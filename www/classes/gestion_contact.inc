<?php
require_once ("classes/contact.inc");

class gestion_contact {

	private $sgbd;
	
	public function __construct() {
		$this->sgbd = new gestion_sgbd();
	}
	
	public function ajouter($prenom_contact,$nom_contact,$email_contact,$mdp_contact) {
		try {		
			$db = $this->sgbd->connexion_sgbd();
			$sql = "INSERT INTO feg_contact (prenom_contact,nom_contact,email_contact,mdp_contact) VALUES 
			(:v1,:v2,:v3,:v4)";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v1",$prenom_contact);
			$stmt -> bindParam(":v2",$nom_contact);
			$stmt -> bindParam(":v3",$email_contact);
			$stmt -> bindParam(":v4",$mdp_contact);
			$db -> beginTransaction();
			$stmt -> execute();
			$id_contact=$db->lastInsertId();
			$db -> commit();
			$db = null;
			return $id_contact;
		}
		catch(PDOException $e){
			$db -> rollback();
			$db = null;
			echo "Echec : " . $e -> getMessage();
		}
	}

	
	public function modifier_contact_presse($id_contact,$id_contact_contact) {
		try {		
			$db = $this->sgbd->connexion_sgbd();
			$sql = "UPDATE sdg_contact SET id_contact_contact=:v13 WHERE id_contact=:v0";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v0",$id_contact);
			$stmt -> bindParam(":v13",$id_contact_contact);
			$db -> beginTransaction();
			$stmt -> execute();
			$db -> commit();
			$db = null;
		}
		catch(PDOException $e){
			$db -> rollback();
			$db = null;
			echo "Echec : " . $e -> getMessage();
		}
	}
	public function modifier_role_contact($id_contact,$role_contact) {
		try {		
			$db = $this->sgbd->connexion_sgbd();
			$sql = "UPDATE sdg_contact SET role_contact=:v1 WHERE id_contact=:v0";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v0",$id_contact);
			$stmt -> bindParam(":v1",$role_contact);
			$db -> beginTransaction();
			$stmt -> execute();
			$db -> commit();
			$db = null;
		}
		catch(PDOException $e){
			$db -> rollback();
			$db = null;
			echo "Echec : " . $e -> getMessage();
		}
	}
	
	public function modifier_profil($id_contact,$prenom_contact,$nom_contact,$unmot) {
		try {
			$db = $this->sgbd->connexion_sgbd();
			$sql = "UPDATE feg_contact SET prenom_contact=:v1,nom_contact=:v2,mdp_contact=:v4 WHERE id_contact=:v0";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v0",$id_contact);
			$stmt -> bindParam(":v1",$prenom_contact);
			$stmt -> bindParam(":v2",$nom_contact);
			$stmt -> bindParam(":v4",$unmot);
			$db -> beginTransaction();
			$stmt -> execute();
			$db -> commit();
			$db = null;
		}
		catch(PDOException $e){
			$db -> rollback();
			$db = null;
			echo "Echec : " . $e -> getMessage();
		}
	}
	
public function detail_contact_complet($id_contact) {
	try {	
		$db = $this->sgbd->connexion_sgbd();	
		$sql = "SELECT * FROM feg_contact where id_contact=:v0 ";
		$stmt = $db -> prepare($sql);
		$stmt -> bindParam(":v0",$id_contact);
		$stmt -> execute();
		$enreg = $stmt->fetch(PDO::FETCH_BOTH);
		$c=new contact($enreg[0],$enreg[1],$enreg[2],$enreg[3],$enreg[4],$enreg[5]);
		$db = null;
		return $c;
		}
		catch(Exception $e){
		$db = null;
		echo $e -> getMessage();
	}
}
	
	
public function recuperer_compte($email_contact,$mdp_contact) {
	try{
		$db = $this->sgbd->connexion_sgbd();
		$sql = "SELECT * FROM feg_contact where email_contact=:v3 and mdp_contact=:v4 ";
		$stmt = $db -> prepare($sql);
		$stmt -> bindParam(":v3",$email_contact);
		$stmt -> bindParam(":v4",$mdp_contact);
		$stmt -> execute();
		$enreg = $stmt->fetch(PDO::FETCH_BOTH);
		$c=new contact($enreg[0],$enreg[1],$enreg[2],$enreg[3],$enreg[4],$enreg[5]);
		$db = null;
		return $c;
		}
		catch(Exception $e){
		$db = null;
		echo $e -> getMessage();
	}
}

public function lister_contact_complet($etat_contact=NULL,$ordre=NULL,$tri=NULL) {
	try {	
		if (is_null($etat_contact)) {
			$critere_etat="";
		} else{
			
				$critere_etat= " AND role_contact=$etat_contact ";
			
		}
		if (is_null($ordre)) {
			$critere_ordre=" ORDER BY nom_media ASC ";
		} else{
			$critere_ordre=" ORDER BY $ordre $tri ";
		}		

		$db = $this->sgbd->connexion_sgbd();		
		$sql = "SELECT * FROM feg_contact ";
		$stmt = $db -> prepare($sql);
		$stmt -> execute();
		while ($enreg = $stmt->fetch(PDO::FETCH_NUM)) { 
		$c=new contact($enreg[0],$enreg[1],$enreg[2],$enreg[3],$enreg[4],$enreg[5]);
		$tab_c[]=$c;
		}
		$db = null;
		if (ISSET($tab_c)) {
			return $tab_c;		
		}
	}
	catch(Exception $e){
		$db = null;
		echo $e -> getMessage();
	}
}

public function supprimer($id_contact) {
		try {		
			$db = $this->sgbd->connexion_sgbd();
			$sql = "DELETE FROM sdg_contact where id_contact=:v0";
		
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v0",$id_contact);
			$db -> beginTransaction();
			//$stmt -> execute();
			echo $id_contact;
			$db -> commit();
			$db = null;
		}
		catch(PDOException $e){
			$db -> rollback();
			$db = null;
			throw new mediacap_exception("ERREUR_SUPPRESSION_DONNEES");
		}
	}

	
}
?>