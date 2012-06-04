<?php
echo "<h3>Еще по этой теме</h3><ul>";
foreach($node->field_related_topics as $link)
{
	echo "<li>".$link['view']."</li>";
}
echo "</ul>";
