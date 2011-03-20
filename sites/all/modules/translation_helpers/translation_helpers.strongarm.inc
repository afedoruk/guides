<?php

/**
 * Implementation of hook_strongarm().
 */
function translation_helpers_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_count';
  $strongarm->value = 1;

  $export['language_count'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_default';
  $strongarm->value = (object) array(
  'language' => 'ru',
  'name' => 'Russian',
  'native' => 'Русский',
  'direction' => '0',
  'enabled' => '1',
  'plurals' => '3',
  'formula' => '(((($n%10)==1)&&(($n%100)!=11))?(0):((((($n%10)>=2)&&(($n%10)<=4))&&((($n%100)<10)||(($n%100)>=20)))?(1):2))',
  'domain' => '',
  'prefix' => 'ru',
  'weight' => '0',
  'javascript' => 'c18e9b3481ab2614ae1f319e1591fb78',
);

  $export['language_default'] = $strongarm;
  return $export;
}
