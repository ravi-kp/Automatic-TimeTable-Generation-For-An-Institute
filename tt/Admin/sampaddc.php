
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

	.styled-select {
   background: url(http://i62.tinypic.com/15xvbd5.png) no-repeat 96% 0;
   height: 25px;
   overflow: hidden;
   width: 190px;
}

#txtNameForLab{
  width:70px;   
}

#txtNameForLab2{
  width:70px;   
}

#txtNameForLab3{
  width:70px;   
}

.styled-select select {
   background: transparent;
   border: none;
   font-size: 14px;
   height: 25px;
   padding: 5px; /* If you add too much padding here, the options won't show in IE */
   width: 215px;
}

.styled-select.slate {
   background: url(http://i62.tinypic.com/2e3ybe1.jpg) no-repeat right center;
   height: 25px;
   width: 190px;
}

.styled-select.slate select {
   border: 1px solid #ccc;
   font-size: 16px;
   height: 30px;
   width: 215px;
}
.rounded {
   -webkit-border-radius: 20px;
   -moz-border-radius: 20px;
   border-radius: 20px;
}
.green   { background-color: #b0c4de; }
.green select   {; }


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
	content:'';
}



    </style>
    <style type="text/css">

.ds_box {
	background-color: #FFF;
	border: 1px solid #000;
	position: absolute;
	z-index: 32767;
}

.ds_tbl {
	background-color: #FFF;
}

.ds_head {
	background-color: #333;
	color: #FFF;
	font-family: Arial, Helvetica, sans-serif;
	font-size: 13px;
	font-weight: bold;
	text-align: center;
	letter-spacing: 2px;
}

.ds_subhead {
	background-color: #CCC;
	color: #000;
	font-size: 12px;
	font-weight: bold;
	text-align: center;
	font-family: Arial, Helvetica, sans-serif;
	width: 32px;
}

.ds_cell {
	background-color: #EEE;
	color: #000;
	font-size: 13px;
	text-align: center;
	font-family: Arial, Helvetica, sans-serif;
	padding: 5px;
	cursor: pointer;
}

.ds_cell:hover {
	background-color: #F3F3F3;
} /* This hover code won't work for IE */

</style>
<script src="SpryAssets/SpryValidationTextarea.js" type="text/javascript"></script>
<link href="SpryAssets/SpryValidationTextarea.css" rel="stylesheet" type="text/css" />
</head>
<body>

<table class="ds_box" cellpadding="0" cellspacing="0" id="ds_conclass" style="display: none;">
<tr><td id="ds_calclass">
</td></tr>
</table>


</head>

<body id="www-url-cz">
<SCRIPT language="JavaScript1.2" src="gen_validation.js"></SCRIPT>
<SCRIPT language="JavaScript1.2">
var arrFormValidation=
             [
			 		[//Name
						["minlen=1",
		"Please Enter Name"
						  ]
					
                     ],
                  
				   [//Email
						  
						["minlen=1",
		"Please Enter Email "
						  ], 
						  ["email",
		"Please Enter valid email "
						  ]  
                   ],
				   [//Mobile
						   ["num",
		"Please Enter valid Mobile "
						  ],
						  ["minlen=10",
		"Please Enter valid Mobile "
						  ],
						  ["maxlen=10",
		"Please Enter valid Mobile "
						  ] 	  
                   ],   
				   
				    
            ];
</SCRIPT>
<!-- Main -->
<div id="main" class="box">
<?php 
include "Header.php"
?>
<?php 
include "menu.php"
?>   

<?php

$user='root';
$pass='';
$db='timetable';
$db = new mysqli('localhost',$user,$pass,$db);
// Select Database
//mysql_select_db("tt", $con);
// Specify the query to execute
// Execute query
$result = mysqli_query($db,"select room_no from room_table");

?>

<!-- Page (2 columns) -->
    <div id="page" class="box">
    <div id="page-in" class="box">

        <div id="strip" class="box noprint">

            <!-- RSS feeds -->
            <hr class="noscreen" />

            <!-- Breadcrumbs -->
            <p id="breadcrumbs">&nbsp;</p>
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
               

                    <div class="login">

                <form action="sampaddc_insert.php"  method="post" onSubmit="return validateForm(this,arrFormValidation);" enctype="multipart/form-data" id="form2">
                  <table width="100%" border="0" cellspacing="0" cellpadding="0">
				  
				  
                    <tr>
                      <td>Course Name:</td>
                      <td><span id="sprytextfield3">
                        <label>
                        <input type="text" name="txtName1" id="txtName1" />
                        </label>
                      <span class="textfieldRequiredMsg"></span></span></td>
                    </tr>
                  
              
                    


                   <tr>
                      <td>No.of Students:</td>
                      <td><span id="sprytextfield3">
                        <label>
                        <input type="text" name="txtName2" id="txtName2" />
                        </label>
                      <span class="textfieldRequiredMsg"></span></span>
                      </td>
                    </tr>
                 <tr><td>Semester Type</td>
				 <td><select name="selectSem" id="selectSem">
	                     <option>odd</option>
	                     <option>even</option>
	                     </select></td></tr>
<tr><td><input type="checkBox" name="myCheck_first" id="myCheck_first" onclick="myFunc(),onlyOne11(this)" value="Core_Course" <?php if(isset($_POST['myCheck_first'])) echo "checked='checked'"; ?> />Core_Course
		<p id="dropdown" style="display:none">
      <select name="txtName5" id="txtName5">
	  <option></option>
	<option>1</option>
	<option>2</option>
	<option>3</option>
	<option>4</option>
	<option>5</option>
	<option>6</option>
        <option>7</option>
	<option>8</option>
	<option>57</option>
        <option>68</option>
	</select>
                        
		 
		 </td>
					 <td> <input type="checkBox" name="myCheck_second" id="myCheck_second"  onclick="myFunction(),onlyOne1(this)" value="Elective_Course" <?php if(isset($_POST['myCheck_second'])) echo "checked='checked'"; ?>/>Elective_Course
					   <p id="text2" style="display:none"><input type="checkbox" id="option1" onclick="myfuncopt1(),onlyOneopt1(this)" name="option1" value="5" <?php if(isset($_POST['option1'])) echo "checked='checked'"; ?>/>5</p>
					   <p id="text3" style="display:none"><input type="checkbox" id="option2" name="option2" onclick="myfuncopt2(),onlyOneopt2(this)" value="6" <?php if(isset($_POST['option2'])) echo "checked='checked'"; ?>/>6</p>
					   <p id="text4" style="display:none"><input type="checkbox" id="option3" name="option3" onclick="myfuncopt3(),onlyOneopt3(this)" value="7" <?php if(isset($_POST['option3'])) echo "checked='checked'"; ?>/>7</p>
                       <p id="text5" style="display:none"><input type="checkbox" id="option4" name="option4" onclick="myfuncopt4(),onlyOneopt4(this)" value="8" <?php if(isset($_POST['option4'])) echo "checked='checked'"; ?>/>8</p> </td>                    
					   <script>
function myFunc() {
  var checkBox = document.getElementById("myCheck_first");
  var dropdown = document.getElementById("dropdown");
 var text2 = document.getElementById("text2");
  var text3 = document.getElementById("text3");
  var text4 = document.getElementById("text4");
  var text5 = document.getElementById("text5");
  
  if (checkBox.checked == true){
	 dropdown.style.display = "block";
text2.style.display = "none";
	   text3.style.display = "none";
	    text4.style.display = "none";
		 text5.style.display = "none";
	 
  } else {
	  dropdown.style.display = "none";
	   
  }
}
function myFunction() {
  var checkBox = document.getElementById("myCheck_second");
  var text2 = document.getElementById("text2");
  var text3 = document.getElementById("text3");
  var text4 = document.getElementById("text4");
  var text5 = document.getElementById("text5");
var dropdown = document.getElementById("dropdown");
  if (checkBox.checked == true){
	 text2.style.display = "block";
	  text3.style.display = "block";
	   text4.style.display = "block";
	    text5.style.display = "block";
            dropdown.style.display = "none";
  } else {
	  text2.style.display = "none";
	   text3.style.display = "none";
	    text4.style.display = "none";
		 text5.style.display = "none";
  }
}

function myfuncopt1()
{
var checkBox = document.getElementById("option1");
var dropdown = document.getElementById("dropdown");
if (checkBox.checked == true){
dropdown.style.display = "none";
}
}
function myfuncopt2()
{
var checkBox = document.getElementById("option2");
var dropdown = document.getElementById("dropdown");
if (checkBox.checked == true){
dropdown.style.display = "none";
}
}
function myfuncopt3()
{
var checkBox = document.getElementById("option3");
var dropdown = document.getElementById("dropdown");
if (checkBox.checked == true){
dropdown.style.display = "none";
}
}
function myfuncopt4()
{
var checkBox = document.getElementById("option4");
var dropdown = document.getElementById("dropdown");
if (checkBox.checked == true){
dropdown.style.display = "none";
}
}

function onlyOne1(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_first')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOneopt1(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_first')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOneopt2(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_first')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOneopt3(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_first')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOneopt4(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_first')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOne11(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_second')
    var checkboxes1= document.getElementsByName('option1')
    var checkboxes2= document.getElementsByName('option2')
var checkboxes3= document.getElementsByName('option3')
var checkboxes4= document.getElementsByName('option4')
checkboxes1.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
 checkboxes2.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
checkboxes3.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
checkboxes4.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}


