<h3>Гиды <?php print $country['in'] ?></h3>
<?php
foreach($guides as $guide)
{
	echo '<div class="col-2"><ul class="img-list">';
	echo node_view($guide, 1);
	echo '</ul></div>';
}
echo l("Другие гиды ".$country['in'], "countries/".$country['id']);