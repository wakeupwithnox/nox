<?php
class contact {
	private $id_contact;
	private $prenom_contact;
	private $nom_contact;
	private $email_contact;	
	private $mdp_contact;
	private $role_contact;			
	
	
		
	public function get_id_contact() {
		return $this -> id_contact;
	}	
	public function get_prenom_contact() {
		return $this -> prenom_contact;
	}
	public function get_nom_contact() {
		return $this -> nom_contact;
	}	
	public function get_email_contact() {
		return $this -> email_contact;
	}
	public function get_mdp_contact() {
		return $this -> mdp_contact;
	}
	public function get_role_contact() {
		return $this -> role_contact;
	}


	public function set_id_contact($id_contact) {
		$this -> id_contact = $id_contact;
	}	
	public function set_prenom_contact($prenom_contact) {
		$this -> prenom_contact =$prenom_contact;
	}
	public function set_nom_contact($nom_contact) {
		$this -> nom_contact = $nom_contact;
	}
	public function set_email_contact($email_contact) {
		$this -> email_contact = $email_contact;
	}	
	public function set_mdp_contact($mdp_contact) {
		$this -> mdp_contact = $mdp_contact;
	}	
	public function set_role_contact($role_contact) {
		$this -> role_contact = $role_contact;
	}

		
	public function __construct($id_contact,$prenom_contact,$nom_contact,$email_contact,$mdp_contact,$role_contact) {
		$this -> id_contact = $id_contact;
		$this -> prenom_contact= $prenom_contact;
		$this -> nom_contact = $nom_contact;
		$this -> email_contact= $email_contact;
		$this -> mdp_contact = $mdp_contact;
		$this -> role_contact= $role_contact;	
	}
}
?>
