<?php
require_once ("classes/produit.inc");

class gestion_produit {

	private $sgbd;
	
	public function __construct() {
		$this->sgbd = new gestion_sgbd();
	}
	
	public function ajouter($nom_produit,$reference_produit) {
		try {		
			$db = $this->sgbd->connexion_sgbd();
			$sql = "INSERT INTO feg_produit (nom_produit,reference_produit) VALUES 
			(:v1,:v2)";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v1",$nom_produit);
			$stmt -> bindParam(":v2",$reference_produit);
			$db -> beginTransaction();
			$stmt -> execute();
			$id_produit=$db->lastInsertId();
			$db -> commit();
			$db = null;
			return $id_produit;
		}
		catch(PDOException $e){
			$db -> rollback();
			$db = null;
			echo "Echec : " . $e -> getMessage();
		}
	}

	
	public function modifier_produit($id_produit,$nom_produit,$reference_produit) {
		try {
			$db = $this->sgbd->connexion_sgbd();
			$sql = "UPDATE feg_produit SET nom_produit=:v1,reference_produit=:v2 WHERE id_produit=:v0";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v0",$id_produit);
			$stmt -> bindParam(":v1",$nom_produit);
			$stmt -> bindParam(":v2",$reference_produit);
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
	
public function detail_produit($id_produit) {
	try {	
		$db = $this->sgbd->connexion_sgbd();	
		$sql = "SELECT * FROM feg_produit where id_produit=:v0 ";
		$stmt = $db -> prepare($sql);
		$stmt -> bindParam(":v0",$id_produit);
		$stmt -> execute();
		$enreg = $stmt->fetch(PDO::FETCH_BOTH);
		$c=new produit($enreg[0],$enreg[1],$enreg[2]);
		$db = null;
		return $c;
		}
		catch(Exception $e){
		$db = null;
		echo $e -> getMessage();
	}
}
	
	
public function lister_produit_complet() {
	try {	
		$db = $this->sgbd->connexion_sgbd();		
		$sql = "SELECT * FROM feg_produit ";
		$stmt = $db -> prepare($sql);
		$stmt -> execute();
		while ($enreg = $stmt->fetch(PDO::FETCH_NUM)) { 
		$c=new produit($enreg[0],$enreg[1],$enreg[2]);
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

public function supprimer($id_produit) {
		try {		
			$db = $this->sgbd->connexion_sgbd();
			$sql = "DELETE FROM sdg_produit where id_produit=:v0";
		
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v0",$id_produit);
			$db -> beginTransaction();
			//$stmt -> execute();
			echo $id_produit;
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