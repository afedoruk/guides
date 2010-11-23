/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

DROP TABLE IF EXISTS `access`;
CREATE TABLE `access` (
  `aid` int(11) NOT NULL AUTO_INCREMENT,
  `mask` varchar(255) NOT NULL DEFAULT '',
  `type` varchar(255) NOT NULL DEFAULT '',
  `status` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`aid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `comments`;
CREATE TABLE `comments` (
  `cid` int(11) NOT NULL AUTO_INCREMENT,
  `pid` int(11) NOT NULL DEFAULT '0',
  `nid` int(11) NOT NULL DEFAULT '0',
  `uid` int(11) NOT NULL DEFAULT '0',
  `subject` varchar(64) NOT NULL DEFAULT '',
  `comment` longtext NOT NULL,
  `hostname` varchar(128) NOT NULL DEFAULT '',
  `timestamp` int(11) NOT NULL DEFAULT '0',
  `status` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `format` smallint(6) NOT NULL DEFAULT '0',
  `thread` varchar(255) NOT NULL,
  `name` varchar(60) DEFAULT NULL,
  `mail` varchar(64) DEFAULT NULL,
  `homepage` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`cid`),
  KEY `pid` (`pid`),
  KEY `nid` (`nid`),
  KEY `status` (`status`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `content_type_guide`;
CREATE TABLE `content_type_guide` (
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `field_phone_value` longtext,
  `field_mail_email` varchar(255) DEFAULT NULL,
  `field_skype_value` longtext,
  `field_addinfo_value` longtext,
  `field_addinfo_format` int(10) unsigned DEFAULT NULL,
  `field_photo_fid` int(11) DEFAULT NULL,
  `field_photo_list` tinyint(4) DEFAULT NULL,
  `field_photo_data` text,
  PRIMARY KEY (`vid`),
  KEY `nid` (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `content_type_testimonial`;
CREATE TABLE `content_type_testimonial` (
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `field_guide_nid` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`vid`),
  KEY `nid` (`nid`),
  KEY `field_guide_nid` (`field_guide_nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `files`;
CREATE TABLE `files` (
  `fid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `uid` int(10) unsigned NOT NULL DEFAULT '0',
  `filename` varchar(255) NOT NULL DEFAULT '',
  `filepath` varchar(255) NOT NULL DEFAULT '',
  `filemime` varchar(255) NOT NULL DEFAULT '',
  `filesize` int(10) unsigned NOT NULL DEFAULT '0',
  `status` int(11) NOT NULL DEFAULT '0',
  `timestamp` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`fid`),
  KEY `uid` (`uid`),
  KEY `status` (`status`),
  KEY `timestamp` (`timestamp`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `flag_content`;
CREATE TABLE `flag_content` (
  `fcid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `fid` smallint(5) unsigned NOT NULL DEFAULT '0',
  `content_type` varchar(32) NOT NULL DEFAULT '',
  `content_id` int(10) unsigned NOT NULL DEFAULT '0',
  `uid` int(10) unsigned NOT NULL DEFAULT '0',
  `timestamp` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`fcid`),
  UNIQUE KEY `fid_content_type_content_id_uid` (`fid`,`content_type`,`content_id`,`uid`),
  KEY `content_type_content_id` (`content_type`,`content_id`),
  KEY `content_type_uid` (`content_type`,`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `flag_counts`;
CREATE TABLE `flag_counts` (
  `fid` smallint(5) unsigned NOT NULL DEFAULT '0',
  `content_type` varchar(32) NOT NULL DEFAULT '',
  `content_id` int(10) unsigned NOT NULL DEFAULT '0',
  `count` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`fid`,`content_type`,`content_id`),
  KEY `fid_content_type` (`fid`,`content_type`),
  KEY `content_type_content_id` (`content_type`,`content_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `flood`;
CREATE TABLE `flood` (
  `fid` int(11) NOT NULL AUTO_INCREMENT,
  `event` varchar(64) NOT NULL DEFAULT '',
  `hostname` varchar(128) NOT NULL DEFAULT '',
  `timestamp` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`fid`),
  KEY `allow` (`event`,`hostname`,`timestamp`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `geonames_countryinfo`;
CREATE TABLE `geonames_countryinfo` (
  `iso_alpha2` varchar(2) NOT NULL,
  `iso_alpha3` varchar(3) NOT NULL,
  `iso_numeric` smallint(5) unsigned NOT NULL,
  `fips_code` varchar(3) NOT NULL,
  `name` varchar(60) NOT NULL,
  `capital` varchar(60) NOT NULL,
  `areainsqkm` varchar(11) NOT NULL,
  `population` varchar(11) NOT NULL,
  `continent` varchar(2) NOT NULL,
  `tld` varchar(200) DEFAULT NULL,
  `currency` varchar(3) NOT NULL,
  `currencyname` varchar(200) DEFAULT NULL,
  `phone` varchar(200) DEFAULT NULL,
  `postal_code_format` varchar(200) DEFAULT NULL,
  `postal_code_regex` varchar(200) DEFAULT NULL,
  `languages` varchar(100) NOT NULL,
  `geonameid` int(10) unsigned NOT NULL,
  `neighbours` varchar(200) DEFAULT NULL,
  `equivalentfipscode` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`geonameid`),
  KEY `iso_alpha3` (`iso_alpha3`),
  KEY `iso_numeric` (`iso_numeric`),
  KEY `fips_code` (`fips_code`),
  KEY `continent` (`continent`),
  KEY `currency` (`currency`),
  KEY `iso_alpha2` (`iso_alpha2`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `geonames_featurecodes`;
CREATE TABLE `geonames_featurecodes` (
  `class` varchar(1) NOT NULL,
  `code` varchar(10) NOT NULL,
  `name` varchar(64) NOT NULL,
  `description` varchar(255) NOT NULL,
  PRIMARY KEY (`class`,`code`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gmaps_content_address`;
CREATE TABLE `gmaps_content_address` (
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `field_name` varchar(32) NOT NULL DEFAULT '',
  `delta` int(10) unsigned NOT NULL DEFAULT '0',
  `country` char(2) NOT NULL DEFAULT '',
  `adminarea` varchar(64) DEFAULT NULL,
  `subadminarea` varchar(64) DEFAULT NULL,
  `locality` varchar(64) DEFAULT NULL,
  `deplocality` varchar(64) DEFAULT NULL,
  `postalcode` varchar(16) DEFAULT NULL,
  `thoroughfare` varchar(255) DEFAULT NULL,
  `privacy` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `search` varchar(255) DEFAULT NULL,
  `u_adminarea` varchar(64) DEFAULT NULL,
  `u_subadminarea` varchar(64) DEFAULT NULL,
  `u_locality` varchar(64) DEFAULT NULL,
  `u_deplocality` varchar(64) DEFAULT NULL,
  `u_postalcode` varchar(16) DEFAULT NULL,
  `u_thoroughfare` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`vid`,`field_name`,`delta`),
  KEY `filter` (`country`,`u_adminarea`(32),`u_subadminarea`(32),`u_locality`(32),`u_deplocality`(32),`u_postalcode`,`u_thoroughfare`(32)),
  KEY `fast_filter` (`country`,`u_locality`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gmaps_content_point`;
CREATE TABLE `gmaps_content_point` (
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `field_name` varchar(32) NOT NULL DEFAULT '',
  `delta` int(10) unsigned NOT NULL DEFAULT '0',
  `map_type` varchar(255) NOT NULL DEFAULT 'earth',
  `latitude` decimal(8,6) NOT NULL DEFAULT '0.000000',
  `longitude` decimal(9,6) NOT NULL DEFAULT '0.000000',
  `elevation` decimal(7,2) DEFAULT NULL,
  `x` float DEFAULT NULL,
  `y` float DEFAULT NULL,
  `z` float DEFAULT NULL,
  `privacy` text,
  `bounds` text,
  `pov` text,
  `search` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`vid`,`field_name`,`delta`),
  KEY `bounds` (`map_type`,`latitude`,`longitude`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gmaps_icons`;
CREATE TABLE `gmaps_icons` (
  `icid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `default_id` varchar(128) NOT NULL DEFAULT '',
  `type` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `throttle_support` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `sticky` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `sticky_id` int(10) unsigned NOT NULL DEFAULT '0',
  `base_id` int(10) unsigned NOT NULL DEFAULT '0',
  `label` varchar(32) NOT NULL DEFAULT '',
  `label_length` int(11) NOT NULL DEFAULT '0',
  `icon` varchar(255) NOT NULL DEFAULT '',
  `icon_size` varchar(255) NOT NULL,
  `shadow` varchar(255) DEFAULT NULL,
  `shadow_size` varchar(255) DEFAULT NULL,
  `icon_anchor` varchar(255) DEFAULT NULL,
  `info_window_anchor` varchar(255) DEFAULT NULL,
  `print_image` varchar(255) DEFAULT NULL,
  `moz_print_image` varchar(255) DEFAULT NULL,
  `print_shadow` varchar(255) DEFAULT NULL,
  `transparent` varchar(255) DEFAULT NULL,
  `imagemap` varchar(255) DEFAULT NULL,
  `maxheight` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `drag_cross_image` varchar(255) DEFAULT NULL,
  `drag_cross_size` varchar(255) DEFAULT NULL,
  `drag_cross_anchor` varchar(255) DEFAULT NULL,
  `modified` tinyint(4) NOT NULL DEFAULT '0',
  `locked` tinyint(4) NOT NULL DEFAULT '0',
  `data` longtext,
  PRIMARY KEY (`icid`),
  UNIQUE KEY `default_id` (`default_id`),
  UNIQUE KEY `name` (`name`),
  KEY `dynamic` (`base_id`,`label`),
  KEY `filter` (`type`,`sticky`,`base_id`,`label`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gmaps_maps`;
CREATE TABLE `gmaps_maps` (
  `mid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `default_id` varchar(128) NOT NULL DEFAULT '',
  `type` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `throttle_support` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `throttle_lifetime` mediumint(8) unsigned NOT NULL DEFAULT '3600',
  `size` varchar(255) NOT NULL DEFAULT '',
  `maptypes` text NOT NULL,
  `default_maptype` varchar(64) NOT NULL DEFAULT '',
  `center` text NOT NULL,
  `zoom` tinyint(4) NOT NULL DEFAULT '-1',
  `map_data` mediumtext NOT NULL,
  `methods` text NOT NULL,
  `method_data` mediumtext NOT NULL,
  `iw_data` mediumtext NOT NULL,
  `controls` mediumtext NOT NULL,
  `control_data` mediumtext NOT NULL,
  `ov_data` mediumtext NOT NULL,
  `modified` tinyint(4) NOT NULL DEFAULT '0',
  `locked` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`mid`),
  UNIQUE KEY `default_id` (`default_id`),
  UNIQUE KEY `name` (`name`),
  KEY `filter` (`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gmaps_static_maps`;
CREATE TABLE `gmaps_static_maps` (
  `mid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `default_id` varchar(128) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `throttle_support` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `throttle_lifetime` mediumint(8) unsigned NOT NULL DEFAULT '3600',
  `se_support` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `size` varchar(255) NOT NULL DEFAULT '',
  `maptype` varchar(32) NOT NULL DEFAULT '',
  `center` text NOT NULL,
  `zoom` tinyint(4) NOT NULL DEFAULT '-1',
  `format` varchar(16) NOT NULL DEFAULT 'gif',
  `fix_viewport` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `frame` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `content` mediumtext NOT NULL,
  `ov_data` mediumtext NOT NULL,
  `modified` tinyint(4) NOT NULL DEFAULT '0',
  `locked` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`mid`),
  UNIQUE KEY `default_id` (`default_id`),
  UNIQUE KEY `name` (`name`),
  KEY `filter` (`maptype`,`format`,`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `history`;
CREATE TABLE `history` (
  `uid` int(11) NOT NULL DEFAULT '0',
  `nid` int(11) NOT NULL DEFAULT '0',
  `timestamp` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`uid`,`nid`),
  KEY `nid` (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `node`;
CREATE TABLE `node` (
  `nid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `type` varchar(32) NOT NULL DEFAULT '',
  `language` varchar(12) NOT NULL DEFAULT '',
  `title` varchar(255) NOT NULL DEFAULT '',
  `uid` int(11) NOT NULL DEFAULT '0',
  `status` int(11) NOT NULL DEFAULT '1',
  `created` int(11) NOT NULL DEFAULT '0',
  `changed` int(11) NOT NULL DEFAULT '0',
  `comment` int(11) NOT NULL DEFAULT '0',
  `promote` int(11) NOT NULL DEFAULT '0',
  `moderate` int(11) NOT NULL DEFAULT '0',
  `sticky` int(11) NOT NULL DEFAULT '0',
  `tnid` int(10) unsigned NOT NULL DEFAULT '0',
  `translate` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`nid`),
  UNIQUE KEY `vid` (`vid`),
  KEY `node_changed` (`changed`),
  KEY `node_created` (`created`),
  KEY `node_moderate` (`moderate`),
  KEY `node_promote_status` (`promote`,`status`),
  KEY `node_status_type` (`status`,`type`,`nid`),
  KEY `node_title_type` (`title`,`type`(4)),
  KEY `node_type` (`type`(4)),
  KEY `uid` (`uid`),
  KEY `tnid` (`tnid`),
  KEY `translate` (`translate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `node_access`;
CREATE TABLE `node_access` (
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `gid` int(10) unsigned NOT NULL DEFAULT '0',
  `realm` varchar(255) NOT NULL DEFAULT '',
  `grant_view` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `grant_update` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `grant_delete` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`nid`,`gid`,`realm`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `node_comment_statistics`;
CREATE TABLE `node_comment_statistics` (
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `last_comment_timestamp` int(11) NOT NULL DEFAULT '0',
  `last_comment_name` varchar(60) DEFAULT NULL,
  `last_comment_uid` int(11) NOT NULL DEFAULT '0',
  `comment_count` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`nid`),
  KEY `node_comment_timestamp` (`last_comment_timestamp`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `node_counter`;
CREATE TABLE `node_counter` (
  `nid` int(11) NOT NULL DEFAULT '0',
  `totalcount` bigint(20) unsigned NOT NULL DEFAULT '0',
  `daycount` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `timestamp` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `node_revisions`;
CREATE TABLE `node_revisions` (
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `vid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `uid` int(11) NOT NULL DEFAULT '0',
  `title` varchar(255) NOT NULL DEFAULT '',
  `body` longtext NOT NULL,
  `teaser` longtext NOT NULL,
  `log` longtext NOT NULL,
  `timestamp` int(11) NOT NULL DEFAULT '0',
  `format` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`vid`),
  KEY `nid` (`nid`),
  KEY `uid` (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `oauth_consumer`;
CREATE TABLE `oauth_consumer` (
  `uid` int(10) unsigned NOT NULL,
  `consumer_key` varchar(32) NOT NULL,
  `consumer_secret` varchar(32) NOT NULL,
  PRIMARY KEY (`uid`),
  UNIQUE KEY `consumer_key` (`consumer_key`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `oauth_nonce`;
CREATE TABLE `oauth_nonce` (
  `nonce` varchar(32) NOT NULL,
  `timestamp` int(11) NOT NULL,
  `token` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`nonce`),
  KEY `timestamp` (`timestamp`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `oauth_token`;
CREATE TABLE `oauth_token` (
  `token_key` varchar(32) NOT NULL,
  `token_secret` varchar(32) NOT NULL,
  `type` varchar(7) NOT NULL,
  `uid` int(10) unsigned NOT NULL,
  `consumer_key` varchar(32) NOT NULL,
  `webservices` text,
  `authorized` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`token_key`),
  KEY `token_key_type` (`token_key`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `openid_association`;
CREATE TABLE `openid_association` (
  `idp_endpoint_uri` varchar(255) DEFAULT NULL,
  `assoc_handle` varchar(255) NOT NULL,
  `assoc_type` varchar(32) DEFAULT NULL,
  `session_type` varchar(32) DEFAULT NULL,
  `mac_key` varchar(255) DEFAULT NULL,
  `created` int(11) NOT NULL DEFAULT '0',
  `expires_in` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`assoc_handle`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `openid_nonce`;
CREATE TABLE `openid_nonce` (
  `idp_endpoint_uri` varchar(255) DEFAULT NULL,
  `nonce` varchar(255) DEFAULT NULL,
  `expires` int(11) NOT NULL DEFAULT '0',
  KEY `nonce` (`nonce`),
  KEY `expires` (`expires`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pm_email_notify`;
CREATE TABLE `pm_email_notify` (
  `user_id` int(10) unsigned NOT NULL,
  `email_notify_is_enabled` int(10) unsigned NOT NULL,
  UNIQUE KEY `user_id` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pm_index`;
CREATE TABLE `pm_index` (
  `mid` int(10) unsigned NOT NULL,
  `thread_id` int(10) unsigned NOT NULL,
  `uid` int(10) unsigned NOT NULL,
  `is_new` int(10) unsigned NOT NULL DEFAULT '1',
  `deleted` int(10) unsigned NOT NULL DEFAULT '0',
  KEY `list` (`uid`,`deleted`,`is_new`),
  KEY `messages` (`mid`,`uid`),
  KEY `participants` (`thread_id`,`uid`,`deleted`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pm_message`;
CREATE TABLE `pm_message` (
  `mid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `author` int(10) unsigned NOT NULL,
  `subject` varchar(255) NOT NULL,
  `body` longtext NOT NULL,
  `format` smallint(6) NOT NULL DEFAULT '0',
  `timestamp` int(10) unsigned NOT NULL,
  PRIMARY KEY (`mid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pm_tags_index`;
CREATE TABLE `pm_tags_index` (
  `tag_id` int(10) unsigned NOT NULL,
  `uid` int(10) unsigned NOT NULL,
  `thread_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`tag_id`,`uid`,`thread_id`),
  KEY `thread_tags` (`uid`,`thread_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `search_dataset`;
CREATE TABLE `search_dataset` (
  `sid` int(10) unsigned NOT NULL DEFAULT '0',
  `type` varchar(16) DEFAULT NULL,
  `data` longtext NOT NULL,
  `reindex` int(10) unsigned NOT NULL DEFAULT '0',
  UNIQUE KEY `sid_type` (`sid`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `search_index`;
CREATE TABLE `search_index` (
  `word` varchar(50) NOT NULL DEFAULT '',
  `sid` int(10) unsigned NOT NULL DEFAULT '0',
  `type` varchar(16) DEFAULT NULL,
  `score` float DEFAULT NULL,
  UNIQUE KEY `word_sid_type` (`word`,`sid`,`type`),
  KEY `sid_type` (`sid`,`type`),
  KEY `word` (`word`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `search_node_links`;
CREATE TABLE `search_node_links` (
  `sid` int(10) unsigned NOT NULL DEFAULT '0',
  `type` varchar(16) NOT NULL DEFAULT '',
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `caption` longtext,
  PRIMARY KEY (`sid`,`type`,`nid`),
  KEY `nid` (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `search_total`;
CREATE TABLE `search_total` (
  `word` varchar(50) NOT NULL DEFAULT '',
  `count` float DEFAULT NULL,
  PRIMARY KEY (`word`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `sessions`;
CREATE TABLE `sessions` (
  `uid` int(10) unsigned NOT NULL,
  `sid` varchar(64) NOT NULL DEFAULT '',
  `hostname` varchar(128) NOT NULL DEFAULT '',
  `timestamp` int(11) NOT NULL DEFAULT '0',
  `cache` int(11) NOT NULL DEFAULT '0',
  `session` longtext,
  PRIMARY KEY (`sid`),
  KEY `timestamp` (`timestamp`),
  KEY `uid` (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `simpletest`;
CREATE TABLE `simpletest` (
  `message_id` int(11) NOT NULL AUTO_INCREMENT,
  `test_id` int(11) NOT NULL DEFAULT '0',
  `test_class` varchar(255) NOT NULL DEFAULT '',
  `status` varchar(9) NOT NULL DEFAULT '',
  `message` text NOT NULL,
  `message_group` varchar(255) NOT NULL DEFAULT '',
  `function` varchar(255) NOT NULL DEFAULT '',
  `line` int(11) NOT NULL DEFAULT '0',
  `file` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`message_id`),
  KEY `reporter` (`test_class`,`message_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `simpletest_test_id`;
CREATE TABLE `simpletest_test_id` (
  `test_id` int(11) NOT NULL AUTO_INCREMENT,
  `last_prefix` varchar(60) DEFAULT '',
  PRIMARY KEY (`test_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `term_data`;
CREATE TABLE `term_data` (
  `tid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `name` varchar(255) NOT NULL DEFAULT '',
  `description` longtext,
  `weight` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`tid`),
  KEY `taxonomy_tree` (`vid`,`weight`,`name`),
  KEY `vid_name` (`vid`,`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `term_hierarchy`;
CREATE TABLE `term_hierarchy` (
  `tid` int(10) unsigned NOT NULL DEFAULT '0',
  `parent` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`tid`,`parent`),
  KEY `parent` (`parent`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `term_node`;
CREATE TABLE `term_node` (
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `tid` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`tid`,`vid`),
  KEY `vid` (`vid`),
  KEY `nid` (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `term_relation`;
CREATE TABLE `term_relation` (
  `trid` int(11) NOT NULL AUTO_INCREMENT,
  `tid1` int(10) unsigned NOT NULL DEFAULT '0',
  `tid2` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`trid`),
  UNIQUE KEY `tid1_tid2` (`tid1`,`tid2`),
  KEY `tid2` (`tid2`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `term_synonym`;
CREATE TABLE `term_synonym` (
  `tsid` int(11) NOT NULL AUTO_INCREMENT,
  `tid` int(10) unsigned NOT NULL DEFAULT '0',
  `name` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`tsid`),
  KEY `tid` (`tid`),
  KEY `name_tid` (`name`,`tid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `twitter`;
CREATE TABLE `twitter` (
  `twitter_id` decimal(20,0) unsigned NOT NULL DEFAULT '0',
  `screen_name` varchar(255) NOT NULL DEFAULT '',
  `created_at` varchar(64) NOT NULL DEFAULT '',
  `created_time` int(11) NOT NULL,
  `text` varchar(255) DEFAULT NULL,
  `source` varchar(255) DEFAULT NULL,
  `in_reply_to_status_id` decimal(20,0) unsigned DEFAULT NULL,
  `in_reply_to_user_id` decimal(20,0) unsigned DEFAULT NULL,
  `in_reply_to_screen_name` varchar(255) DEFAULT NULL,
  `truncated` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`twitter_id`),
  KEY `screen_name` (`screen_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `twitter_account`;
CREATE TABLE `twitter_account` (
  `twitter_uid` decimal(20,0) unsigned NOT NULL DEFAULT '0',
  `uid` bigint(20) unsigned NOT NULL,
  `host` varchar(255) DEFAULT NULL,
  `screen_name` varchar(255) DEFAULT NULL,
  `password` varchar(64) DEFAULT NULL,
  `oauth_token` varchar(64) DEFAULT NULL,
  `oauth_token_secret` varchar(64) DEFAULT NULL,
  `name` varchar(64) NOT NULL DEFAULT '',
  `description` varchar(255) DEFAULT NULL,
  `location` varchar(255) DEFAULT NULL,
  `followers_count` int(11) NOT NULL DEFAULT '0',
  `friends_count` int(11) NOT NULL DEFAULT '0',
  `statuses_count` int(11) NOT NULL DEFAULT '0',
  `favourites_count` int(11) NOT NULL DEFAULT '0',
  `url` varchar(255) DEFAULT NULL,
  `profile_image_url` varchar(255) DEFAULT NULL,
  `protected` int(10) unsigned NOT NULL DEFAULT '0',
  `profile_background_color` varchar(6) NOT NULL DEFAULT '',
  `profile_text_color` varchar(6) NOT NULL DEFAULT '',
  `profile_link_color` varchar(6) NOT NULL DEFAULT '',
  `profile_sidebar_fill_color` varchar(6) NOT NULL DEFAULT '',
  `profile_sidebar_border_color` varchar(6) NOT NULL DEFAULT '',
  `profile_background_image_url` varchar(255) DEFAULT NULL,
  `profile_background_tile` int(10) unsigned NOT NULL DEFAULT '1',
  `verified` int(10) unsigned NOT NULL DEFAULT '1',
  `created_at` varchar(64) NOT NULL DEFAULT '',
  `created_time` int(11) NOT NULL,
  `utc_offset` int(11) NOT NULL,
  `import` int(10) unsigned NOT NULL DEFAULT '1',
  `last_refresh` int(11) NOT NULL DEFAULT '0',
  `is_global` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`twitter_uid`),
  KEY `screen_name` (`screen_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `url_alias`;
CREATE TABLE `url_alias` (
  `pid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `src` varchar(128) NOT NULL DEFAULT '',
  `dst` varchar(128) NOT NULL DEFAULT '',
  `language` varchar(12) NOT NULL DEFAULT '',
  PRIMARY KEY (`pid`),
  UNIQUE KEY `dst_language_pid` (`dst`,`language`,`pid`),
  KEY `src_language_pid` (`src`,`language`,`pid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `urlfill`;
CREATE TABLE `urlfill` (
  `type` varchar(8) NOT NULL DEFAULT '',
  `node_type` varchar(32) NOT NULL DEFAULT '',
  `field_name` varchar(32) NOT NULL DEFAULT '',
  `variable` varchar(64) NOT NULL DEFAULT '',
  `multiple` tinyint(4) NOT NULL,
  `override` tinyint(4) NOT NULL,
  `editable` varchar(8) NOT NULL,
  `nourl` varchar(8) NOT NULL,
  PRIMARY KEY (`type`,`node_type`,`field_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `uid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(60) NOT NULL DEFAULT '',
  `pass` varchar(32) NOT NULL DEFAULT '',
  `mail` varchar(64) DEFAULT '',
  `mode` tinyint(4) NOT NULL DEFAULT '0',
  `sort` tinyint(4) DEFAULT '0',
  `threshold` tinyint(4) DEFAULT '0',
  `theme` varchar(255) NOT NULL DEFAULT '',
  `signature` varchar(255) NOT NULL DEFAULT '',
  `signature_format` smallint(6) NOT NULL DEFAULT '0',
  `created` int(11) NOT NULL DEFAULT '0',
  `access` int(11) NOT NULL DEFAULT '0',
  `login` int(11) NOT NULL DEFAULT '0',
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `timezone` varchar(8) DEFAULT NULL,
  `language` varchar(12) NOT NULL DEFAULT '',
  `picture` varchar(255) NOT NULL DEFAULT '',
  `init` varchar(64) DEFAULT '',
  `data` longtext,
  PRIMARY KEY (`uid`),
  UNIQUE KEY `name` (`name`),
  KEY `access` (`access`),
  KEY `created` (`created`),
  KEY `mail` (`mail`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `users_roles`;
CREATE TABLE `users_roles` (
  `uid` int(10) unsigned NOT NULL DEFAULT '0',
  `rid` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`uid`,`rid`),
  KEY `rid` (`rid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

