<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function geotest_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'quides_country_layout';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'countries/*' => 'countries/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'guides_articles-2' => array(
          'module' => 'guides_articles',
          'delta' => 2,
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['quides_country_layout'] = $context;

  return $export;
}
