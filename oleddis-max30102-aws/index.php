<?php

include 'config.php';

// delete the old data if there's more than 500 data (FIFO)
/*$delete_query = "
DELETE FROM wp_max30102_data
WHERE no NOT IN (
    SELECT no
    FROM (
        SELECT no
        FROM wp_max30102_data
        ORDER BY create_at DESC
        LIMIT 500
    ) AS subquery
)
AND (SELECT COUNT(*) FROM wp_max30102_data) > 500;
";
$conn->query($delete_query)
*/

// SQL query to show 100 newest data from the wp_max30102_data table @aws_ec2_seni
$select_query = "SELECT * FROM wp_max30102_data ORDER BY create_at DESC LIMIT 100";
$result = $conn->query($select_query);

// Check if there are any rows returned
if ($result->num_rows > 0) {
    // Output data of each row
    while ($row = $result->fetch_assoc()) {
        // Display the data
        echo "ID: " . $row["no"] . " - Beat Average: " . $row["beat"] . " - EspO2: " . $row["espo2"] . " - T: " . $row["time"] . " - Time: " . $row["create_at"] . "<br>";
    }
} else {
    echo "No data found";
}

// Close the database connection
$conn->close();

?>