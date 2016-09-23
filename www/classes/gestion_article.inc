<?php
require_once ("classes/article.inc");

class gestion_article {

	private $sgbd;
	
	public function __construct() {
		$this->sgbd = new gestion_sgbd();
	}
	
	public function ajouter($id_produit,$id_contact,$sn_article) {
		try {		
			$db = $this->sgbd->connexion_sgbd();
			$sql = "INSERT INTO feg_article (id_produit,id_contact,sn_article) VALUES 
			(:v1,:v2,:v3)";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v1",$id_produit);
			$stmt -> bindParam(":v2",$id_contact);
			$stmt -> bindParam(":v3",$sn_article);
			$db -> beginTransaction();
			$stmt -> execute();
			$id_contact=$db->lastInsertId();
			$db -> commit();
			$db = null;
			return $id_article;
		}
		catch(PDOException $e){
			$db = null;
			echo "Echec : " . $e -> getMessage();
		}
	}

	public function modifier($id_produit,$id_contact,$sn_article) {
		try {
			$db = $this->sgbd->connexion_sgbd();
			$sql = "UPDATE feg_article SET id_produit=:v1,id_contact=:v2,sn_article=:v3 WHERE id_article=:v0";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v0",$id_article);
			$stmt -> bindParam(":v1",$id_produit);
			$stmt -> bindParam(":v2",$id_contact);
			$stmt -> bindParam(":v3",$sn_article);
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

	public function lier_contact($sn_article,$id_contact) {
		try {
			$db = $this->sgbd->connexion_sgbd();
			$sql = "UPDATE feg_article SET id_contact=:v1 WHERE sn_article=:v0";
			$stmt = $db -> prepare($sql);
			$stmt -> bindParam(":v0",$sn_article);
			$stmt -> bindParam(":v1",$id_contact);
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
	
public function detail_article($id_article) {
	try {	
		$db = $this->sgbd->connexion_sgbd();	
		$sql = "SELECT * FROM feg_article where id_article=:v0 ";
		$stmt = $db -> prepare($sql);
		$stmt -> bindParam(":v0",$id_article);
		$stmt -> execute();
		$enreg = $stmt->fetch(PDO::FETCH_BOTH);
		$c=new contact($enreg[0],$enreg[1],$enreg[2],$enreg[3]);
		$db = null;
		return $c;
		}
		catch(Exception $e){
		$db = null;
		echo $e -> getMessage();
	}
}
	
	
public function lister_article($id_produit,$sn_article) {
	try {

		if ($id_produit!= NULL ) {
			
			$critere_idproduit=" AND id_produit=$id_produit ";
		} else {
			$critere_idproduit="";
		}
		if ($sn_article!= NULL ) {
			$critere_snarticle=" AND sn_article='$sn_article' ";
		} else {
			$critere_snarticle="";
		}
		$db = $this->sgbd->connexion_sgbd();		
		$sql = "SELECT * FROM feg_article where 1  $critere_idproduit $critere_snarticle ";
		$stmt = $db -> prepare($sql);
		$stmt -> execute();
		while ($enreg = $stmt->fetch(PDO::FETCH_NUM)) { 
		$a=new article($enreg[0],$enreg[1],$enreg[2],$enreg[3]);
		$tab_a[]=$a;
		}
		$db = null;
		if (ISSET($tab_a)) {
			return $tab_a;		
		}
	}
	catch(Exception $e){
		$db = null;
		echo $e -> getMessage();
	}
}

public function lister_article_complet($id_contact) {
	try {
		if ($id_contact!= NULL ) {
				
			$critere_idcontact=" AND id_contact=$id_contact ";
		} else {
			$critere_idcontact="";
		}

		$db = $this->sgbd->connexion_sgbd();
		$sql = "SELECT * FROM feg_article,feg_produit where feg_article.id_produit=feg_produit.id_produit $critere_idcontact  ";
		$stmt = $db -> prepare($sql);
		$stmt -> execute();
		while ($enreg = $stmt->fetch(PDO::FETCH_NUM)) {
			$a=new article($enreg[0],$enreg[1],$enreg[2],$enreg[3]);
			$tab_a[]=$a;
		}
		$db = null;
		if (ISSET($tab_a)) {
			return $tab_a;
		}
	}
	catch(Exception $e){
		$db = null;
		echo $e -> getMessage();
	}
}

public function supprimer($id_article) {
		try {		
			$db = $this->sgbd->connexion_sgbd();
			$sql = "DELETE FROM feg_article where id_article=:v0";
		
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
		}
	}

	
}
?>