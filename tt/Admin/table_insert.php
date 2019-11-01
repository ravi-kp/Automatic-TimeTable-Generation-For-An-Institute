<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
     $Course1=$_POST['course1'];
	 $Course2=$_POST['course2'];
	 $Course3=$_POST['course3'];
	 $Course4=$_POST['course4'];
	 $Course5=$_POST['course5'];
	 $Course6=$_POST['course6'];
	 $Id1="Monday";
	 $Id2="Tuesday";
	 $Id3="Wednesday";
	 $Id4="Thursday";
	 $Id5="Friday";
	// Establish Connection with MYSQL
	$con = mysql_connect ("localhost","root");
	// Select Database
	mysql_select_db("tt", $con);
	// Specify the query to Insert Record
	if($Course1=="Data Analysis")
	{
	 $sql = "insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id3."','','".$Course1."','".$Course1."','','','','','')";
		mysql_query ($sql,$con);
$sql1="insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id5."','','','','".$Course1."','','','','')";
		mysql_query ($sql1,$con);		
	}
	if($Course2=="Data Structures and Algorithms")
	{
		$sql = "insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id1."','".$Course2."','','','','','','','')";
		mysql_query ($sql,$con);
		$sql1="insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id2."','','".$Course2."','','','','','','')";
		mysql_query ($sql1,$con);
		$sql2="insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id4."','','','".$Course2."','','','','','')";
		mysql_query ($sql2,$con);	
	}
	
	if($Course3=="Data Structures and Algorithms Lab")
	{
		$sql = "insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id1."','','','','','','','','') ON DUPLICATE KEY UPDATE t5='".$Course3."',t6='".$Course3."' ";
		mysql_query ($sql,$con);
	}
	
	if($Course4=="Discrete Structures")
	{
		$sql = "insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id4."','','','','','','','','') ON DUPLICATE KEY UPDATE t6='".$Course4."' ";
		mysql_query ($sql,$con);
		$sql1="insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id5."','','','','','','','','') ON DUPLICATE KEY UPDATE t1='".$Course4."',t5='".$Course4."' ";
		mysql_query ($sql1,$con);
	}
	//echo "$Course5";
	if($Course5=="Economics")
	{
		$sql = "insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id3."','','','','','','','','') ON DUPLICATE KEY UPDATE t5='".$Course5."' ";
		mysql_query ($sql,$con);
		$sql1="insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id5."','','','','','','','','') ON DUPLICATE KEY UPDATE t2='".$Course5."',t3='".$Course5."' ";
		mysql_query ($sql1,$con);
		
	}
	if($Course6=="Software Systems Lab")
	{
		$sql = "insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id3."','','','','','','','','') ON DUPLICATE KEY UPDATE t1='".$Course6."' ";
		mysql_query ($sql,$con);
		$sql1="insert into time_slot(Day,t1,t2,t3,t4,t5,t6,t7,t8) values('".$Id2."','','','','','','','','') ON DUPLICATE KEY UPDATE t5='".$Course6."',t6='".$Course6."' ";
		mysql_query ($sql1,$con);
	}	
	// Close The Connection
	
	
echo '<script type="text/javascript">alert("Course added Succesfully");window.location=\'generated.php\';</script>';
?>
</body>
</html>
