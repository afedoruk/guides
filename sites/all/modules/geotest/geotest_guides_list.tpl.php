<?php 
$i=0;
foreach ($guides as $guide): ?>
  <?php print  ' <div class="col-'.($i%2+1).'"><ul class="img-list">'.node_view($guide, 1).'</ul></div>'; $i++?>
<?php endforeach; ?>