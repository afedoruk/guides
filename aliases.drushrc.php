<?php
$aliases['dev'] = array(
  'uri' => 'http://guides.local/',
  'db-url' => 'mysql://bang:makondo1979@localhost/guides',
);

$aliases['devhudson'] = array(
  'uri' => 'http://guides.hudson.local/',
  'db-url' => 'mysql://bang:makondo1979@localhost/guides_hudson',
);
  
$aliases['prod'] = array(
  'uri' => 'http://deploy-prod.openconsole.ru/',
  'db-url' => 'mysqli://deploypr_deploy:makelove@localhost/deploypr_deploypr',
  'remote-host' => '174.121.78.170',
  'remote-user' => 'deploypr',
  'root' => '~/www',
);
?>