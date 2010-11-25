<?php

/**
 * Implementation of hook_rules_defaults().
 */
function guide_workflow_rules_defaults() {
  return array(
    'rules' => array(
      'guide_workflow_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Unpublish guide card when created by unregistered user',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'guide_workflow',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is Карточка гида',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'guide' => 'guide',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#info' => array(
              'label' => 'User has role(s)',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User',
                ),
              ),
              'module' => 'User',
            ),
            '#name' => 'rules_condition_user_hasrole',
            '#settings' => array(
              'roles' => array(
                '0' => 2,
              ),
              'operation' => 'OR',
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
          '2' => array(
            '#type' => 'condition',
            '#settings' => array(
              'code' => 'global $user;

if($user->uid==0)
return true;
else
return false;',
              'vars' => array(
                '0' => 'user',
              ),
            ),
            '#name' => 'rules_condition_custom_php',
            '#info' => array(
              'label' => 'Execute custom PHP code',
              'module' => 'PHP',
              'eval input' => array(
                '0' => 'code',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'auto_save' => 1,
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_core_node_unpublish_action',
            '#info' => array(
              'label' => 'Unpublish created content',
              'module' => 'Node',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'base' => 'rules_core_action_execute',
              'action_name' => 'node_unpublish_action',
              'configurable' => FALSE,
              'label callback' => 'rules_core_node_label_callback',
              'label_skeleton' => 'Unpublish @node',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#settings' => array(
              'message' => 'Ваша карточка гида будет доступна другим пользователям после того, как вы подтвердите свой адрес email. Посмотрите в свой почтовый ящик — там должно быть письмо со ссылкой для подтверждения.',
              'error' => 0,
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              'path' => '<front>',
              'query' => '',
              'fragment' => '',
              'force' => 0,
              'immediate' => 0,
            ),
            '#name' => 'rules_action_drupal_goto',
            '#info' => array(
              'label' => 'Page redirect',
              'module' => 'System',
              'eval input' => array(
                '0' => 'path',
                '1' => 'query',
                '2' => 'fragment',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'guide_workflow_2' => array(
        '#type' => 'rule',
        '#set' => 'event_user_login',
        '#label' => 'Publish guide card when guide logs in',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'guide_workflow',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Execute custom PHP code',
              'module' => 'PHP',
              'eval input' => array(
                '0' => 'code',
              ),
            ),
            '#name' => 'rules_condition_custom_php',
            '#settings' => array(
              'code' => 'global $user;
$nid=db_result(db_query("SELECT nid FROM {node} WHERE uid=%d AND type=\'guide\' AND status=0", $user->uid));
if($nid)
return true;
else
return false;',
              'vars' => array(),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              '#argument map' => array(
                'user' => 'account',
              ),
            ),
            '#name' => 'guides_helpers_publish_action',
            '#info' => array(
              'label' => 'Publish guide card',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Current user',
                ),
              ),
              'module' => 'User',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'message' => 'Ваша карточка гида опубликована!',
              'error' => 0,
            ),
            '#name' => 'rules_action_drupal_message',
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#weight' => 0,
          ),
          '3' => array(
            '#info' => array(
              'label' => 'Page redirect',
              'module' => 'System',
              'eval input' => array(
                '0' => 'path',
                '1' => 'query',
                '2' => 'fragment',
              ),
            ),
            '#name' => 'rules_action_drupal_goto',
            '#settings' => array(
              'path' => 'guides/redirect',
              'query' => '',
              'fragment' => '',
              'force' => 1,
              'immediate' => 0,
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}
