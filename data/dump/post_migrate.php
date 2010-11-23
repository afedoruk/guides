<?php
include_once './post_migrate.inc';
chdir('../..');
include_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
restore_error_handler();

post_migrate_variable_set(array(
  'cache' => 1,
  'block_cache' => 1,
  'preprocess_css' => 1,
  'preprocess_js' => 1,
));

post_migrate_unset_permissions(array('access devel information'));

module_disable(array('sass_api'));