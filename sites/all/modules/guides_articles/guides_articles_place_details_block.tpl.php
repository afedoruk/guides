<?php
if($node->field_place_link[0]["value"])
{
	echo "<p><a href='".$node->field_place_link[0]["value"]."'>".$node->field_place_link[0]["value"]."</a></p>";
}
if($node->field_place_contacts[0]["value"])
{
	echo "<h4>Контакты:</h4>";
	echo $node->field_place_contacts[0]["view"];
}
if($node->field_place_hours[0]["value"])
{
	echo "<h4>Часы работы:</h4>";
	echo $node->field_place_hours[0]["view"];
}
if($node->field_region[0]["value"])
{
	echo "<h4>Район:</h4>";
	echo $node->field_region[0]["view"];
}
if($node->field_place_address[0]["view"])
{
	echo "<h4>Адрес:</h4>";
	echo $node->field_place_address[0]["view"];
}