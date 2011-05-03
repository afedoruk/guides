<?php

/**
 * Implementation of hook_content_default_fields().
 */
function guides_testimonials_content_default_fields() {
  $fields = array();

  // Exported field: field_guide
  $fields['testimonial-field_guide'] = array(
    'field_name' => 'field_guide',
    'type_name' => 'testimonial',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'guide' => 'guide',
      'page' => 0,
      'story' => 0,
      'news' => 0,
      'testimonial' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => 'Написать отзыв',
        'hover_title' => 'Вы пользовались услугами этого гида? Расскажите о впечатлениях!',
        'destination' => 'default',
      ),
      'fallback' => 'page_not_found',
      'edit_fallback' => 0,
      'autocomplete_match' => 'starts_with',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_guide][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Гид',
      'weight' => '31',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Гид');

  return $fields;
}
