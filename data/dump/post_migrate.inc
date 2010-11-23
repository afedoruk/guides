<?php
function post_migrate_variable_set($variables) {
  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}

function post_migrate_unset_permissions($permissions) {
  $result = db_query("SELECT * FROM {permission}");
  while ($row = db_fetch_object($result)) {
    $perm = array_fill_keys(explode(', ', $row->perm), TRUE);
    foreach ($permissions as $name) {
      unset($perm[$name]);
    }
    $row->perm = implode(', ', array_keys($perm));
    drupal_write_record('permission', $row, array('rid'));
  }
}