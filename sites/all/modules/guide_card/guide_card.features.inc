<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function guide_card_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function guide_card_imagecache_default_presets() {
  $items = array(
    'guide_face' => array(
      'presetname' => 'guide_face',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '300',
            'height' => '300',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'userpic' => array(
      'presetname' => 'userpic',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '62',
            'height' => '62',
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
function guide_card_node_info() {
  $items = array(
    'guide' => array(
      'name' => t('Карточка гида'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Имя'),
      'has_body' => '1',
      'body_label' => t('О себе'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function guide_card_views_api() {
  return array(
    'api' => '2',
  );
}
