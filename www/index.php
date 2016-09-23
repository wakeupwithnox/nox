<?php
//app section
//phpinfo();//var_dump(json_decode($json_app));


/*section 
compoment*/
$json_device = file_get_contents($_SERVER["HTTP_REFERER"]."component/Device/Device.json");
$parsed_json_device = json_decode($json_device);
$lang = $parsed_json_device->{'language'};
$format_tt = $parsed_json_device->{'format_tt'};
$format_hour = $parsed_json_device->{'format_hour'};
$theme_path = $parsed_json_device->{'theme_path'};


$img_panel = $_SERVER["HTTP_REFERER"].$theme_path."img/various/panel.png";
$img_home = $_SERVER["HTTP_REFERER"].$theme_path."img/various/home.png";

if ($format_tt==12) {
	$TT="now.format(\"TT\");";
	$HH="now.format(\"hh:MM\");";
	$DATE="now.format(\"dd/mm/yyyy\");";
} else {
	$TT="\"\"";
	$HH="now.format(\"HH:MM\");";
	$DATE="now.format(\"dd/mm/yyyy\");";
}


if (file_exists($filename)) {
    echo "Le fichier $filename existe.";
} else {
    echo "Le fichier $filename n'existe pas.";
}

function LanguageExist($file) {
	if (file_exists($file)) {
    echo "Le fichier $filename existe.";
	} else {
		echo "Le fichier $filename n'existe pas.";
	}


	if ($HourFormat=="12") { //shorttime
	$heure='heure =now.format("h : MM")'.';periode =now.format("TT");';
	}else { //isotime
	$heure='heure =now.format("H : MM")'.';periode ="";';
	}
	return $heure;
}



//section plugin
$json_plugin_state = file_get_contents($_SERVER["HTTP_REFERER"]."main.json");
$parsed_json_plugin_state = json_decode($json_plugin_state);
// 1 - Weather
// get the language
$language_weather_plugin = file_get_contents($_SERVER["HTTP_REFERER"]."plugin/".$parsed_json_plugin_state->{'active'}->{'weather'}->{'plugin'}."/language/".$lang.".json");
$parsed_language_weather_plugin = json_decode($language_weather_plugin);
$text_minimum = $parsed_language_weather_plugin->{'text_minimum'};
$text_maximum = $parsed_language_weather_plugin->{'text_maximum'};
// get data
$json_weather_plugin = file_get_contents($_SERVER["HTTP_REFERER"].$parsed_json_plugin_state->{'weather'}->{'directory'}.$parsed_json_plugin_state->{'weather'}->{'json'});
$parsed_json_weather_plugin = json_decode($json_weather_plugin);
$weather_current_day_humidity = $parsed_json_weather_plugin->{'weather_current_day'}->{'humidity'};
$weather_current_day_max_temperature = $parsed_json_weather_plugin->{'weather_current_day'}->{'max_temperature'};
$weather_current_day_min_temperature = $parsed_json_weather_plugin->{'weather_current_day'}->{'min_temperature'};
$weather_current_day_weather_context = $parsed_json_weather_plugin->{'weather_current_day'}->{'weather_context'};

// 1 - probe



?>
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
	<!--<META HTTP-EQUIV="Refresh" CONTENT="30">
	<META HTTP-EQUIV="Pragma" CONTENT="no-cache"> -->
		<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
		<title>Nox by ABLE</title>
		<link rel="stylesheet" type="text/css" href="css/able.css" />
		
		<?php require_once("js/all.inc"); ?>

		<script type="text/javascript"> 
		//document.oncontextmenu = new Function("return false");
		//document.onselectstart = new Function ("return false");


		function AffichageHeure() { //cette fonction utilise dateFormat.js
			var now = new Date();
			heure = <?php echo $HH;?>;
			periode = <?php echo $TT;?>;
			//date = <?php echo $DATE;?>;
			document.getElementById("heure").innerHTML = heure; 
			document.getElementById("periode").innerHTML = periode;
			//document.getElementById("date").innerHTML = date;
			setTimeout("AffichageHeure()",1000); 
		} 
		



		
		
		
		</script>
	</head>
<body onload="AffichageHeure()"> 

 <div id="heure" class="bloc-heure"></div>
 <div id="periode" class="bloc-AMPM"></div>
 <a href="panel.php"><img src="<?=$img_panel;?>"></a>
 <img src="<?=$img_home;?>">
 <?=$weather_current_day_humidity;?>%<br />
 <?=$text_maximum." ".$weather_current_day_max_temperature;?><br />
 <?=$text_minimum." ".$weather_current_day_min_temperature;?><br />
 <img src="<?=$_SERVER["HTTP_REFERER"].$theme_path."img/weather/".$weather_current_day_weather_context;?>.png"><br />
 
 </body> 
</html>