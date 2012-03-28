<?
if(!$page)
{
	?>
	<dt>
	   <a href="<?php print $node_url; ?>"><?php print $title; ?></a><br />
	</dt>
	<dd>
		<?=$content?>
	</dd>
<?
}
else
{
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix">
	<div class='gallery'>
	<?php
	if(sizeof($node->field_place_images) && $node->field_place_images[0]['filepath'])
	{
		foreach($node->field_place_images as $image)
		{
			echo "<a href='/".$image['filepath']."' rel='lightbox[node-".$node->nid."]'>".theme("imagecache", "gallery_preview", $image["filepath"])."</a>";
		}
	}
	?>
	</div>
  <div class="content">
    <?php print $content; 	
	if($node->field_place_address[0]["value"])
	{
		if($node->point && !$node->field_map[0]["view"])
		{
			echo "<div id='gmap' style='height: 500px; width: 610px;'></div>";
			$script='$(document).ready(function() {
				var latlng = new google.maps.LatLng('.$node->point[1].', '.$node->point[0].');
				var myOptions = {
				  zoom: 15,
				  center: latlng,
				  mapTypeId: google.maps.MapTypeId.ROADMAP
				};
				var marker = new google.maps.Marker({
					  position: latlng,
					  title:"'.$node->title.'"
				  });

				var map = new google.maps.Map(document.getElementById("gmap"),
					myOptions);

				var infowindow = new google.maps.InfoWindow({
				    content: "<h1>'.$node->title.'</h1>'.$node->field_place_address[0]["view"].'"
				});
				google.maps.event.addListener(marker, "click", function() {
				  infowindow.open(map,marker);
				});
				 marker.setMap(map);  
			});';
			drupal_add_js($script, "inline");
		}
	}
	if($node->field_map[0]["view"])
	{
		echo "<p>".$node->field_map[0]["value"]."</p>";
	}
	?>
  </div>
  <?php print $links; ?>
</div> <!-- /.node -->
<?
}
?>