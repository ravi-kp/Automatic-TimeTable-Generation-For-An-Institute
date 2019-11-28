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
#page-in {min-height:1px;padding:10px 0;background-color:#ffffff;_height:1px;}
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


//ini_set('display_errors', 1);
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
            
   
  
<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
System("./run.sh");

?> 
<form action="generate.php">
<button class="button" style="vertical-align:middle"><span> Print</span></button>
</form>

           <p class="btn-more box noprint">&nbsp;</p>
          </div> <!-- /article -->
            <hr class="noscreen" />
            
       <!-- </div> <!-- /content -->



</div> <!-- /main -->

</body>
</html>
