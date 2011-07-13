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
	if(sizeof($node->field_story_images))
	{
		foreach($node->field_story_images as $image)
		{
			echo "<a href='/".$image['filepath']."' rel='lightbox[node-".$node->nid."]'>".theme("imagecache", "gallery_preview", $image["filepath"])."</a>";
		}
	}
	?>
	</div>
  <div class="content">
    <?php print $content; 
	if($node->field_story_link[0]["value"])
	{
		echo "<p><a href='".$node->field_story_link[0]["value"]."'>".$node->field_story_link[0]["value"]."</a></p>";
	}
	if($node->field_story_hours[0]["value"])
	{
		echo "<h4>Часы работы</h4>";
		echo $node->field_story_hours[0]["view"];
	}
	if($node->field_story_address[0]["value"])
	{
		echo "<h4>Адрес</h4>";
		echo $node->field_story_address[0]["view"];
	}	
	?>
  </div>
  <?php print $links; ?>
</div> <!-- /.node -->
<?
}
?>