</script>
		
	              <tr>
                     <td>Department:</td>
                      <td><span id="sprytextfield3">
                        <label>
                        <select name="txtName3" id="txtName3">
                        <option>CSE</option>
	<option>ME</option>
	<option>EE</option>
	<option>CSE,ME</option>
	<option>CSE,EE</option>
	<option>ME,EE</option>
	<option>CSE,ME,EE</option>
	</select>
                        </label>
                      <span class="textfieldRequiredMsg"></span></span>
                      </td>
                    </tr>	
	
					<tr>
                     <td>Is It Lab(YES/NO):</td>
                      <td>
                        <input type="checkbox" name="myCheck_third" id="myCheck_third"  onclick="myFunctionThird(),onlyOne2(this)" value="y" <?php if(isset($_POST['myCheck_third'])) echo "checked='checked'"; ?>/>y
						<input type="checkbox" name="myCheck_fourth" id="myCheck_fourth"  onclick="myFunctionFourth(),onlyOne22(this)" value="n" <?php if(isset($_POST['myCheck_fourth'])) echo "checked='checked'"; ?>/>n</input>
						<p id="text6" style="display:none"><input type="checkbox" id="option5" name="option5" onclick="onlyOneopt5(this)" value="D1" <?php if(isset($_POST['option5'])) echo "checked='checked'"; ?>/>D1</p>
						<p id="text7" style="display:none"><input type="checkbox" id="option6" name="option6" onclick="onlyOneopt6(this)" value="D2" <?php if(isset($_POST['option6'])) echo "checked='checked'"; ?>/>D2</p>
						<p id="text8" style="display:none"><input type="checkbox" id="option7" name="option7" onclick="onlyOneopt7(this)" value="D3" <?php if(isset($_POST['option7'])) echo "checked='checked'"; ?>/>D3</p>
						<p id="dropdownLab" style="display:none">Labrooms:<select name="txtNameForLab" id="txtNameForLab">				
    <option></option>
	<option>21</option>
	<option>22</option>
	<option>23</option>
	<option>Chemistry_Lab</option>
	<option>Mech_Workshop</option>
	<option>Eng_Drawing_Lab</option>
	<option>Physics_Lab</option>
	<option>Computer_Lab(Ground_Floor)</option>
	<option>Computer_LabII</option>
	<option>Micro_Electronics_Lab</option>
	<option>Fluid_Mechanics</option>
	<option>DSP/PE_Lab</option>
	<option>Heat_Transfer_Lab</option>
	<option>SOM_Lab</option>
	<option>KDOM_Lab</option>
	<option>Measurement_Lab</option>
	<option>Manufacturing_Lab</option>
	<option>Machine_Lab</option>
	<option>Solid_Mechanics_Lab</option>
  </select>
  <select name="txtNameForLab2" id="txtNameForLab2">				
    <option>NULL</option>
	<option>21</option>
	<option>22</option>
	<option>23</option>
	<option>Chemistry_Lab</option>
	<option>Mech_Workshop</option>
	<option>Eng_Drawing_Lab</option>
	<option>Physics_Lab</option>
	<option>Computer_Lab(Ground_Floor)</option>
	<option>Computer_LabII</option>
	<option>Micro_Electronics_Lab</option>
	<option>Fluid_Mechanics</option>
	<option>DSP/PE_Lab</option>
	<option>Heat_Transfer_Lab</option>
	<option>SOM_Lab</option>
	<option>KDOM_Lab</option>
	<option>Measurement_Lab</option>
	<option>Manufacturing_Lab</option>
	<option>Machine_Lab</option>
	<option>Solid_Mechanics_Lab</option>
  </select>
  <select name="txtNameForLab3" id="txtNameForLab3">				
    <option>NULL</option>
	<option>21</option>
	<option>22</option>
	<option>23</option>
	<option>Chemistry_Lab</option>
	<option>Mech_Workshop</option>
	<option>Eng_Drawing_Lab</option>
	<option>Physics_Lab</option>
	<option>Computer_Lab(Ground_Floor)</option>
	<option>Computer_LabII</option>
	<option>Micro_Electronics_Lab</option>
	<option>Fluid_Mechanics</option>
	<option>DSP/PE_Lab</option>
	<option>Heat_Transfer_Lab</option>
	<option>SOM_Lab</option>
	<option>KDOM_Lab</option>
	<option>Measurement_Lab</option>
	<option>Manufacturing_Lab</option>
	<option>Machine_Lab</option>
	<option>Solid_Mechanics_Lab</option>
  </select></p>
                      </td>
                    </tr>

 <script>
