<?php
echo "We will we will rock you!\n";
$min = $_POST["min"];
$max = $_POST["max"];
$id = $_POST["user"];
$today = date("Y-m-d H:i:s");
$ip = $_SERVER["REMOTE_ADDR"];
$rec = $today . "," . $min . "," . $max . "," . $id . "," . $ip . "\n";
$fname = "app_dev_prj.txt";
if(file_exists($fname))
        $fp = fopen($fname, "a");
else
        $fp = fopen($fname, "w");

fwrite($fp, $rec);
fclose($fp);

echo "Data is saved\n";
?>
