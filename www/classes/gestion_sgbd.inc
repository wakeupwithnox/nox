<?php
require_once("classes/config.inc");

class gestion_sgbd {
	
	private $config;
	
	public function __construct() {
		$this->config = config::get_intance();
	}
	
	public function connexion_sgbd() {
		$db = new PDO($this->config-> get_sgbd_host(),$this->config-> get_sgbd_user(),$this->config-> get_sgbd_password());
		$db->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);;
		return $db;
	}
		
}



?>