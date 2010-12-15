<?php
$countries=geotest_country_list();
if($page)
{
	echo "<h4>".$countries[$node->field_city[0]["country_id"]].", ".$node->field_city[0]["city_name"]."</h4>";
?>
<script type="text/javascript">
$(document).ready(function() {
	jQuery('#guide-tabs ul').superSimpleTabs();	
});
</script>
<table>
<tr>
<td style='vertical-align: top'>
<?=$node->field_photo[0]["filepath"]?theme("imagecache", "guide_face", $node->field_photo[0]["filepath"]):"";?>
</td>
<td style='vertical-align: top'>

<div id="guide-tabs">
<ul class='jtabs'>
    <li><a href="#jquery-super-simple-tabs-example-1">Главное</a></li>
	<?
	if($content)
	{
	?>
    <li><a href="#jquery-super-simple-tabs-example-2">О себе</a></li>
	<?
	}
	?>
    <li><a href="#jquery-super-simple-tabs-example-3">Отзывы</a></li>
</ul>
<div class='clear-block'></div>
<div id="jquery-super-simple-tabs-example-1">
<h4>Услуги</h4>
<?
	foreach($node->taxonomy as $term)
	{
		$s[]=$term->name;
	}
	echo theme("item_list", $s);
	if($node->field_addinfo[0]["value"])
	{
		echo "<h4>Дополнительная информация</h4>";
		echo $node->field_addinfo[0]["view"];
	}
	echo "<h4>Контакты</h4>";
	if($node->field_phone[0]["value"])
	{
		echo "Телефон: ".$node->field_phone[0]["view"];
	}
	if($node->field_mail[0]["value"])
	{
		echo "Почта: ".$node->field_mail[0]["view"];
	}
	if($node->field_skype[0]["value"])
	{
		echo "Skype: ".$node->field_skype[0]["view"];
	}
?>
</div>
<?
if($content)
{
?>
	<div id="jquery-super-simple-tabs-example-2">
	<?=$content?>
	</div>
	<?
}
?>
<div id="jquery-super-simple-tabs-example-3">
<?
//$view = views_get_view('sample_view');
//output the view
print views_embed_view('testimonials', 'page_1', $node->nid);
?>
</div>
</div>
</td></tr></table>


  <?php print $links; ?>
 <!-- /.node -->
<?
}
else
{
	?>
	<li>
	   <?=$node->field_photo[0]["filepath"]?theme("imagecache", "userpic", $node->field_photo[0]["filepath"]):""?>
	   <div class="extra-wrap">
		  <p><strong><?=l($node->title, "node/".$node->nid)?></strong></p>	
		  <?
		  echo $countries[$node->field_city[0]["country_id"]].", ".$node->field_city[0]["city_name"]."<br>";
			foreach($node->taxonomy as $term)
			{
				$s[]=$term->name;
			}
			echo theme("item_list", $s);
			?>
	   </div>
	</li>
	<?
}