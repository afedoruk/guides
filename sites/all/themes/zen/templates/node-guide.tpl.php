<?php
if($page)
{
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
    <li><a href="#jquery-super-simple-tabs-example-2">О себе</a></li>
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
<div id="jquery-super-simple-tabs-example-2">
<?=$content?>
</div>
<div id="jquery-super-simple-tabs-example-3">
    Content 3
</div>
</div>
</td></tr></table>


  <?php print $links; ?>
</div> <!-- /.node -->
<?
}
else
{
	?>
	<table><tr><td style='width: 80px'><?=$node->field_photo[0]["filepath"]?theme("imagecache", "userpic", $node->field_photo[0]["filepath"]):""?></td><td><?=l($node->title, "node/".$node->nid)?></td></tr></table>
	<?
}