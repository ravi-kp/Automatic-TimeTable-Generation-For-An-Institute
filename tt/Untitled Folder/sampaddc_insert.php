<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
	$C_Name=$_POST['txtName1'];
	//echo $C_Name;
	$nos=$_POST['txtName2'];
	//echo $nos;
	$sem_type=$_POST['selectSem'];
	$course_type1=(isset($_POST['myCheck_first']) ? 'Core_Course' : '');
	//echo $course_type1;
	$semester=$_POST['txtName5'];
	echo $semester;
	$course_type2=(isset($_POST['myCheck_second']) ? 'Elective_Course' : ''); 
	echo $course_type2;
	$arr_sem=array();
	$arr_sem[]=(isset($_POST['option1']) ? '5' : '');
	$arr_sem[]=(isset($_POST['option2']) ? '6' : '');
	$arr_sem[]=(isset($_POST['option3']) ? '7' : '');
	$arr_sem[]=(isset($_POST['option4']) ? '8' : '');
	$sem_option=implode('',$arr_sem);
	echo $sem_option;
	
	$dept=$_POST['txtName3'];
	echo $dept;
	$lab_type1=(isset($_POST['myCheck_third']) ? 'y' : '');
	echo $lab_type1;
	$lab_type2=(isset($_POST['myCheck_fourth']) ? 'n' : '');
	echo $lab_type2;
	$division='';
	$division1=(isset($_POST['option5']) ? 'D1' : '');
	echo $division1;
	$division2=(isset($_POST['option6']) ? 'D2' : '');
	echo $division2;
	$division3=(isset($_POST['option7']) ? 'D3' : '');
	echo $division3;
	$arr_labroom=array();
	$arr_labroom[]=$_POST['txtNameForLab'];
	$arr_labroom[]=$_POST['txtNameForLab2'];
	$arr_labroom[]=$_POST['txtNameForLab3'];
	$lab_room=implode(' ',$arr_labroom); 
	echo $lab_room;
	$lb_room='';
    $priority1=(isset($_POST['myCheck_prefer1']) ? '0' : '');
	$priority2=(isset($_POST['myCheck_prefer2']) ? '1' : '');
	echo $priority1;
	echo $priority2;
	$preffered_room='';
	$preffered_slot='';
	$pref_room=$_POST['txtName7'];
	echo $pref_room;
	$pref_slot=$_POST['txtName8'];
	// Establish Connection with MYSQL
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
if( $lab_type2 === "n" )
{
if($course_type1==='Core_Course' and $priority1==='0')	
{
$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$semester."','".$dept."','".$lab_type2."','".$priority1."','".$preffered_room."','".$preffered_slot."','".$division."','".$lb_room."')");
}
if($course_type1==='Core_Course' and $priority2==='1')	
{
$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$semester."','".$dept."','".$lab_type2."','".$priority2."','".$pref_room."','".$pref_slot."','".$division."','".$lb_room."')");
}
if($course_type2==='Elective_Course' and $priority1==='0')	
{
$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$sem_option."','".$dept."','".$lab_type2."','".$priority1."','".$preffered_room."','".$preffered_slot."','".$division."','".$lb_room."')");
}
if($course_type2==='Elective_Course' and $priority2==='1')	
{
$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$sem_option."','".$dept."','".$lab_type2."','".$priority2."','".$pref_room."','".$pref_slot."','".$division."','".$lb_room."')");
}
}
else
{
	if($course_type1==='Core_Course' and $priority1==='0')
	{
	if($division1 == 'D1' or $division1 == 'D2' or $division1 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$semester."','".$dept."','".$lab_type1."','".$priority1."','".$preffered_room."','".$preffered_slot."','".$division1."','".$lab_room."')");
	}
	if($division2 == 'D1' or $division2 == 'D2' or $division2 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$semester."','".$dept."','".$lab_type1."','".$priority1."','".$preffered_room."','".$preffered_slot."','".$division2."','".$lab_room."')");
	}
	if($division3 == 'D1' or $division3 == 'D2' or $division3 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$semester."','".$dept."','".$lab_type1."','".$priority1."','".$preffered_room."','".$preffered_slot."','".$division3."','".$lab_room."')");
	}
	}
	
	if($course_type1==='Core_Course' and $priority2==='1')
	{
	if($division1 == 'D1' or $division1 == 'D2' or $division1 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$semester."','".$dept."','".$lab_type1."','".$priority2."','".$pref_room."','".$pref_slot."','".$division1."','".$lab_room."')");
	}
	if($division2 == 'D1' or $division2 == 'D2' or $division2 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$semester."','".$dept."','".$lab_type1."','".$priority2."','".$pref_room."','".$pref_slot."','".$division2."','".$lab_room."')");
	}
	if($division3 == 'D1' or $division3 == 'D2' or $division3 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$semester."','".$dept."','".$lab_type1."','".$priority2."','".$pref_room."','".$pref_slot."','".$division3."','".$lab_room."')");
	}
	}
	
	if($course_type2==='Elective_Course' and $priority1==='0')
	{
	if($division1 == 'D1' or $division1 == 'D2' or $division1 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$sem_option."','".$dept."','".$lab_type1."','".$priority1."','".$preffered_room."','".$preffered_slot."','".$division1."','".$lab_room."')");
	}
	if($division2 == 'D1' or $division2 == 'D2' or $division2 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$sem_option."','".$dept."','".$lab_type1."','".$priority1."','".$preffered_room."','".$preffered_slot."','".$division2."','".$lab_room."')");
	}
	if($division3 == 'D1' or $division3 == 'D2' or $division3 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$sem_option."','".$dept."','".$lab_type1."','".$priority1."','".$preffered_room."','".$preffered_slot."','".$division3."','".$lab_room."')");
	}
	}
	
	if($course_type2==='Elective_Course' and $priority2==='1')
	{
	if($division1 == 'D1' or $division1 == 'D2' or $division1 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$sem_option."','".$dept."','".$lab_type1."','".$priority2."','".$pref_room."','".$pref_slot."','".$division1."','".$lab_room."')");
	}
	if($division2 == 'D1' or $division2 == 'D2' or $division2 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$sem_option."','".$dept."','".$lab_type1."','".$priority2."','".$pref_room."','".$pref_slot."','".$division2."','".$lab_room."')");
	}
	if($division3 == 'D1' or $division3 == 'D2' or $division3 == 'D3')
	{
		$result = mysqli_query($db,"insert into course(course_name,no_of_student,sem_type,semester,department,lab,preference,preffered_room,preffered_slot,division,lab_room) values('".$C_Name."','".$nos."','".$sem_type."','".$sem_option."','".$dept."','".$lab_type1."','".$priority2."','".$pref_room."','".$pref_slot."','".$division3."','".$lab_room."')");
	}
	}
}
	
	
	
	// Close The Connection
	mysqli_close ($db);
	
	echo '<script type="text/javascript">window.location=\'sampaddc.php\';</script>';

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
