<?php

/*$user = 'root';
$password = 'root';
$db = 'camagru';
$host = 'localhost';
$port = 8889;*/

/*$con = mysql_connect('localhost:8889', 'root', 'root', 'camagru');

mysql_select_db('users', $con);*/

$con = mysqli_connect('localhost:8889', 'root', 'root'); //Database host may be:127.0.0.1:3306
if (!$con)
{
die('Could not connect: ' . mysql_error());
}
mysql_select_db('users', $con);
$sql="set names 'utf8'";// for unicode support, must use after mysql_select_db() function.
mysql_query($sql);
mysql_query('SET CHARACTER SET utf8')or die('charset problem:'.mysql_error());
mysql_query("SET SESSION collation_connection ='utf8_general_ci'") or die('collation      problem:'.mysql_error());
