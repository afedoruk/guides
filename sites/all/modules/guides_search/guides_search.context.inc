<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function guides_search_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'guide_search_blocks';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'guides' => 'guides',
        'guides:page_1' => 'guides:page_1',
        'guides_search' => 'guides_search',
        'guides_search:page_1' => 'guides_search:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-guides_search-block_1' => array(
          'module' => 'views',
          'delta' => '-exp-guides_search-block_1',
          'region' => 'highlight',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['guide_search_blocks'] = $context;
  return $export;
}
