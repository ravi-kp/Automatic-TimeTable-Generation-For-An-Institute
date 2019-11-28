<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
	$C_Name=$_POST['txtName1'];
	$c_sem=$_POST['txtName5'];
	$nos=$_POST['txtName2'];
	$dept=$_POST['txtName3'];
	$clab=$_POST['txtName4'];
        $priority=$_POST['txtName6'];
	$pref_room=$_POST['txtName7'];
	$pref_slot=$_POST['txtName8'];
	// Establish Connection with MYSQL
	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"insert into course_table(course_name,semester,no_of_students,Department,lab,preference,preffered_room,preffered_slot) values('".$C_Name."','".$c_sem."','".$nos."','".$dept."','".$clab."','".$priority."','".$pref_room."','".$pref_slot."')");
	
	// Close The Connection
	mysqli_close ($db);
	
	echo '<script type="text/javascript">window.location=\'addcourse.php\';</script>';

?>

<?php
    $fh = fopen('course_from_db.txt', 'w');
	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$temp=mysqli_query($db,"SELECT count(*) FROM course_table");
$result = mysqli_query($db,"SELECT * FROM course_table");
$result1=mysqli_fetch_row($temp);
$counts=$result1[0];
	fwrite($fh, $counts); 
	fwrite($fh, "\n");
    while ($row = mysqli_fetch_array($result)) {          
        $last = end($row);          
        $num = mysqli_num_fields($result) ;    
        for($i = 0; $i < $num; $i++) {            
            fwrite($fh, $row[$i]);                      
            if ($row[$i] != $last)
               fwrite($fh, " ");
        }                                                                 
        fwrite($fh, "\n");
    }
    fclose($fh);
	// Close The Connection
	mysqli_close ($db);
	echo '<script type="text/javascript">alert("Course added Succesfully");window.location=\'course_details.php\';</script>';
?>
</body>
</html>
