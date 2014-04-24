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
  $view->name = 'os2web_spotbox_view_spot';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'SpotBox view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'spotbox-indhold';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Forbindelse: Felt: Spotboxe (field_os2web_base_field_spotbox) */
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['id'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['table'] = 'field_data_field_os2web_base_field_spotbox';
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['field'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['delta'] = '-1';
  /* Felt: Indhold: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<img src="[field_os2web_spotbox_lead_image]" alt="[title]" />
<span class="zoom-icon"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_os2web_spotbox_lead_image]<br />
[title]';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<div class="spotImage">[field_os2web_spotbox_lead_image]</div>
<div class="spotTitle">[title]</div>

';
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Felt: Indhold: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Felt: Indhold: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontekstuelt filter: Indhold: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox-2-vertical';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Redigér-link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Felt: Global: Kontekstuelle links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'body' => 0,
    'field_os2web_spotbox_lead_image' => 0,
    'title' => 0,
    'title_1' => 0,
    'field_os2web_spotbox_url' => 0,
  );
  /* Felt: Indhold: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Felt: Indhold: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<img src="[field_os2web_spotbox_lead_image]" alt="[title]" />
<span class="zoom-icon"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_os2web_spotbox_lead_image]<br />
[title]';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<div class="spotImage">[field_os2web_spotbox_lead_image]</div>
<div class="spotTitle">[title]</div>

';
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Felt: Indhold: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;

  /* Display: Spotbox */
  $handler = $view->new_display('block', 'Spotbox', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Felt: Indhold: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['alter']['text'] = '[field_os2web_spotbox_url] ';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['type'] = 'text_plain';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_os2web_spotbox_lead_image]<br />
[title]';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Felt: Indhold: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'slideshow';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<h3><a href=[field_os2web_spotbox_url]>[title]';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Felt: Indhold: Redigér-link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Felt: Global: Kontekstuelle links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'body' => 0,
    'field_os2web_spotbox_url' => 0,
    'field_os2web_spotbox_lead_image' => 0,
    'title' => 0,
    'title_1' => 0,
  );
  $translatables['os2web_spotbox_view_spot'] = array(
    t('Master'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('field_os2web_base_field_spotbox'),
    t('<img src="[field_os2web_spotbox_lead_image]" alt="[title]" />
<span class="zoom-icon"></span>'),
    t('[field_os2web_spotbox_lead_image]<br />
[title]'),
    t('<div class="spotImage">[field_os2web_spotbox_lead_image]</div>
<div class="spotTitle">[title]</div>

'),
    t('Indhold'),
    t('Alle'),
    t('Content pane'),
    t('<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>'),
    t('View panes'),
    t('Spotbox'),
    t('[field_os2web_spotbox_url] '),
    t('[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span>'),
    t('<h3><a href=[field_os2web_spotbox_url]>[title]'),
    t('Redigér-link'),
  );
  $export['os2web_spotbox_view_spot'] = $view;

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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'spotboks';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $translatables['os2web_spotbox_view_spots'] = array(
    t('Master'),
    t('Spotboxe'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Page'),
  );
  $export['os2web_spotbox_view_spots'] = $view;

  return $export;
}
