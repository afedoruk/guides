<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function guides_facebook_integration_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer fb apps
  $permissions['administer fb apps'] = array(
    'name' => 'administer fb apps',
    'roles' => array(),
  );

  // Exported permission: delete own fb_user authmap
  $permissions['delete own fb_user authmap'] = array(
    'name' => 'delete own fb_user authmap',
    'roles' => array(),
  );

  return $permissions;
}
