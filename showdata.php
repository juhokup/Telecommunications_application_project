<?php
$servername = "localhost";
$username = "dbaccess_rw";
$password = "fasdjkf2389vw2c3k234vk2f3";
$dbname = "measurements";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
        }

$sql = "SELECT Suunta, X, Y, Z, Aikaleima FROM rawdata ORDER BY id DESC LIMIT 5";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
   while($row = $result->fetch_assoc()) {
      echo "Suunta: " . $row["Suunta"] . " - X: " . $row["X"] . " - Y: " . $row["Y"] . " - Z: " . $row["Z"]  . " - Aika: " . $row["Aikaleima"] ."<br>" ;
   }
}

$conn->close();
?>
