<?php
    
// Insert the data max30102 into the MySQL database @aws_ec2_seni
$servername = "localhost";
$username = "admin";
$password = "cfiot2J@y@";
$dbname = "cfiot_team2";

// Create a new MySQLi object
$conn = new mysqli($servername, $username, $password, $dbname);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
//else{
//    echo "database connected";
//}

?>