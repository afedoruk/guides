<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function guides_blocks_default_fe_block_settings() {
  $export = array();

  // caravan
  $theme = array();

  $theme['block-guide_card_block'] = array(
    'module' => 'block',
    'theme' => 'caravan',
    'status' => '1',
    'weight' => '-15',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'guide_card_block',
  );

  $theme['custom_links-0'] = array(
    'module' => 'custom_links',
    'delta' => '0',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-4',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['geotest-0'] = array(
    'module' => 'geotest',
    'delta' => '0',
    'theme' => 'caravan',
    'status' => '1',
    'weight' => '-14',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '',
    'title' => '',
    'cache' => '8',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-10',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-secondary-links'] = array(
    'module' => 'menu',
    'delta' => 'secondary-links',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-7',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['privatemsg-privatemsg-menu'] = array(
    'module' => 'privatemsg',
    'delta' => 'privatemsg-menu',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-9',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['privatemsg-privatemsg-new'] = array(
    'module' => 'privatemsg',
    'delta' => 'privatemsg-new',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-11',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['search-0'] = array(
    'module' => 'search',
    'delta' => '0',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-5',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['twitter_signin-0'] = array(
    'module' => 'twitter_signin',
    'delta' => '0',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-6',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views--exp-guides_search-block_1'] = array(
    'module' => 'views',
    'delta' => '-exp-guides_search-block_1',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-12',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'guides
guides/*',
    'title' => '',
    'cache' => '1',
  );

  $theme['views--exp-guides_search-default'] = array(
    'module' => 'views',
    'delta' => '-exp-guides_search-default',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-1',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views--exp-guides_search-page_1'] = array(
    'module' => 'views',
    'delta' => '-exp-guides_search-page_1',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-guides-block_1'] = array(
    'module' => 'views',
    'delta' => 'guides-block_1',
    'theme' => 'caravan',
    'status' => '1',
    'weight' => '-11',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-guides-block_2'] = array(
    'module' => 'views',
    'delta' => 'guides-block_2',
    'theme' => 'caravan',
    'status' => '1',
    'weight' => '-12',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-guides_search-block_1'] = array(
    'module' => 'views',
    'delta' => 'guides_search-block_1',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '-15',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-news-block_1'] = array(
    'module' => 'views',
    'delta' => 'news-block_1',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '2',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-testimonials-block_1'] = array(
    'module' => 'views',
    'delta' => 'testimonials-block_1',
    'theme' => 'caravan',
    'status' => '1',
    'weight' => '-13',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-tweets-block'] = array(
    'module' => 'views',
    'delta' => 'tweets-block',
    'theme' => 'caravan',
    'status' => 0,
    'weight' => '4',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $export['caravan'] = $theme;

  // garland
  $theme = array();

  $theme['block-guide_card_block'] = array(
    'module' => 'block',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'guide_card_block',
  );

  $theme['custom_links-0'] = array(
    'module' => 'custom_links',
    'delta' => '0',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['geotest-0'] = array(
    'module' => 'geotest',
    'delta' => '0',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '8',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-secondary-links'] = array(
    'module' => 'menu',
    'delta' => 'secondary-links',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['privatemsg-privatemsg-menu'] = array(
    'module' => 'privatemsg',
    'delta' => 'privatemsg-menu',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['privatemsg-privatemsg-new'] = array(
    'module' => 'privatemsg',
    'delta' => 'privatemsg-new',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['search-0'] = array(
    'module' => 'search',
    'delta' => '0',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['twitter_signin-0'] = array(
    'module' => 'twitter_signin',
    'delta' => '0',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views--exp-guides_search-block_1'] = array(
    'module' => 'views',
    'delta' => '-exp-guides_search-block_1',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views--exp-guides_search-default'] = array(
    'module' => 'views',
    'delta' => '-exp-guides_search-default',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views--exp-guides_search-page_1'] = array(
    'module' => 'views',
    'delta' => '-exp-guides_search-page_1',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-guides-block_1'] = array(
    'module' => 'views',
    'delta' => 'guides-block_1',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-guides-block_2'] = array(
    'module' => 'views',
    'delta' => 'guides-block_2',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-guides_search-block_1'] = array(
    'module' => 'views',
    'delta' => 'guides_search-block_1',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-news-block_1'] = array(
    'module' => 'views',
    'delta' => 'news-block_1',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-testimonials-block_1'] = array(
    'module' => 'views',
    'delta' => 'testimonials-block_1',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-tweets-block'] = array(
    'module' => 'views',
    'delta' => 'tweets-block',
    'theme' => 'garland',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $export['garland'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
