<?php 

class Device{

    private $parsed_json_device ;
    
    
    private $name;
    private $language;
    private $theme_path;
    private $connexion_mode;    
    private $format_tt;    
    private $format_hour;    
    private $timezone;    

        
    public function get_name() {
        return $this -> name;
    }   
    public function get_language() {
        return $this -> $parsed_json_device->{'language'};
    }
    public function get_theme_path() {
        return $this -> theme_path;
    }   
    public function get_connexion_mode() {
        return $this -> connexion_mode;
    }
    public function get_format_tt() {
        return $this -> format_tt;
    }    
    public function get_format_hour() {
        return $this -> format_hour;
    }    
    public function get_timezone() {
        return $this -> timezone;
    }    
    public function set_name($name) {
        $this -> name = $name;
    }   
    public function set_language($language) {
        $this -> language =$language;
    }
    public function set_id_theme_path($theme_path) {
        $this -> theme_path = $theme_path;
    }
    public function set_connexion_mode($connexion_mode) {
        $this -> connexion_mode = $connexion_mode;
    }   
    public function set_format_tt($format_tt) {
        $this -> format_tt =$format_tt;
    }
    public function set_format_hour($format_hour) {
        $this -> format_hour = $format_hour;
    }
    public function set_timezone($timezone) {
        $this -> timezone = $timezone;
    }   

}


?>