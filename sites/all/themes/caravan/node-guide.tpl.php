<?php
$countries=geotest_country_list();
if($page)
{
	global $user;
	$testimonials=views_embed_view('testimonials', 'page_1', $node->nid);
	print "<div class='service'>".$links."</div>";
	echo "<h4>".$countries[$node->field_city[0]["country_id"]].", ".$node->field_city[0]["city_name"]."</h4>";
    
?>
    <!-- featured box begin -->
            <div id="guide-card">
               <ul class="ui-tabs-nav">
                  <li class="ui-tabs-nav-item ui-tabs-selected" id="nav-fragment-1">
                     <a href="#fragment-1">
                        <strong>Главное</strong>
                     </a>
                  </li>
				  <?
				  if($content)
					{
					?>
						 <li class="ui-tabs-nav-item ui-tabs-selected" id="nav-fragment-2">
						 <a href="#fragment-2">
							<strong>О себе</strong>
						 </a>
						 </li>
					<?
					}
					if(trim(strip_tags($testimonials)))
					{
                 ?>
                  <li class="ui-tabs-nav-item ui-tabs-selected last" id="<?=$content?"nav-fragment-3":"nav-fragment-2"?>">
                     <a href="<?=$content?"#fragment-3":"#fragment-2"?>">
                        <strong>Отзывы</strong>
                     </a>
                  </li>
				  <?
					}
				   ?>
               </ul>
               <!-- First Content -->
               <div id="fragment-1" class="ui-tabs-panel">			    
                  <div class="info">	
				  <?=$node->field_photo[0]["filepath"]?theme("imagecache", "guide_face", $node->field_photo[0]["filepath"]):"";?>
                     <div class="inner">											 
						<h4>Услуги</h4>
						<?
						foreach($node->taxonomy as $term)
						{
							$s[]=$term->name;
						}
						echo theme("item_list", $s);
						if($node->field_addinfo[0]["value"])
						{
							echo "<h4>Дополнительная информация</h4>";
							echo $node->field_addinfo[0]["view"];
						}
						echo "<h4>Контакты</h4>";
						if($user->uid || !$node->field_restrict_contact[0]["value"])
						{
							if($node->field_phone[0]["value"])
							{
								echo "Телефон: ".$node->field_phone[0]["view"]."<br>";
							}

							if($node->field_mail[0]["email"])
							{
								echo "Почта: ".$node->field_mail[0]["view"]."<br>";
							}
							if($node->field_skype[0]["value"])
							{
								echo "Skype: ";
								echo '<script type="text/javascript" src="http://download.skype.com/share/skypebuttons/js/skypeCheck.js"></script>';
								echo '<a href="skype:'.$node->field_skype[0]["value"].'?call"><img src="http://download.skype.com/share/skypebuttons/buttons/call_blue_transparent_34x34.png" style="border: none;" width="34" height="34" alt="Skype Me™!" /></a>';
								echo $node->field_skype[0]["view"]."<br>";
							}
						}
						else
						{
							echo "Этот гид разрешил показывать свои контакты только зарегистрированным пользователям сайта. ".l("Зарегистрируйтесь", "user/register")." или ".l("войдите на сайт", "guides/nojs/login").", чтобы увидеть контакты гида";
						}
					?>
                     </div>
					  <div class='clear-block'></div>
                  </div>
	  		     
               </div>
               <!-- Second Content -->
			   <?
				if($content)
				{
				?>
				<div id="fragment-2" class="ui-tabs-panel ui-tabs-hide">
                  <div class="info bg1">	
                  <?=$node->field_photo[0]["filepath"]?theme("imagecache", "guide_face", $node->field_photo[0]["filepath"]):"";?>
					 <div class="inner"> 
	                      <?=$content?>
                     </div>
					  <div class='clear-block'></div>
                  </div>
	  		      
				</div>
				<?
				}
				if(trim(strip_tags($testimonials)))
				{
				?>
               
               <!-- Third Content -->
               <div id="<?=$content?"fragment-3":"fragment-2"?>" class="ui-tabs-panel ui-tabs-hide">
                  <div class="info bg2">	
				  <?=$node->field_photo[0]["filepath"]?theme("imagecache", "guide_face", $node->field_photo[0]["filepath"]):"";?>
                     <div class="inner">
                        <h2>Отзывы</h2> 
                       <?
						print views_embed_view('testimonials', 'page_1', $node->nid);
						?>
                     </div>
					 <div class='clear-block'></div>
                  </div>
               </div>
			<?
				}
				?>
            </div>
            <!-- featured box begin -->
<?	
			;
}
else
{
	?>
	<li>
	   <?=$node->field_photo[0]["filepath"]?theme("imagecache", "userpic", $node->field_photo[0]["filepath"]):""?>
	   <div class="extra-wrap">
		  <p><strong><?=l($node->title, "node/".$node->nid)?></strong></p>	
		  <?
		  echo $countries[$node->field_city[0]["country_id"]].", ".$node->field_city[0]["city_name"]."<br>";
			foreach($node->taxonomy as $term)
			{
				$s[]=$term->name;
			}
			echo theme("item_list", $s);
			?>
	   </div>
	</li>
	<?
}