<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
	$r_Name=$_POST['txtName1'];
	$capacity=$_POST['txtName2'];
	// Establish Connection with MYSQL
	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"insert into room_table(room_no,capacity) values('".$r_Name."','".$capacity."')");
	
	// Close The Connection
	mysqli_close ($db);
	
	echo '<script type="text/javascript">;window.location=\'add_room.php\';</script>';

?>
<?php
    $fh = fopen('room_file.txt', 'w');	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"SELECT * FROM room_table");
	
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
	echo '<script type="text/javascript">alert("Rooms added Succesfully");window.location=\'add_room.php\';</script>';
?>
</body>
</html>
