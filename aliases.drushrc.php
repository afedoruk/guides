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
  'uri' => 'http://theguides.ru/',
  'db-url' => 'mysql://guide:roxgZaaF6TnzB4RpKI3c@localhost/guides',
  'remote-host' => '178.79.152.226',
  'remote-user' => 'root',
  'root' => '/var/www/theguides.ru/public_html/sites/theguides.ru',
);
?>