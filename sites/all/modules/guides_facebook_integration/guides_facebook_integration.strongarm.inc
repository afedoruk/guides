<?php

/**
 * Implementation of hook_strongarm().
 */
function guides_facebook_integration_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_button_text_login';
  $strongarm->value = '';

  $export['fb_button_text_login'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_button_text_login_block';
  $strongarm->value = '';

  $export['fb_button_text_login_block'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_button_text_register';
  $strongarm->value = '';

  $export['fb_button_text_register'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_connect_primary_label';
  $strongarm->value = 'theguides_fb_app';

  $export['fb_connect_primary_label'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_connect_theme_username_1';
  $strongarm->value = 1;

  $export['fb_connect_theme_username_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_connect_theme_username_2';
  $strongarm->value = 1;

  $export['fb_connect_theme_username_2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_connect_theme_userpic_1';
  $strongarm->value = 1;

  $export['fb_connect_theme_userpic_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_connect_theme_userpic_2';
  $strongarm->value = 1;

  $export['fb_connect_theme_userpic_2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_user_alter_contact';
  $strongarm->value = 1;

  $export['fb_user_alter_contact'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_user_alter_login';
  $strongarm->value = 1;

  $export['fb_user_alter_login'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_user_alter_login_block';
  $strongarm->value = 1;

  $export['fb_user_alter_login_block'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_user_alter_register';
  $strongarm->value = 1;

  $export['fb_user_alter_register'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_user_check_session';
  $strongarm->value = 1;

  $export['fb_user_check_session'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_user_username_style';
  $strongarm->value = '1';

  $export['fb_user_username_style'] = $strongarm;
  return $export;
}
