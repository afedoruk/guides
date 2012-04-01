<h3>Интересные места <?php print $country['in'] ?></h3>
<?php
$countries=geotest_country_list();
foreach($places as $place)
{
	?>
	<div class="col-2"><ul class="img-list">
	<li>
	   <?=$place->field_place_images[0]["filepath"]?theme("imagecache", "userpic", $place->field_place_images[0]["filepath"]):""?>
	   <div class="extra-wrap">
		  <p><strong><?=l($place->title, "node/".$place->nid)?></strong></p>	
		  <?
		   foreach($place->field_place_city as $city)
			{
				echo $countries[$city["country_id"]].", ".$city["city_name"]."<br>";
			}
			if($place->field_place_address[0]['value'])
			{
				echo $place->field_place_address[0]['value'];
			}
			echo theme("item_list", $s);
			?>
	   </div>
	</li>
	</ul></div>
	<?php
}
//echo l("Другие гиды ".$country['in'], "countries/".$country['id']);