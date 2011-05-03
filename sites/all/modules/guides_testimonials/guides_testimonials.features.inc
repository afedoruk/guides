<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function guides_testimonials_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function guides_testimonials_node_info() {
  $items = array(
    'testimonial' => array(
      'name' => t('Отзыв'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Подпись'),
      'has_body' => '1',
      'body_label' => t('Ваши впечатления от работы с этим гидом'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function guides_testimonials_views_api() {
  return array(
    'api' => '2',
  );
}
