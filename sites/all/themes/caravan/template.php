<?php
function caravan_links($links, $attributes = array('class' => 'links')) 
{
  global $language;
  $output = '';
 if (count($links) > 0) 
 {
    if(strstr($attributes['class'], 'primary'))
	{
		$output = '<ul class="nav">';

		$num_links = count($links);
		$i = 1;

		foreach ($links as $key => $link) {
		  $class = $key;

		  // Add first, last and active classes to the list of links to help out themers.
		  if ($i == 1) {
			$class .= ' first';
		  }
		  if ($i == $num_links) {
			$class .= ' last';
		  }
		  if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
			   && (empty($link['language']) || $link['language']->language == $language->language)) {
			$class .= ' active';
		  }
		  $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

		  if (isset($link['href'])) {
			// Pass in $link as $options, they share the same keys.
			$output .= l($link['title'], $link['href'], $link);
		  }
		  else if (!empty($link['title'])) {
			// Some links are actually not links, but we wrap these in <span> for adding title and class attributes
			if (empty($link['html'])) {
			  $link['title'] = check_plain($link['title']);
			}
			$span_attributes = '';
			if (isset($link['attributes'])) {
			  $span_attributes = drupal_attributes($link['attributes']);
			}
			$output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
		  }

		  $i++;
		  $output .= "</li>\n";
		}

		$output .= '</ul>';
	}
	else
	{	 
		$output = '<ul' . drupal_attributes($attributes) . '>';

		$num_links = count($links);
		$i = 1;

		foreach ($links as $key => $link) {
		  $class = $key;

		  // Add first, last and active classes to the list of links to help out themers.
		  if ($i == 1) {
			$class .= ' first';
		  }
		  if ($i == $num_links) {
			$class .= ' last';
		  }
		  if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
			   && (empty($link['language']) || $link['language']->language == $language->language)) {
			$class .= ' active';
		  }
		  $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

		  if (isset($link['href'])) {
			// Pass in $link as $options, they share the same keys.
			$output .= l($link['title'], $link['href'], $link);
		  }
		  else if (!empty($link['title'])) {
			// Some links are actually not links, but we wrap these in <span> for adding title and class attributes
			if (empty($link['html'])) {
			  $link['title'] = check_plain($link['title']);
			}
			$span_attributes = '';
			if (isset($link['attributes'])) {
			  $span_attributes = drupal_attributes($link['attributes']);
			}
			$output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
		  }

		  $i++;
		  $output .= "</li>\n";
		}

		$output .= '</ul>';
    }
  }
  return $output;
}

function caravan_preprocess_page(&$vars)
{
	if(arg(0)=="node" && is_numeric(arg(1)) && !arg(2))
	{
		$node=menu_get_object();
		if($node->type=="guide")
		{
			$vars["template_files"][]="page-node-guide";
			foreach($node->field_city as $city)
			{
				$p[]="Гид ".geotest_get_in_country($city["country_id"]).", ".$city["city_name"];
			}
			$vars["head_title"]=implode(". ", $p)." ".$node->title;
		}
	}
}

function caravan_username($object) {

  if ($object->uid && $object->name) {
    // Shorten the name when it is too long or it will break many tables.
    if (drupal_strlen($object->name) > 20) {
      $name = drupal_substr($object->name, 0, 15) . '...';
    }
    else {
      $name = $object->name;
    }

	if($object->picture)
		$pic=theme("imagecache", "small", $object->picture);

    if (user_access('access user profiles')) {
      $output = l($pic." ".$name, 'user/' . $object->uid, array('html'=>true, 'attributes' => array('title' => t('View user profile.'))));
    }
    else {
      $output = $pic." ".check_plain($name);
    }
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if (!empty($object->homepage)) {
      $output = l($object->name, $object->homepage, array('attributes' => array('rel' => 'nofollow')));
    }
    else {
      $output = check_plain($object->name);
    }

    $output .= ' (' . t('not verified') . ')';
  }
  else {
    $output = check_plain(variable_get('anonymous', t('Anonymous')));
  }

  return $output;
}

