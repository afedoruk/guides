<?php
$output='';
if($node->field_place_link[0]["value"])
{
	$output.="<a href='".$node->field_place_link[0]["value"]."'>".$node->field_place_link[0]["value"]."</a>";
}
if($node->field_place_contacts[0]["value"])
{
	$output.="<h4>Контакты:</h4>";
	$output.=$node->field_place_contacts[0]["view"];
}
if($node->field_place_hours[0]["value"])
{
	$output.="<h4>Часы работы:</h4>";
	$output.=$node->field_place_hours[0]["view"];
}
if($node->field_region[0]["value"])
{
	$output.="<h4>Район страны:</h4>";
	$output.= $node->field_region[0]["view"];
}
if($node->field_place_block[0]["value"])
{
	$output.="<h4>Район города:</h4>";
	$output.= $node->field_place_block[0]["view"];
}
if($node->field_place_address[0]["view"])
{
	$output.="<h4>Адрес:</h4>";
	$output.=$node->field_place_address[0]["view"];
}
if($output)
{
?>
<div class='place-detail'>
<?
	echo $output;
?>
</div>
<?
}
?>