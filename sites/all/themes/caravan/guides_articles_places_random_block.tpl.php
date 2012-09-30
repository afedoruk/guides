<h3 style='clear: both'>Куда поехать?</h3>
<?php 
$i=0;
foreach ($places as $place)
{
	print  ' <div class="col-2"><ul class="img-list">	<li>';
	echo $place->field_place_images[0]["filepath"]?theme("imagecache", "userpic", $place->field_place_images[0]["filepath"]):"";
	echo '<div class="extra-wrap"><p><strong>'.l($place->title, "node/".$place->nid).'</strong></p>';
   foreach($place->field_place_city as $city)
	{
		echo $countries[$city["country_id"]].", ".$city["city_name"]."<br>";
	}
	echo '</div></li></ul></div>';
	$i++;
}
?>

