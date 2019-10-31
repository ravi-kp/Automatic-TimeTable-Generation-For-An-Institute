<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
$R_no=$_POST['txtName2[]'];	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"delete from room_table where room_table.room_no = '$R_no' ");
	mysqli_close ($db);
	//echo '<script type="text/javascript">window.location=\'delete_room.php\';</script>';
?>

<?php
include "right.php"
?>
    
<?php
include "footer.php"
?>  

</body>
</html>
