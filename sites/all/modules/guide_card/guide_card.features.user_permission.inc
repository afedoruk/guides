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

  return $permissions;
}
