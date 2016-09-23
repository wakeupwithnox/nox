<?php
/******************************************************
* �2006 copyrights by RE-Desgin (www.re-design.de)   *
* Author: Enrico Reinsdorf (enrico@.re-design.de)    *
* Modified: 2006-01-16                               *
******************************************************/

class iniParser {
    
    var $_iniFilename = '';
    var $_iniParsedArray = array();
    
    /**
    *  erstellt einen mehrdimensionalen Array aus der INI-Datei
    **/
    function iniParser( $filename )
    {
        $this->_iniFilename = $filename;
        if($this->_iniParsedArray = parse_ini_file( $filename, true ) ) {
            return true;
        } else {
            return false;
        }
    }
    
    /**
    * gibt die komplette Sektion zur�ck
    **/
    function getSection( $key )
    {
        return $this->_iniParsedArray[$key];
    }
    
    /**
    *  gibt einen Wert aus einer Sektion zur�ck
    **/
    function getValue( $section, $key )
    {
        if(!isset($this->_iniParsedArray[$section])) return false;
        return $this->_iniParsedArray[$section][$key];
    }
    
    /**
    *  gibt den Wert einer Sektion  oder die ganze Section zur�ck
    **/
    function get( $section, $key=NULL )
    {
        if(is_null($key)) return $this->getSection($section);
        return $this->getValue($section, $key);
    }
    
    /**
    * Seta um valor de acordo com a chave especificada
    **/
    function setSection( $section, $array )
    {
        if(!is_array($array)) return false;
        return $this->_iniParsedArray[$section] = $array;
    }
    
    /**
    * setzt einen neuen Wert in einer Section
    **/
    function setValue( $section, $key, $value )
    {
        if( $this->_iniParsedArray[$section][$key] = $value ) return true;
    }
    
    /**
    * setzt einen neuen Wert in einer Section oder eine gesamte, neue Section
    **/
    function set( $section, $key, $value=NULL )
    {
        if(is_array($key) && is_null($value)) return $this->setSection($section, $key);
        return $this->setValue($section, $key, $value);
    }
    
    
    /**
    * sichert den gesamten Array in die INI-Datei
    **/
    function save( $filename = null )
    {
        if( $filename == null ) $filename = $this->_iniFilename;
        if( is_writeable( $filename ) ) {
            $SFfdescriptor = fopen( $filename, "w" );
            foreach($this->_iniParsedArray as $section => $array){
                fwrite( $SFfdescriptor, "[" . $section . "]\n" );
                foreach( $array as $key => $value ) {
                    fwrite( $SFfdescriptor, "$key = $value\n" );
                }
                fwrite( $SFfdescriptor, "\n" );
            }
            fclose( $SFfdescriptor );
            return true;
        } else {
            return false;
        }
    }
    
/**
    * 
    **/
    
    function liste_data_lang($section)
    {
    	$lessections = explode(',',$section);
    	$nb_section = count($lessections);
    	foreach ($lessections as $lasection) {
    		$valeur = array_keys($this->get($lasection));
    		$nb_valeur = count($valeur);
    		for ($i=0;$i<$nb_valeur;$i++) {
    			$nom_contance=strtoupper($valeur[$i]);
    			$valeur_contance=$this->get($lasection,$valeur[$i]);
    			define($nom_contance,$valeur_contance) ;
    		}
    	}
    		
    }
    
    
    

}
?> 