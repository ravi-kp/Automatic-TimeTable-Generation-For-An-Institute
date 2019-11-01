
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

                <form action="course_insert.php"  method="post" onSubmit="return validateForm(this,arrFormValidation);" enctype="multipart/form-data" id="form2">
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
                      <td>Semester:</td>
                      <td><span id="sprytextfield2">
                        <label>
                        <select name="txtName5" id="txtName5">
	<option>1</option>
	<option>2</option>
	<option>3</option>
	<option>4</option>
	<option>5</option>
	<option>6</option>
        <option>7</option>
	<option>8</option>
	<option>5and7</option>
        <option>6and8</option>
	</select>
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
                      <td><span id="sprytextfield3">
                        <label>
                        <select name="txtName4" id="txtName4">
	                     <option>y</option>
	                     <option>n</option>
	                     </select>
                        </label>
                      <span class="textfieldRequiredMsg"></span></span>
                      </td>
                    </tr>



                  <tr>
                     <td>Preferrence(1 for High Priority):</td>
                      <td><span id="sprytextfield3">
                        <label>
                        <select name="txtName6" id="txtName6">
	                     <option value="opt1">0</option>
	                     <option value="opt2">1</option>
	                     </select>
                        </label>
                      <span class="textfieldRequiredMsg"></span></span>
                      </td>
                    </tr>

                    <tr>   
                    <td>preffered Room:</td>
                      <td><span id="sprytextfield3">
                        <label>
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
                        </label>
                      <span class="textfieldRequiredMsg"></span></span>
                      </td>
                    </tr>

  <tr>   
                    <td>preffered slot:</td>
                      <td><span id="sprytextfield3">
                        <label>
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
	                     </select>
                        </label>
                      <span class="textfieldRequiredMsg"></span></span>
                      </td>
                    </tr>
		
					
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
