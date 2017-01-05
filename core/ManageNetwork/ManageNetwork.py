#!/usr/bin/env python
# -*- coding: utf-8 -*-

import logging
logger = logging.getLogger(__name__)

import requests
import json

class ManageNetwork():
    """ Classe permettant de gérer les interfaces réseaux"""
    scriptpath = "./component/ManageNetwork/"
    config = json.load(open(scriptpath+'ManageNetwork.json','r'))
    
    def __init__(self):
        """Constructeur de notre classe"""
        self._interface_name_used = ManageNetwork.config['interface_name_used']
        self._interface_name_ethernet = ManageNetwork.config['interface_name_ethernet']
        self._connexion_mode = ManageNetwork.config['connexion_mode']
    
    def testConnexion(self,url='https://www.google.com/', timeout=5):
        try:
            _ = requests.get(url, timeout=timeout)
            return True
        except requests.ConnectionError:
            pass
        return False
    
    def defineConnexionMode(self):
        """Fonction permettant de gérer le mode de connexion : eth0 ou wlan0
        En eth0, la connexion reste active.
        En wlan0, l'utilisateur a le choix entre différent mode
            mode 1 = la connexion est toujours active
            mode 2 = la connexion se connecte si nécessaire
        le mode 0 indique qu'il y a un soucis avec la connexion"""
        if (self._interface_name_used == self._interface_name_ethernet ):
            self._connexion_mode = 1
            logger.debug('Connexion Ethernet')
        else:
            self._connexion_mode = self._connexion_mode
            logger.debug('Connexion Wlan')
            
        return self._connexion_mode