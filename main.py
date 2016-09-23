#!/usr/bin/env python
# -*- coding: utf-8 -*-
#----------------------------------------------------#
#              Structure of software                 #
#----------------------------------------------------#
import os,sys
AppPath = os.getcwd()
sys.path.append(AppPath+"\\component\\ManageLog")
from ManageLog import *
setup_logging('./component/ManageLog/ManageLog.json')
logger = logging.getLogger(__name__)
logger.info('Starting the software')
#----------------------------------------------------#
#                    Instance schedule               #
#----------------------------------------------------#
try:
    sys.path.append(AppPath+"\\component\\ManageSchedule")

    from ManageSchedule import ManageSchedule
    try:
        manageschedule = ManageSchedule()
        try:
            manageschedule.LaunchSchedule()
        except:
            logger.debug('La fonction launchSchedule a généré une erreur')
            sys.exit(0)
    except:
        logger.debug('L objet n a pas pu etre instancié')
        sys.exit(0) 
except:
    logger.debug('L import du module ManageSchedule ne semble pas fonctionner')
    sys.exit(0)

try:
    logger.info('Début de la boucle infinie')
    while True:
        pass
except:
    pass