<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function guides_articles_taxonomy_default_vocabularies() {
  return array(
    'tags' => array(
      'name' => 'Теги',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_tags',
      'weight' => '0',
      'nodes' => array(
        'place' => 'place',
        'story' => 'story',
      ),
    ),
  );
}
