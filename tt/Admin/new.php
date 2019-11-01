<?xml version="1.0"?>
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
	content:' \2295';
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
            
   
   <table width="100%" border="1" cellpadding="1" cellspacing="2" bordercolor="#006699" >
<tr>
<th height="32" bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>Day</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>8.30 –9.25</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>9.30-10.25</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>10.35-11.30</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>11.35-12.30</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>2.30-3.55</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>4.00-5.25</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>5.30-6.55</strong></div></th>
<th bgcolor="#006699" class="style3"><div align="left" class="style9 style5 style2"><strong>7.00-8.25</strong></div></th>
</tr>
   
   <?php
// Establish Connection with Database
$con = mysql_connect("localhost","root");
// Select Database
mysql_select_db("tt", $con);
// Specify the query to execute
$sql = "select * from time_slot";
// Execute query
$result = mysql_query($sql,$con);
// Loop through each records 
while($row = mysql_fetch_array($result))
{
$day=$row['Day'];
$ts1=$row['t1'];
$ts2=$row['t2'];
$ts3=$row['t3'];
$ts4=$row['t4'];
$ts4=$row['t5'];
$ts5=$row['t5'];
$ts6=$row['t6'];
$ts7=$row['t7'];
$ts8=$row['t8'];
?>
<tr>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $day;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $ts1;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $ts2;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $ts3;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $ts4;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $ts5;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $ts6;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $ts7;?></strong></div></td>
<td class="style3"><div align="left" class="style9 style5"><strong><?php echo $ts8;?></strong></div></td>
</tr>
<?php
}
// Retrieve Number of records returned
$records = mysql_num_rows($result);
?>

<?php
// Close the connection
mysql_close($con);
?>
</table>
    </td>
  </tr>
</table>

<form action="addcourse.php">
<button class="button2" style="vertical-align:middle"><span> Print</span></button>
</form>

           <p class="btn-more box noprint">&nbsp;</p>
          </div> <!-- /article -->
            <hr class="noscreen" />
            
       <!-- </div> <!-- /content -->



</div> <!-- /main -->

</body>
</html>
