#!/usr/bin/env python
# -*- coding: utf-8 -*-

import logging
logger = logging.getLogger(__name__)

import json

class ManageObject():
    """Classe pour la gestion des plugins"""
    def __init__(self):
        """Constructeur de notre classe"""
        jsonfile = ""

        
    def UpdateObject(self, jsonfile,state,type):
        """Création des instances de class"""
        data = json.load(open(jsonfile))
        import os,sys
        AppPath = os.getcwd()
        for key, value in dict.items(data[type][state]):
            for cle , valeur in value.items():
                sys.path.append(AppPath+"\\"+type+"\\"+key) 
                exec("from "+key+" import "+ key)
                exec(valeur +" = " + key+"()")
        if self._connexion_mode < 2 and type == "plugins":
            exec(valeur+".PersonalSchedule()")
        else:
            print("yahoo weather mode safe")
        return
        