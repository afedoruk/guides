<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function guides_private_messages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
