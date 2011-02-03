<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function guides_private_messages_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete privatemsg
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(),
  );

  // Exported permission: read privatemsg
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: write privatemsg
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
