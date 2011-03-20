<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function guide_card_taxonomy_default_vocabularies() {
  return array(
    'guide_services' => array(
      'name' => 'Услуги',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '1',
      'required' => '1',
      'tags' => '0',
      'module' => 'features_guide_services',
      'weight' => '0',
      'nodes' => array(
        'guide' => 'guide',
      ),
    ),
  );
}
