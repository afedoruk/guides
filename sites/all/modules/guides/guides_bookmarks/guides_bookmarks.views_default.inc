<?php

/**
 * Implementation of hook_views_default_views().
 */
function guides_bookmarks_views_default_views() {
  $views = array();

  // Exported view: flag_bookmarks_guides
  $view = new view;
  $view->name = 'flag_bookmarks_guides';
  $view->description = 'A page listing the current user\'s bookmarks at /bookmarks.';
  $view->tag = 'flag';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'flag_content_rel' => array(
      'label' => 'bookmarks',
      'required' => 1,
      'flag' => 'bookmarks',
      'user_scope' => 'current',
      'id' => 'flag_content_rel',
      'table' => 'node',
      'field' => 'flag_content_rel',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('fields', array(
    'type' => array(
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'label' => 'Type',
    ),
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'label' => 'Title',
      'link_to_node' => 1,
    ),
    'name' => array(
      'label' => 'Author',
      'link_to_user' => 1,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
    ),
    'comment_count' => array(
      'id' => 'comment_count',
      'table' => 'node_comment_statistics',
      'field' => 'comment_count',
      'label' => 'Replies',
    ),
    'last_comment_timestamp' => array(
      'id' => 'last_comment_timestamp',
      'table' => 'node_comment_statistics',
      'field' => 'last_comment_timestamp',
      'label' => 'Last Post',
    ),
    'ops' => array(
      'label' => 'Ops',
      'id' => 'ops',
      'table' => 'flag_content',
      'field' => 'ops',
      'relationship' => 'flag_content_rel',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      2 => '2',
    ),
    'perm' => '',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Избранные гиды');
  $handler->override_option('empty', 'You have not yet bookmarked any content. Click the "Запомнить" link when viewing a piece of content to add it to this list.');
  $handler->override_option('items_per_page', '25');
  $handler->override_option('use_pager', TRUE);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 1,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->override_option('path', 'bookmarks/guides');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => 'My bookmarks',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => NULL,
    'description' => '',
    'weight' => NULL,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  // Exported view: flag_bookmarks_places
  $view = new view;
  $view->name = 'flag_bookmarks_places';
  $view->description = 'A page listing the current user\'s places at /bookmarks.';
  $view->tag = 'flag';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'flag_content_rel' => array(
      'label' => 'bookmarks',
      'required' => 1,
      'flag' => 'bookmarks_places',
      'user_scope' => 'current',
      'id' => 'flag_content_rel',
      'table' => 'node',
      'field' => 'flag_content_rel',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('fields', array(
    'type' => array(
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'label' => 'Type',
    ),
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'label' => 'Title',
      'link_to_node' => 1,
    ),
    'name' => array(
      'label' => 'Author',
      'link_to_user' => 1,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
    ),
    'comment_count' => array(
      'id' => 'comment_count',
      'table' => 'node_comment_statistics',
      'field' => 'comment_count',
      'label' => 'Replies',
    ),
    'last_comment_timestamp' => array(
      'id' => 'last_comment_timestamp',
      'table' => 'node_comment_statistics',
      'field' => 'last_comment_timestamp',
      'label' => 'Last Post',
    ),
    'ops' => array(
      'label' => 'Ops',
      'id' => 'ops',
      'table' => 'flag_content',
      'field' => 'ops',
      'relationship' => 'flag_content_rel',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      2 => '2',
    ),
    'perm' => '',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'My bookmarks');
  $handler->override_option('empty', 'You have not yet bookmarked any content. Click the "Запомнить" link when viewing a piece of content to add it to this list.');
  $handler->override_option('items_per_page', '25');
  $handler->override_option('use_pager', TRUE);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 1,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->override_option('path', 'bookmarks/places');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => 'My bookmarks',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => NULL,
    'description' => '',
    'weight' => NULL,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  return $views;
}
