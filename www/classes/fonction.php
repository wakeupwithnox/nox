<?php
//fonction valide
function choixFormatHeure($HourFormat) {
	if ($HourFormat=="12") { //shorttime
	$heure='heure =now.format("h : MM")'.';periode =now.format("TT");';
	}else { //isotime
	$heure='heure =now.format("H : MM")'.';periode ="";';
	}
	return $heure;
}

//fonction a voir

function redirection($nb,$etape) {
	switch ($etape) {
	case "1": //redirection choix langue
		header('Location: etape1.php');
		exit();
	break;
	}
}


function avant_insert($texte) {
	$texte=htmlentities($texte);
	return $texte;
}
function avant_affichage($texte) {
	$texte=html_entity_decode($texte);
	return $texte;
}


function avant_mail($texte) {
	$texte=strip_tags($texte);
	$texte=stripslashes($texte);
	return $texte;
}

function sn() {
	$chaine = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0I23456789";
	srand((double)microtime()*1000000);
	for($i=0; $i<12; $i++) {
	$id .= $chaine[rand()%strlen($chaine)];
	}
return $id;
}

function f_crypt($private_key, $str_to_crypt) {
	$private_key = md5($private_key);
	$letter = -1;
	$new_str = '';
	$strlen = strlen($str_to_crypt);

	for ($i = 0; $i < $strlen; $i++) {
		$letter++;
		if ($letter > 31) {
			$letter = 0;
		}
		$neword = ord($str_to_crypt{$i}) + ord($private_key{$letter});
		if ($neword > 255) {
			$neword -= 256;
		}
		$new_str .= chr($neword);
	}
	return base64_encode($new_str);
}
function f_decrypt($private_key, $str_to_decrypt) {
	$private_key = md5($private_key);
	$letter = -1;
	$new_str = '';
	$str_to_decrypt = base64_decode($str_to_decrypt);
	$strlen = strlen($str_to_decrypt);
	for ($i = 0; $i < $strlen; $i++) {
		$letter++;
		if ($letter > 31) {
			$letter = 0;
		}
		$neword = ord($str_to_decrypt{$i}) - ord($private_key{$letter});
		if ($neword < 1) {
			$neword += 256;
		}
		$new_str .= chr($neword);
	}
	return $new_str;
}
?>
