<?php

/**
 * Implementation of hook_user_default_roles().
 */
function guides_helper_modules_user_default_roles() {
  $roles = array();

  // Exported role: anonymous user
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
  );

  // Exported role: superadmin
  $roles['superadmin'] = array(
    'name' => 'superadmin',
  );

  return $roles;
}
