<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Time Table Generator</title>
</head>

<body>
<?php
$R_no=$_GET['txtName2'];	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"delete from slot_table where slot_table.slot_name = '$R_no' ");
	mysqli_close ($db);
echo '<script type="text/javascript">alert("slot deleted Succesfully");window.location=\'slot_details.php\';</script>';
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
