<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function guides_testimonials_user_default_permissions() {
  $permissions = array();

  // Exported permission: create testimonial content
  $permissions['create testimonial content'] = array(
    'name' => 'create testimonial content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete own testimonial content
  $permissions['delete own testimonial content'] = array(
    'name' => 'delete own testimonial content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own testimonial content
  $permissions['edit own testimonial content'] = array(
    'name' => 'edit own testimonial content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
