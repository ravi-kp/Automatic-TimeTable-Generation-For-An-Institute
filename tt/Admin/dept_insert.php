<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
    $Id=$_POST['txtId'];
	$Dept_code=$_POST['txtName2'];
	$Name=$_POST['txtName'];
	// Establish Connection with MYSQL
	$con = mysql_connect ("localhost","root");
	// Select Database
	mysql_select_db("tt", $con);
	// Specify the query to Insert Record
	$sql = "insert into department(dept_id,dept_code,dept_name) values('".$Id."','".$Dept_code."','".$Name."')";
	// execute query
	mysql_query ($sql,$con);
	// Close The Connection
	mysql_close ($con);
	
	echo '<script type="text/javascript">alert("Registration Completed Succesfully");window.location=\'departments.php\';</script>';

?>
</body>
</html>
