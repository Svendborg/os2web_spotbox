<?php
/**
 * @file
 * os2web_spotbox.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function os2web_spotbox_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'os2web_spotbox_view_spots';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Spotboxe';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Spotboxe';
  $handler->display->display_options['css_class'] = 'spotbox';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'spotbox';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontekstuelt filter: Indhold: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Kontekstuelt filter: Indhold: Forfrem til (field_os2web_spotbox_promote_to) */
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['id'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['field'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['validate_options']['vocabularies'] = array(
    'os2web_base_tax_promoteto' => 'os2web_base_tax_promoteto',
  );
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['field_os2web_spotbox_promote_to_tid']['break_phrase'] = TRUE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'spotboxe';

  /* Display: Standard */
  $handler = $view->new_display('panel_pane', 'Standard', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Blok til at vise standard spotbokse.';
  $handler->display->display_options['pane_category']['name'] = 'Spotbox';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 'offset';
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:user.picture',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Evt. Spotbox indholds ID\'er. Separer med komma (,)',
    ),
    'field_os2web_spotbox_promote_to_tid' => array(
      'type' => 'user',
      'context' => 'entity:user.picture',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Evt. Spotboxe der er forfremmet til et taksonomi navn.',
    ),
    'null' => array(
      'type' => 'user',
      'context' => 'entity:user.picture',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Global: Null',
    ),
  );
  $translatables['os2web_spotbox_view_spots'] = array(
    t('Master'),
    t('Spotboxe'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Alle'),
    t('Page'),
    t('Standard'),
    t('Blok til at vise standard spotbokse.'),
    t('Spotbox'),
  );
  $export['os2web_spotbox_view_spots'] = $view;

  return $export;
}
