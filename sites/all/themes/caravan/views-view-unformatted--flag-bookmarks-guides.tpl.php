<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php 
$i=0;
foreach ($rows as $id => $row): ?>
  <?php print  ' <div class="col-'.($i%2+1).'"><ul class="img-list">'.$row.'</ul></div>'; $i++?>
<?php endforeach; ?>