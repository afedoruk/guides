<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function guides_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Карточка гида';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'guide_card_block';
  $fe_block_boxes->body = '<?php
if(function_exists("guides_helpers_get_card"))
{
if($nid=guides_helpers_get_card())
{
$guide=node_load($nid);
echo "<div class=\'my-card\'>";
echo "<h4>Моя карточка гида</h4>";
echo \'<ul class="img-list">\';
echo node_view($guide, 1);
echo \'</ul></div>\';
}
else
{
echo "<div class=\'created-my-card\'>".l("Стань гидом!", "node/add/guide")."</div>";
}
}
?>';

  $export['guide_card_block'] = $fe_block_boxes;

  return $export;
}
