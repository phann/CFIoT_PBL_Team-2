# CFIoT_PBL_Team-2

## Setup for AWS Service
- create an AWS account
- create IoT Core Service
- create EC2 Instance (Ubuntu 20.0) 30 GB Free Storage
- create Elastic IP for EC2 Instance
- create DynamoDB

## Setup for Server (Linux, Nginx, Mysql, PHP)
Installation refers to "Command History.txt"
- Install Nginx
- Install mysql,
  create user admin for mysql database
  ```bash
  CREATE USER 'admin'@'%' IDENTIFIED BY 'cfiot2J@y@';
  GRANT ALL PRIVILEGES ON *.* TO 'admin'@'%' WITH GRANT OPTION;
  FLUSH PRIVILEGES;
- Install PHP & PHPmyadmin
- Install PHP Composer
- Install Wordpress

### Deploy for web application
- Deploy database from "cfiot_team2.sql"
- Deploy Wordpress from "wordpress-cfiot.zip", and replace existing installation
