<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function guides_helpers_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'guides_global_layout';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'guide_card-0' => array(
          'module' => 'guide_card',
          'delta' => 0,
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['guides_global_layout'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'guides_main_layout';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'news' => 'news',
        'contact' => 'contact',
        'faq' => 'faq',
        'bookmarks' => 'bookmarks',
        'users/*' => 'users/*',
        'messages' => 'messages',
        'messages/*' => 'messages/*',
        'node/add/guides' => 'node/add/guides',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'geotest-0' => array(
          'module' => 'geotest',
          'delta' => 0,
          'region' => 'right',
          'weight' => 0,
        ),
        'views-testimonials-block_1' => array(
          'module' => 'views',
          'delta' => 'testimonials-block_1',
          'region' => 'right',
          'weight' => 1,
        ),
        'views-guides-block_1' => array(
          'module' => 'views',
          'delta' => 'guides-block_1',
          'region' => 'right',
          'weight' => 2,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['guides_main_layout'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'guides_only_main_layout';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'guides_articles-4' => array(
          'module' => 'guides_articles',
          'delta' => 4,
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['guides_only_main_layout'] = $context;

  return $export;
}
