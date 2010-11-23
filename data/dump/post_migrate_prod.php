<?php
include_once './post_migrate.inc';
chdir('../..');
include_once './includes/bootstrap.inc';
include_once './aliases.drushrc.php';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
restore_error_handler();

post_migrate_variable_set(array(
  'site_mail' => 'noreply@' . parse_url($aliases['prod']['uri'], PHP_URL_HOST),
));

post_migrate_unset_permissions(array('Access Firebug Debug', 'Execute Firebug PHP'));

module_disable(array('devel', 'reroute_email'));