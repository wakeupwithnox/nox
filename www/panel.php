<!DOCTYPE html>
<html>
	<head>
		<!--<META HTTP-EQUIV="Refresh" CONTENT="30">
		<META HTTP-EQUIV="Pragma" CONTENT="no-cache"> -->
		<meta charset="utf-8">

		<title>Panel - Nox by ABLE</title>

		<link href="css/jquery-ui.min.css" rel="stylesheet">
		<link href="css/keyboard.css" rel="stylesheet">
		
		<script src="js/jquery-latest.min.js"></script>
		<script src="js/jquery-ui.min.js"></script>
		<script src="js/bootstrap.min.js"></script>
		<script src="js/jquery.keyboard.js"></script>
		<script src="js/jquery.mousewheel.js"></script>

		<script>
			$(function(){
				$('#keyboard').keyboard();
			});
			$(function(){
				$('#keyboard1').keyboard();
			});
		</script>
	</head>
	<body>
		<div id="wrap"> 
			SSID <input id="keyboard" type="text"><br />
			Key	<input id="keyboard1" type="text">
		</div>
	</body>
</html>
