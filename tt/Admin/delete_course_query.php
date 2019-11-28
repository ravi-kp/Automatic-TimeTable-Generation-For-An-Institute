<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
$c_no=$_GET['txtName2'];
$division=$_GET['txtNamed'];	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"delete from course where course.course_name = '$c_no' and course.division= '$division'");
	mysqli_close ($db);
echo '<script type="text/javascript">alert("course deleted Succesfully");window.location=\'course_detail.php\';</script>';
?>

<?php
    $fh = fopen('course_from_db.txt', 'w');
	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$temp=mysqli_query($db,"SELECT count(*) FROM course");
$result = mysqli_query($db,"SELECT course_name,no_of_student,semester,department,lab,preference,preffered_slot,preffered_room,division,lab_room FROM course");
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
	//echo '<script type="text/javascript">alert("Course added Succesfully");window.location=\'course_details.php\';</script>';
?>
</body>
</html>
