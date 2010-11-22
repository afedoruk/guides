<?php
// $Id: custom_links.admin.inc,v 1.1 2008/01/27 09:16:01 eaton Exp $

// Lists all current custom links, and provides a link to the edit page.
function custom_links_page() {
  $links = _custom_links_load_all_links(TRUE);

  $header = array(t('key'), t('link'), '');

  $rows = array();
  foreach ($links as $link) {
    $row = array();
    $row[] = $link->link_key;
    $row[] =  $link->title;
    $row[] =  l(t('edit'), 'admin/build/custom_links/edit/' . $link->lid);
    $rows[] = $row;
  }
  if (count($rows) == 0) {
    $rows[] = array(array('data' => t('No custom links have been defined.'), 'colspan' => 3));
  }

  $rows[] = array(array('data' => l(t('Add a new custom link'), 'admin/build/custom_links/add'), 'colspan' => 3));


  return theme('table', $header, $rows);
}


// Displays an edit form for a custom link record.
function custom_links_form() {
  global $base_url;

  $lid = arg(4);
  if (isset($lid)) {
    $link = _custom_links_load_link($lid);
    $form['lid'] = array(
      '#type' => 'hidden',
      '#value' => $lid,
    );
  }

  $form['link'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link details'),
  );

  $form['link']['link_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Link key'),
    '#description' => t('A unique string to identify this link. It will also be used as a CSS class when the link is output as HTML.'),
    '#default_value' => $lid ? $link->link_key : NULL
  );

  $form['link']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#description' => t("The visible text of the link seen by the user."),
    '#default_value' => $lid ? $link->title : NULL
  );

  $form['link']['check_html'] = array(
    '#type' => 'checkbox',
    '#title' => t('Title uses HTML'),
    '#return_value' => 1,
    '#default_value' => $lid ? $link->check_html : 0
  );

  $form['link']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#description' => t("The Drupal path for the link. (!sample_url)", array('!sample_url' => $base_url.'/<u><b>node/1</b></u>#comment')),
    '#default_value' => $lid ? $link->path : NULL
  );

  $form['link']['querystring'] = array(
    '#type' => 'textfield',
    '#title' => t('Querystring'),
    '#description' => t("The optional querystring for the link. (!sample_url)", array('!sample_url' => $base_url.'/article?<u><b>id=1</b></u>')),
    '#default_value' => $lid ? $link->query : NULL
  );

  $form['link']['fragment'] = array(
    '#type' => 'textfield',
    '#title' => t('Anchor'),
    '#description' => t("The optional HTML anchor for the link. (!sample_url)", array('!sample_url' => $base_url.'/node/1<u><b>#comment</b></u>')),
    '#default_value' => $lid ? $link->fragment : NULL
  );

  $form['help'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Placeholder tokens'),
    '#description' => t("The following placeholder tokens can be used in paths, titles, querystrings, and anchors. they will be replaced with the appropriate values."),
  );

  if (module_exists('token')) {
    $form['help']['tokens'] = array(
      '#value' => theme('token_help', 'node'),
    );
  }
  else {
    $form['help']['#description'] = t("To use dynamic placeholder tokens in your paths and titles (the ID or title of the current node, for example), download and install the <a href='@token'>Token module</a> from Drupal.org.", array('@token' => 'http://www.drupal.org/project/token'));
    $form['help']['#collapsible'] = FALSE;
    $form['help']['#collapsed'] = FALSE;
  }

  $form['filters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link conditions'),
  );

  $modes = array(
    0 => t('In full node views'),
    1 => t('In teaser node views'),
    2 => t('In both teaser and full node views'),
    3 => t('In a sidebar block'),
  );
  $form['filters']['display'] = array(
    '#type' => 'select',
    '#title' => t('Display'),
    '#options' => $modes,
    '#default_value' => $lid ? $link->display : 2,
  );

  $options['*all*'] = t('All node types');
  foreach (node_get_types('names') as $type => $name) {
    $options[$type] = $name;
  }
  $form['filters']['node_type'] = array(
    '#type' => 'select',
    '#title' => t('Node type'),
    '#options' => $options,
    '#description' => t('If selected, the link will only be added to nodes of this type.'),
    '#default_value' => $lid ? $link->node_type : NULL,
  );

  $form['filters']['author_perm'] = array(
    '#type' => 'textfield',
    '#title' => t('Author permission restriction'),
    '#description' => t('A specific permission that the <i>author</i> of the node must have for the link to be added.'),
    '#default_value' => $lid ? $link->author_perm : NULL
  );

  $form['filters']['viewer_perm'] = array(
    '#type' => 'textfield',
    '#title' => t('Viewer permission restriction'),
    '#description' => t('A specific permission that the <i>viewer</i> of the node must have for the link to be added.'),
    '#default_value' => $lid ? $link->viewer_perm : 'access content'
  );

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  if ($lid) {
    $form['buttons']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('custom_links_form_delete'),
    );
  }

  return $form;
}

function custom_links_form_validate($form, &$form_state) {
  if (strpos($form_state['values']['link_key'], array(' ', '#', '.', '%', '^')) !== FALSE) {
    form_set_error('link][link_key', t('The link key may not contain spaces or punctuation.'));
  }
}

function custom_links_form_submit($form, &$form_state) {
  $link = (object)$form_state['values'];
  if ($link->node_type == '*all*') {
    $link->node_type = '';
  }
  $link->query = $link->querystring;
  _custom_links_save_link($link);

  $form_state['redirect'] = 'admin/build/custom_links';
}

function custom_links_form_delete($form, &$form_state) {
  _custom_links_delete_link($form_state['values']['lid']);
  $form_state['redirect'] = 'admin/build/custom_links';
}
