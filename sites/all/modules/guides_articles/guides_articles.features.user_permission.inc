<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function guides_articles_user_default_permissions() {
  $permissions = array();

  // Exported permission: create place content
  $permissions['create place content'] = array(
    'name' => 'create place content',
    'roles' => array(),
  );

  // Exported permission: create story content
  $permissions['create story content'] = array(
    'name' => 'create story content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete any place content
  $permissions['delete any place content'] = array(
    'name' => 'delete any place content',
    'roles' => array(),
  );

  // Exported permission: delete any story content
  $permissions['delete any story content'] = array(
    'name' => 'delete any story content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own place content
  $permissions['delete own place content'] = array(
    'name' => 'delete own place content',
    'roles' => array(),
  );

  // Exported permission: delete own story content
  $permissions['delete own story content'] = array(
    'name' => 'delete own story content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit any place content
  $permissions['edit any place content'] = array(
    'name' => 'edit any place content',
    'roles' => array(),
  );

  // Exported permission: edit any story content
  $permissions['edit any story content'] = array(
    'name' => 'edit any story content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own place content
  $permissions['edit own place content'] = array(
    'name' => 'edit own place content',
    'roles' => array(),
  );

  // Exported permission: edit own story content
  $permissions['edit own story content'] = array(
    'name' => 'edit own story content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  return $permissions;
}
