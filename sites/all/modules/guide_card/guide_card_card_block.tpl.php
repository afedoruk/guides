<?php
if($node)
{
	$output="<div class='my-card'>";
	$output.="<h4>".l("Моя карточка гида", "node/".$node->nid)."</h4>";
	$output.='</div>';
}
else
{
	$output="<div class='created-my-card'>".l("Стать гидом!", "node/add/guide")."</div>";
}

echo $output;