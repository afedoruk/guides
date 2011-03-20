<?php

/**
 * Implementation of hook_strongarm().
 */
function guide_workflow_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'inline_registration_guide';
  $strongarm->value = 1;

  $export['inline_registration_guide'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'inline_registration_weight_guide';
  $strongarm->value = '-10';

  $export['inline_registration_weight_guide'] = $strongarm;
  return $export;
}