function myFunctionThird() {
  var checkBox = document.getElementById("myCheck_third");
  var text6 = document.getElementById("text6");
  var text7 = document.getElementById("text7");
  var text8 = document.getElementById("text8");
  var dropdownLab = document.getElementById("dropdownLab");
  if (checkBox.checked == true){
	  text6.style.display = "block";
	  text7.style.display = "block";
	   text8.style.display = "block";
    dropdownLab.style.display = "block";
  } else {
	  text6.style.display = "none";
	  text7.style.display = "none";
	   text8.style.display = "none";
     dropdownLab.style.display = "none";
  }
}
function myFunctionFourth(){
var checkBox = document.getElementById("myCheck_fourth");
var text6 = document.getElementById("text6");
  var text7 = document.getElementById("text7");
  var text8 = document.getElementById("text8");
  var dropdownLab = document.getElementById("dropdownLab");
if (checkBox.checked == true){
text6.style.display = "none";
	  text7.style.display = "none";
	   text8.style.display = "none";
     dropdownLab.style.display = "none";
}
}
function onlyOne2(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_fourth')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOneopt5(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_fourth')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOneopt6(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_fourth')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOneopt7(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_fourth')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOne22(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_third')
var checkboxes1 = document.getElementsByName('option5')
var checkboxes2 = document.getElementsByName('option6')
var checkboxes3 = document.getElementsByName('option7')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
checkboxes1.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
checkboxes2.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
checkboxes3.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}

