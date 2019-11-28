
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="cs" lang="cs">
<head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <meta http-equiv="content-language" content="cs" />
    <meta name="robots" content="all,follow" />

    <meta name="author" content="All: ... [Nazev webu - www.url.cz]; e-mail: info@url.cz" />
    <meta name="copyright" content="Design/Code: Vit Dlouhy [Nuvio - www.nuvio.cz]; e-mail: vit.dlouhy@nuvio.cz" />
    
    <title>Time Table Generator</title>
    <meta name="description" content="..." />
    <meta name="keywords" content="..." />
	
    
    <link rel="index" href="./" title="Home" />
    <link rel="stylesheet" media="screen,projection" type="text/css" href="./css/main.css" />
    <link rel="stylesheet" media="print" type="text/css" href="./css/print.css" />
    <link rel="stylesheet" media="aural" type="text/css" href="./css/aural.css" />
    <style>

.button {
  background-color: #4CAF50;
  border: groove;
  color: white;
  padding: 2px 13px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 14px;
  margin: 4px 2px;
  cursor: pointer;
}

.button2 {
  display: inline-block;
  border-radius: 4px;
  background-color: #4CAF50;
  border: groove;
  color: #FFFFFF;
  text-align: center;
  font-size: 14px;
  padding: 2px;
  width: 130px;
  transition: all 0.5s;
  cursor: pointer;
  margin: 3px;
}
.button2:before{
	
}

    </style>
</head>

<body id="www-url-cz">
<!-- Main -->
<div id="main" class="box">
<?php 
include "Header.php"
?>
<?php 
include "menu.php"
?>   
<!-- Page (2 columns) -->
    <div id="page" class="box">
    <div id="page-in" class="box">

        <div id="strip" class="box noprint">

            <!-- RSS feeds -->
            <hr class="noscreen" />

            
          <hr class="noscreen" />
            
        </div> <!-- /strip -->

        <!-- Content -->
        <div id="content">

           
            <!-- /article -->

            <hr class="noscreen" />

           
            <!-- /article -->

            <hr class="noscreen" />
            
            <!-- Article -->
           
            <!-- /article -->

            <hr class="noscreen" />

            <!-- Article -->
            <div class="article">
                <h2><span>Course Details</span></h2>
  <table width="100%" border="1" cellpadding="1" cellspacing="2" bordercolor="#006699" >
<tr>
<th height="32" bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>Course Name</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>Division </strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>Department</strong></div></th>
</tr>
 
 <?php
$dept=$_POST['txtName3'];
$sem_type=$_POST['txtName4'];	
$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
$result = mysqli_query($db,"select course_name,division,department from course where department='$dept' and sem_type='$sem_type' ");
while($row = mysqli_fetch_array($result))
{
$course_name=$row['course_name'];
$division=$row['division'];
$dept=$row['department'];
?>
<tr>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $course_name;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $division;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $dept;?></strong></div></td>
</tr>
<?php
}
// Retrieve Number of records returned
$records = mysqli_num_rows($result);
?>

<?php
// Close the connection
mysqli_close($db);
?>
</table>

<!-- adding add department button -->
 <form action="sampaddc.php">
<div align="center">
<button class="button2" style="vertical-align:middle"><span>Add Course</span></button></div>
</form>


           <p class="btn-more box noprint">&nbsp;</p>
          </div> <!-- /article -->
            <hr class="noscreen" />
            
        </div> <!-- /content -->

<?php
include "right.php"
?>
    </div> <!-- /page-in -->
    </div> <!-- /page -->

<?php
include "footer.php"
?>  

</div> <!-- /main -->

</body>
</html>
