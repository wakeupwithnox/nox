<?php
class article {
	private $id_article;
	private $id_produit;
	private $id_contact;
	private $sn_article;	

		
	public function get_id_article() {
		return $this -> id_article;
	}	
	public function get_id_produit() {
		return $this -> id_produit;
	}
	public function get_id_contact() {
		return $this -> id_contact;
	}	
	public function get_sn_article() {
		return $this -> sn_article;
	}

	public function set_id_article($id_article) {
		$this -> id_article = $id_article;
	}	
	public function set_id_produit($id_produit) {
		$this -> id_produit =$id_produit;
	}
	public function set_id_contact($id_contact) {
		$this -> id_contact = $id_contact;
	}
	public function set_sn_article($sn_article) {
		$this -> sn_article = $sn_article;
	}	


		
	public function __construct($id_article,$id_produit,$id_contact,$sn_article) {
		$this -> id_article = $id_article;
		$this -> id_produit= $id_produit;
		$this -> id_contact = $id_contact;
		$this -> sn_article= $sn_article;
	}
}
?>
