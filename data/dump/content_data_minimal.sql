LOCK TABLES `node_access` WRITE;
/*!40000 ALTER TABLE `node_access` DISABLE KEYS */;
INSERT INTO `node_access` VALUES (0,0,'all',1,0,0);
/*!40000 ALTER TABLE `node_access` ENABLE KEYS */;
UNLOCK TABLES;

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (0,'','','',0,0,0,'','',0,0,0,0,0,NULL,'','','',NULL);
UPDATE users SET uid=0 WHERE name = '';
INSERT INTO `users` VALUES (1,'admin','154b7f1b8c224a746caf7ed3001fa63d','afedoruk@gmail.com',0,0,0,'','',0,1283717118,1290518106,1290025336,1,NULL,'','','afedoruk@gmail.com','a:0:{}');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
