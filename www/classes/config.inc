<?php 
class config {
	
	private static $instance;
	
	private $sgbd_host;
	private $sgbd_user;
	private $sgbd_password;
	
	private function __construct() {
		$tab_config=parse_ini_file("configuration/config.ini.php",true);
		
		$this->sgbd_host=$tab_config["SGBD"]["sgbd_host"];
		$this->sgbd_user=$tab_config["SGBD"]["sgbd_user"];
		$this->sgbd_password=$tab_config["SGBD"]["sgbd_password"];
		
	}
	
		public static function get_intance() {
		if (config::$instance==NULL) config::$instance=new config();
		return config::$instance;
	}
	

		
	public function get_sgbd_host() {
		return $this -> sgbd_host;
	}
	public function get_sgbd_user() {
		return $this -> sgbd_user;
	}
	public function get_sgbd_password() {
		return $this -> sgbd_password;
	}

	
}


?>
