<?
if(!$page)
{
	echo $content;
	echo '<div class="alignright">'.l('Читать дальше', 'node/'.$node->nid, array("attributes"=>array("class"=>"button"))).'</div>';
	echo '<div style="clear: left"></div>';
}
else
{
	echo "<div class='col-2 guide-preview'><ul class='img-list'>".node_view($node->guide, 1)."</ul></div>";
	echo "<div class='submitted'>Отзыв оставил: ".theme("username", $node).", ".format_date($node->created, "custom", "d/m/Y H:i")."</div>";
	echo $content;
?>

<?
}
?>