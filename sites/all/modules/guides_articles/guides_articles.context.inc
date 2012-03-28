<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function guides_articles_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'guides_place_layout';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'place' => 'place',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'guides_articles-0' => array(
          'module' => 'guides_articles',
          'delta' => 0,
          'region' => 'right',
          'weight' => 0,
        ),
        'guides_articles-1' => array(
          'module' => 'guides_articles',
          'delta' => 1,
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['guides_place_layout'] = $context;

  return $export;
}
