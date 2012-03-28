<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function guide_card_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:guides
  $menu_links['primary-links:guides'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'guides',
    'router_path' => 'guides',
    'link_title' => 'Гиды',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Гиды');


  return $menu_links;
}