</script>

                  <tr>
                     <td>Preferrence(1 for High Priority):</td>
                     <td> <input type="checkbox" id="myCheck_prefer1" name="myCheck_prefer1" onclick="myFunction_fir(),onlyOne3(this)" value="0" <?php if(isset($_POST['myCheck_prefer1'])) echo "checked='checked'"; ?>/>0
                       <input type="checkbox" id="myCheck_prefer2"  name="myCheck_prefer2" value="1" onclick="myFunction_sec(),onlyOne33(this)" <?php if(isset($_POST['myCheck_prefer2'])) echo "checked='checked'"; ?>/>1
					   <p id="dropdown1" style="display:none"> 
                      <b>preffered Room: </b>
                        <select name="txtName7" id="txtName7">
                          <option></option>						
	                     <option>115</option>
	                     <option>117</option>
                             <option>119</option>
                             <option>203</option>
	                     <option>207</option>
                             <option>21</option>
                             <option>210</option>
	                     <option>211</option>
                             <option>215</option> 
                             <option>22</option>
	                     <option>23</option>
	                     </select>
                        </p>

                     <p id="dropdown2" style="display:none"> 
                    <b>preffered slot: </b>
                      
                        <select name="txtName8" id="txtName8">
						<option></option>
	                     <option>S1</option>
	                     <option>S2</option>
                             <option>S3</option>
                             <option>S4</option>
	                     <option>S5</option>
                             <option>S6</option>
                             <option>S7</option>
	                     <option>S8</option>
                             <option>S9</option> 
                             <option>S10</option>
	                     <option>S11</option>
                             <option>S12</option>
                             <option>S13</option>
                             <option>S14</option>
                             <option>S15</option>
	                     </select></p></td>
  <script>
function myFunction_sec() {
  var checkBox = document.getElementById("myCheck_prefer2");
  var dropdown1 = document.getElementById("dropdown1");
  var dropdown2 = document.getElementById("dropdown2");
  if (checkBox.checked == true){
    dropdown1.style.display = "block";
	dropdown2.style.display = "block";
  } else {
     dropdown1.style.display = "none";
	 dropdown2.style.display = "none";
  }
}

function myFunction_fir()
{
var checkBox = document.getElementById("myCheck_prefer1");
  var dropdown1 = document.getElementById("dropdown1");
  var dropdown2 = document.getElementById("dropdown2");
if (checkBox.checked == true){
         dropdown1.style.display = "none";
	 dropdown2.style.display = "none";
}
}
function onlyOne3(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_prefer2')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
function onlyOne33(checkbox) {
    var checkboxes = document.getElementsByName('myCheck_prefer1')
    checkboxes.forEach((item) => {
        if (item !== checkbox) item.checked = false
    })
}
</script>
					
					<tr>
                      <td colspan="2"><label>
                        <label></label>
                        <div align="center">
                          <input type="submit" name="button2" id="button2" value="Add" />
                          </div>
                      </label></td>
                    </tr>
                  </table>
                 </form>
              </div>
					
                  </table>
                 </form>
				 
              </div>

              <p class="btn-more box noprint">&nbsp;</p>
          </div> <!-- /article -->

            <hr class="noscreen" />
        </div> <!-- /content -->
		

<?php
 //include "right.php"
?>

    </div> <!-- /page-in -->
    </div> <!-- /page -->

 
<?php
 //include "footer.php"
?>
</div> <!-- /main -->


</body>
</html>
