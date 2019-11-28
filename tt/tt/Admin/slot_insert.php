<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
$arr_day = array(); // Declare an array
$arr_time_start=array();
$arr_time_till=array();
$arr_day[] = $_POST['txtName2'];
$arr_day[] = $_POST['txtName3'];
$arr_day[] = $_POST['txtName4']; 
$insert_day = implode(' ',$arr_day); 
$arr_time_start[] = $_POST['txtName5'];
$arr_time_start[] = $_POST['txtName6'];
$arr_time_start[] = $_POST['txtName7']; 
$insert_time_start = implode(' ',$arr_time_start); 	
$arr_time_till[] = $_POST['txtName8'];
$arr_time_till[] = $_POST['txtName9'];
$arr_time_till[] = $_POST['txtName10']; 
$insert_time_till = implode(' ',$arr_time_till); 
        $s_Name=$_POST['txtName1'];
	//$s_day=$_POST['txtName2'];
       // $time_from=$_POST['txtName3'];
         // $time_till=$_POST['txtName4'];
	// Establish Connection with MYSQL
	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"insert into slot_table(slot_name,day,time_from,till_time) values('".$s_Name."','".$insert_day."','".$insert_time_start."','".$insert_time_till."')");
	
	// Close The Connection
	mysqli_close ($db);
	
	echo '<script type="text/javascript">;window.location=\'add_slots.php\';</script>';

?>
<?php
    $fh = fopen('slot_fromdb.txt', 'w');	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"SELECT slot_name,day,time_from FROM slot_table order by slot_id");
	
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
	echo '<script type="text/javascript">alert("slots added Succesfully");window.location=\'add_slots.php\';</script>';
?>
</body>
</html>
