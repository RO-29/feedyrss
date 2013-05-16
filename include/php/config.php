<?php

$choice=$_GET['ch'];
if($choice=="yes"){
     
$connection = mysql_connect('localhost','rss','rss');
mysql_select_db('arduino_rss');
$email=mysql_query("select gmail from user_info");
mysql_query('DELETE FROM user_info ');
echo "Deleted the user with gmail id-- !!".$email;

}




?>
<!DOCTYPE html> 
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Configurations!</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="ajax based signup form infotuts">
    <meta name="author" content="InfoTuts">
    <link href="../../css/bootstrap.css" rel="stylesheet">
    <link href="../../css/bootstrap-responsive.css" rel="stylesheet">

      <script src="../../js/html5.js"></script>
	  <style type="text/css">
	  #footer {
	  margin-left: 400px;
	  }
	  </style>
</head>
  <body>	  
	
 	    

   <div class="well">    
      <form id="settings" class="form-horizontal" method="post" action="\cgi-bin\form.py">
		<legend>Settings</legend>		
		<div class="control-group">
	        <label class="control-label">Name</label>
			<div class="controls">
			    <div class="input-prepend">
				<span class="add-on"><i class="icon-user"></i></span>
					<input type="text" class="input-xlarge" id="fname" name="fname" placeholder="First Name">
				</div>
			</div>
		</div>
		<div class="control-group">
	        <label class="control-label">Gmail_email</label>
			<div class="controls">
			    <div class="input-prepend">
				<span class="add-on"><i class="icon-envelope"></i></span>
					<input type="text" class="input-xlarge" id="email" name="email" placeholder="Email">
				</div>
			</div>	
		</div>
		<div class="control-group">
	        <label class="control-label">Facebook_stream</label>
			<div class="controls">
			    <div class="input-prepend">
				<span class="add-on"><i class="icon-envelope"></i></span>
					<input type="text" class="input-xlarge" id="fb" name="fb" placeholder="https://www.facebook.com/feeds/notifications.php?id=631271796&viewer=631271796&key=AWicFSEf0YMG3CMO&format=rss20">
				</div>
			</div>	
		</div>
		<div class="control-group">
	        <label class="control-label">Gender</label>
			<div class="controls">
			    
					<p><div id="gender" name="gender" class="btn-group" data-toggle="buttons-radio">  
                    <button type="button" class="btn btn-info">Male</button>  
                    <button type="button" class="btn btn-info">Female</button>  
                    
                  </div></p>
				
			</div>
		</div>
		<div class="control-group">
	        <label class="control-label">Password_gmail</label>
			<div class="controls">
			    <div class="input-prepend">
				<span class="add-on"><i class="icon-lock"></i></span>
					<input type="Password" id="passwd" class="input-xlarge" name="passwd" placeholder="Password">
				</div>
			</div>
		</div>
		<div class="control-group">
	        <label class="control-label">Confirm Password</label>
			<div class="controls">
			    <div class="input-prepend">
				<span class="add-on"><i class="icon-lock"></i></span>
					<input type="Password" id="conpasswd" class="input-xlarge" name="conpasswd" placeholder="Re-enter Password">
				</div>
			</div>
		</div>
		
		<div class="control-group">
		<label class="control-label" for="input01"></label>
	      <div class="controls">
	       <button type="submit" class="btn btn-success" rel="tooltip" title="first tooltip">Configure me!</button>
	       
	      </div>
	
	</div>
	
	  </form>

   </div>
</div>
<div id="footer">
   <h2> <a href="../../index.htm">Take me back</a></h2>
</div>

    <!-- Javascript placed at the end of the file to make the  page load faster -->
    <script src="../../js/jquery.js"></script>
    
    <script src="../../js/bootstrap-button.js"></script>
	<script type="text/javascript" src="../../js/jquery.validate.js"></script>
	  <script type="text/javascript">
	  
	  $(document).ready(function(){
			
			$("#settings").validate({
				rules:{
					fname:"required",
					fb:"required",
					email:{
							required:true,
							email: true
						},
					passwd:{
						required:true,
						minlength: 8
					},
					conpasswd:{
						required:true,
						equalTo: "#passwd"
					},
					gender:"required"
				},
				
				errorClass: "help-inline"
				
			});
		});
	  </script>

  

  </body>
</html>

