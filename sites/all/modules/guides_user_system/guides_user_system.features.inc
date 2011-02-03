<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function guides_user_system_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function guides_user_system_imagecache_default_presets() {
  $items = array(
    'small' => array(
      'presetname' => 'small',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '16',
            'height' => '16',
          ),
        ),
      ),
    ),
  );
  return $items;
}
