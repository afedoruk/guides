<?php
// $Id: privatemsg-view.tpl.php,v 1.1.2.8 2010/03/10 12:35:34 berdir Exp $
// Each file loads it's own styles because we cant predict which file will be
// loaded.
drupal_add_css(drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.css');
?>
<?php print $anchors; ?>
<div class="privatemsg-box-fb <?php print $zebra; ?>" id="privatemsg-mid-<?php print $mid; ?>">
  <div class="middle-column">
    <div class="name">
      <?php print $author_name_link; ?>
    </div>
    <div class="date">
      <?php print $message_timestamp; ?>
    </div>
  </div>
  <div class="right-column">
    <div class="message-body">
      <?php if (isset($new)) : ?>
        <span class="new"><?php print $new ?></span>
      <?php endif ?>
      <?php print $message_body; ?>
    </div>
    <?php if ( isset($message_actions)) : ?>
       <?php print $message_actions ?>
    <?php endif ?>
  </div>
  <div class="clear-both"></div>
</div>