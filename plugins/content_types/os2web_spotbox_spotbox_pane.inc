<?php
/**
 * @file os2web_spotbox_spotbox_pane.inc
 */

$plugin = array(
  'single'          => TRUE,
  'title'           => t('Spotbox pane'),
  'description'     => t('Spotbox panes lets you display spotboxes.'),
  'category'        => array('Spotbox'),
  'edit form'       => 'os2web_spotbox_spotbox_pane_edit_form', // A function that will return the settings form for the pane.
  'render callback' => 'os2web_spotbox_spotbox_pane_render', // A function that will return the renderable content.
  'all contexts'    => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
  'defaults'        => array(
    'spotbox_nids' => '',
    'spotbox_type' => '',
    'spotbox_count' => '10',
    'spotbox_offset' => '0',
    'spotbox_sitestruct' => '',
  ),
);

/**
 * An edit form for the pane's settings.
 */
function os2web_spotbox_spotbox_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];


  $form['spotbox_nids'] = array(
    '#type' => 'textfield',
    '#title' => t("Evt. Id'er af spotboxe som du vil have vist."),
    '#description' => t("Seperér flere ID'er med komma fx. 1212,1313,2121. Hvis ingen er valgt vises nyeste spotboxe."),
    '#default_value' => $conf['spotbox_nids'],
  );

  // Get all types of image styles for the spotbox image.
  $crops = field_info_instance('node', 'field_os2web_spotbox_big_image', 'os2web_spotbox_box');

  $form['spotbox_type'] = array(
    '#prefix' => '<div class="no-float">',
    '#title' => t('Vælg hvilken spotbox type du vil bruge.'),
    '#type' => 'select',
    '#options' => $crops['settings']['epsacrop']['styles'],
    '#default_value' => $conf['spotbox_type'],
    '#weight' => -10,
    '#suffix' => '</div>',
  );

  $form['spotbox_count'] = array(
    '#prefix' => '<div class="no-float">',
    '#title' => t('Antal elementer'),
    '#description' => t('Vælg hvor mange spotboxe du vil vise. Bruges kun hvis du ikke har specificeret IDer.'),
    '#type' => 'textfield',
    '#default_value' => $conf['spotbox_count'],
    '#weight' => -9,
    '#suffix' => '</div>',
  );

  $form['spotbox_offset'] = array(
    '#prefix' => '<div class="no-float">',
    '#title' => t('Forskydning.'),
    '#description' => t('Brug denne i sammenhæng med "Antal elementer".'),
    '#type' => 'textfield',
    '#default_value' => $conf['spotbox_offset'],
    '#weight' => -8,
    '#suffix' => '</div>',
  );

  $form['spotbox_sitestruct'] = array(
    '#prefix' => '<div class="no-float">',
    '#title' => t('Placering i site struktur (Portalkategori)'),
    '#type' => 'textfield',
    '#autocomplete_path' => 'taxonomy/autocomplete/field_os2web_spotbox_sitestruct',
    '#default_value' => $conf['spotbox_sitestruct'],
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function os2web_spotbox_spotbox_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function os2web_spotbox_spotbox_pane_render($subtype, $conf, $args, $contexts) {

  $nids = $conf['spotbox_nids'];
  $count = $conf['spotbox_count'];
  $offset = $conf['spotbox_offset'];
  $sitestruct = $conf['spotbox_sitestruct'];
  $spotbox_type = $conf['spotbox_type'];

  // Update the strings to allow contexts.
  if (!empty($contexts)) {
    $nids       = ctools_context_keyword_substitute($conf['spotbox_nids'], array(), $contexts);
    $count      = ctools_context_keyword_substitute($conf['spotbox_count'], array(), $contexts);
    $offset     = ctools_context_keyword_substitute($conf['spotbox_offset'], array(), $contexts);
    $sitestruct = ctools_context_keyword_substitute($conf['spotbox_sitestruct'], array(), $contexts);
  }

  // Get all spotboxes to show.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'os2web_spotbox_box')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC');

  // If specific nids are spcified, query for them.
  if (!empty($nids)) {
    $nids = explode(',', $nids);
    $query->entityCondition('entity_id', $nids, 'IN');
  }
  elseif (!empty($count)) {
    // If not specific, query for latest spotboxes.
    $offset = isset($offset) ? (int) $offset : NULL;
    $count = isset($count) ? (int) $count : 100;
    $query->range($offset, $count);
  }

  if (!empty($sitestruct)) {
    $term = taxonomy_get_term_by_name($sitestruct, 'os2web_base_tax_site_structure');
    $term = array_shift($term);
    $query->fieldCondition('field_os2web_spotbox_sitestruct', 'tid', $term->tid, '=');
  }

  $result = $query->execute();
  $spotboxes = array();
  if (isset($result['node'])) {
    $spotbox_nids = array_keys($result['node']);
    $spotboxes = entity_load('node', $spotbox_nids);
  }

  $render_array = entity_view('node', $spotboxes, 'spotbox');

  foreach ($render_array['node'] as $key => &$rendered_spotbox) {
    // If a specific image style is set the formatter.
    if (!empty($spotbox_type) && isset($rendered_spotbox['field_os2web_spotbox_big_image'][0]['#image_style'])) {
      $rendered_spotbox['field_os2web_spotbox_big_image'][0]['#image_style'] = $spotbox_type;
    }

    // Add the spotbox url as an variable to the node. This is used in the
    // template file.
    if (isset($rendered_spotbox['field_os2web_spotbox_url']['#items'][0]['value'])) {
      $rendered_spotbox['#spotbox_url'] = $rendered_spotbox['field_os2web_spotbox_url']['#items'][0]['value'];
    }
  }

  $block = new stdClass();

  // Initial content is blank.
  $block->title = t('Spotboxe');
  $block->content = drupal_render($render_array);

  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function os2web_spotbox_spotbox_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $conf['text'];
    return $block;
  }
}
