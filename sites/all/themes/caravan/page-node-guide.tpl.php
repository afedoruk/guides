<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
    <?php print $head ?>
    <title><?php print $head_title ?></title>
    <?php print $styles ?>
    <?php print $scripts ?>

<!--[if lt IE 7]>
	<link href="/<?=path_to_theme()?>/css/ie_style.css" rel="stylesheet" type="text/css" />
<![endif]-->
</head>

<body id="page2">
   <div class="tail-bottom">
      <div id="main">
	    <?
	  global $user;
	  if(!$user->uid)
	  {   
		 echo "<div class='login-place'>".ctools_modal_text_button(t('Login'), 'guides/nojs/login', t('Login'), 'ctools-modal-ctools-sample-style')." <a href=\"/\" onclick=\"window.location = Drupal.settings.basePath + &#039;twitter/redirect&#039;; return false;\"><img src='/".path_to_theme()."/images/twitter.png'></a>  ".l("Зарегистрироваться", "user/register", array("attributes"=>array("class"=>"reglink")))."</div>";
	  }
	  ?>
         <!-- header -->
         <div id="header">
            <div class="logo"><a href="/"><img alt="" src="/<?=path_to_theme()?>/images/logo.gif" /></a></div>
			<?php if (isset($primary_links)) : ?>
				<?php print theme('links', $primary_links, array('class' => 'links primary-links')) ?>
	        <?php endif; ?>         
         </div>
          <!-- content -->
         <div id="content">
		 <?php //print $breadcrumb; ?>
		  <?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
		  <?php if ($tabs): print '<div id="tabs-wrapper" class="clear-block">'; endif; ?>
		  <?php if (!$is_front && $title): print '<h3'. ($tabs ? ' class="with-tabs"' : '') .'>'. $title .'</h3>'; endif; ?>
		  <?php if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul></div>'; endif; ?>
		  <?php if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
		  <?php if ($show_messages && $messages): print $messages; endif; ?>
		  <?php print $help; ?>
		  <div class="clear-block">
			<?php print $content ?>
		  </div>
         </div>
         <!-- footer -->
         <div id="footer">
            <div class="wrapper">
              <?php print $footer_message . $footer ?>
            </div>
         </div>
      </div>
   </div>
   <script type="text/javascript"> Cufon.now(); </script>
     <?php print $closure ?>
</body>
</html>