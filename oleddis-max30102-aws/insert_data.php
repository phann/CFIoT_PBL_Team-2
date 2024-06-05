<?php

include 'config.php';

// Retrieve the data from max30102 the POST parameters
$beat = $_POST['beat'];
$espo2 = $_POST['espo2'];
$time = $_POST['time'];

// Prepare the SQL statement from max30102 @aws_ec2_seni
$sql = "INSERT INTO wp_max30102_data (beat, espo2, time) VALUES ('$beat', '$espo2', '$time')";

// Execute the SQL statement
if ($conn->query($sql) === TRUE) {
    echo "Data inserted successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

// delete the old data if there's more than 500 data (FIFO)
/*
$delete_query = "DELETE FROM wp_max30102_data WHERE no NOT IN (SELECT no FROM (SELECT no FROM wp_max30102_data ORDER BY create_at DESC LIMIT 500) AS subquery) AND (SELECT COUNT(*) FROM wp_max30102_data) > 500";
$conn->query($delete_query)
*/

// Close the database connection
$conn->close();

?>
