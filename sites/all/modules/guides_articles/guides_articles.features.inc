<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function guides_articles_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function guides_articles_imagecache_default_presets() {
  $items = array(
    'gallery_preview' => array(
      'presetname' => 'gallery_preview',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function guides_articles_node_info() {
  $items = array(
    'place' => array(
      'name' => t('Место'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название '),
      'has_body' => '1',
      'body_label' => t('Описание'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'story' => array(
      'name' => t('Статья'),
      'module' => 'features',
      'description' => t('A <em>story</em>, similar in form to a <em>page</em>, is ideal for creating and displaying content that informs or engages website visitors. Press releases, site announcements, and informal blog-like entries may all be created with a <em>story</em> entry. By default, a <em>story</em> entry is automatically featured on the site\'s initial home page, and provides the ability to post comments.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function guides_articles_views_api() {
  return array(
    'api' => '2',
  );
}
