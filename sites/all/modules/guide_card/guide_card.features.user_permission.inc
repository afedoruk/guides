<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function guide_card_user_default_permissions() {
  $permissions = array();

  // Exported permission: create guide content
  $permissions['create guide content'] = array(
    'name' => 'create guide content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any guide content
  $permissions['delete any guide content'] = array(
    'name' => 'delete any guide content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own guide content
  $permissions['delete own guide content'] = array(
    'name' => 'delete own guide content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit any guide content
  $permissions['edit any guide content'] = array(
    'name' => 'edit any guide content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own guide content
  $permissions['edit own guide content'] = array(
    'name' => 'edit own guide content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
