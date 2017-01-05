#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json

class Device():
    """Classe représentant le réveil"""

    scriptpath = "./component/Device/"
    config = json.load(open(scriptpath+'Device.json','r'))

    
    def __init__(self):
        """Constructeur de notre classe
        _connexion_mode =1 lan 2 wlan or 3 wlan_safe"""
        """data = open('device.json')
        x = json.load(data, object_hook=lambda d: Namespace(**d))"""

        self._name = Device.config['name']
        self._language = Device.config['language']
        self._connexionmode = Device.config['connexion_mode']
        self._timezone = Device.config['timezone']
        
    def _get_connexionmode(self):
        """méthode qui va lire l'attibut 'resultformat' depuis le fichier json du plugin"""
        return self._connexionmode
    
    def _get_timezone(self):
        """méthode qui va lire l'attibut 'timezone' depuis le fichier json du plugin"""
        return self._timezone

    def _set_connexionmode(self, connexionmode):
        """Méthode appelée quand on souhaite modifier le format du résultat"""

        Device.config["connexionmode"] = connexionmode
        with open(Device.scriptpath+'Device.json', 'w', encoding='utf-8') as f:
            json.dump(Device.config, f, indent=4)
        self._connexionmode = connexionmode


    connexionmode = property(_get_connexionmode,_set_connexionmode)
    timezone = property(_get_timezone)

