<?
if(!$page)
{
	echo $content;
	echo '<div class="alignright">'.l('Читать дальше', 'node/'.$node->nid, array("attributes"=>array("class"=>"button"))).'</div>';
}
else
{
	echo "<div class='col-2 guide-preview'><ul class='img-list'>".node_view($node->guide, 1)."</ul></div>";
	echo $content;
?>

<?
}
?>