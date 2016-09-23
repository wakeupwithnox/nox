<?php
class produit {
	private $id_produit;
	private $nom_produit;
	private $reference_produit;
	
		
	public function get_id_produit() {
		return $this -> id_produit;
	}	
	public function get_nom_produit() {
		return $this -> nom_produit;
	}
	public function get_reference_produit() {
		return $this -> reference_produit;
	}	


	public function set_id_produit($id_produit) {
		$this -> id_produit = $id_produit;
	}	
	public function set_nom_produit($nom_produit) {
		$this -> nom_produit =$nom_produit;
	}
	public function set_reference_produit($reference_produit) {
		$this -> reference_produit = $reference_produit;
	}


		
	public function __construct($id_produit,$nom_produit,$reference_produit) {
		$this -> id_produit = $id_produit;
		$this -> nom_produit= $nom_produit;
		$this -> reference_produit = $reference_produit;

	}
}
?>
