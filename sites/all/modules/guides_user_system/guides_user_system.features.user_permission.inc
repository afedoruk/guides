<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function guides_user_system_user_default_permissions() {
  $permissions = array();

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: add twitter accounts
  $permissions['add twitter accounts'] = array(
    'name' => 'add twitter accounts',
    'roles' => array(),
  );

  return $permissions;
}
