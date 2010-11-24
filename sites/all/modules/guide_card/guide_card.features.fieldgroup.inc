<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function guide_card_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_contacts
  $groups['guide-group_contacts'] = array(
    'group_type' => 'standard',
    'type_name' => 'guide',
    'group_name' => 'group_contacts',
    'label' => 'Контакты',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '0',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '0',
    'fields' => array(
      '0' => 'field_phone',
      '1' => 'field_mail',
      '2' => 'field_skype',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Контакты');

  return $groups;
}
