<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function guides_bookmarks_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function guides_bookmarks_flag_default_flags() {
  $flags = array();
  // Exported flag: "Записная книжка".
  $flags['bookmarks'] = array(
    'content_type' => 'node',
    'title' => 'Записная книжка',
    'global' => '0',
    'types' => array(
      '0' => 'guide',
    ),
    'flag_short' => 'Запомнить',
    'flag_long' => 'Добавить гида в свою записную книжку',
    'flag_message' => 'Теперь вы можете всегда найти этого гида в своей записной книжке',
    'unflag_short' => 'Забыть',
    'unflag_long' => 'Убрать гида из записной книжки',
    'unflag_message' => 'Этот гид был удален из вашей записной книжки',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        '0' => '2',
      ),
      'unflag' => array(
        '0' => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'guides_bookmarks',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Избранные места".
  $flags['bookmarks_places'] = array(
    'content_type' => 'node',
    'title' => 'Избранные места',
    'global' => '0',
    'types' => array(
      '0' => 'place',
    ),
    'flag_short' => 'Запомнить',
    'flag_long' => 'Добавить место в свою записную книжку',
    'flag_message' => 'Теперь вы можете всегда найти это место в своей записной книжке',
    'unflag_short' => 'Забыть',
    'unflag_long' => 'Убрать место из записной книжки',
    'unflag_message' => 'Это место был удален из вашей записной книжки',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        '0' => '2',
      ),
      'unflag' => array(
        '0' => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => '0',
    'module' => 'guides_bookmarks',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_views_api().
 */
function guides_bookmarks_views_api() {
  return array(
    'api' => '2',
  );
}
