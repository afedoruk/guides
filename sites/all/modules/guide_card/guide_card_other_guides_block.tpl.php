<?php
foreach($guides as $ci=>$cguides)
{
	echo "<h3>Другие гиды ".geotest_get_in_country($ci)."</h3>";
	$i=0;
	foreach ($cguides as $guide)
	{
		print  ' <div class="col-'.($i%3+1).'"><ul class="img-list">'.node_view($guide, 1).'</ul></div>'; 
		$i++;
	}
}