#!/usr/bin/env python
# -*- coding: utf-8 -*-

#----------------------------------------------------#
#              Structure of software                 #
#----------------------------------------------------#
from component.ManageLog.ManageLog import *
from test.datetimetester import MINUTE
setup_logging('./component/ManageLog/ManageLog.json')
logger = logging.getLogger(__name__)
logger.info('Starting the software')

from component.ManageObject.ManageObject import ManageObject
manageobject = ManageObject()

#----------------------------------------------------#
#                   Component                        #
#----------------------------------------------------#
for liste in enumerate(manageobject.InstanceObject("main.json","enable","component")):
    exec(liste[1][0])
    exec(liste[1][1])
    logger.debug('Instance of '+liste[1][1])

#----------------------------------------------------#
#                   Plugins                          #
#----------------------------------------------------#
for liste in enumerate(manageobject.InstanceObject("main.json","enable","plugins")):
    exec(liste[1][0])
    exec(liste[1][1])
    logger.debug('Instance of '+liste[1][1])
    
    
import os
import datetime
import time
from apscheduler.schedulers.background import BackgroundScheduler

class ManageSchedule():
    
    scheduler = BackgroundScheduler(timezone="Europe/Paris")
    def __init__(self):
        """Constructeur de notre classe"""
        self._DateToCompare = ''
        self._Now = ''
        self.DateFileModification =''
        
    def _Set_DateToCompare(self):
        self._DateToCompare = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        
    def _Get_DateFileModification(self,file):
        return datetime.datetime.fromtimestamp(os.stat(file).st_mtime).strftime('%Y-%m-%d %H:%M:%S')
        
    def LaunchSchedule(self):
        scheduler.start()
        
    def CompareDate(self):
        file = 'main.json'
        if self._DateToCompare =='':
            print('je lance la fonction des plugins')
            self._Set_DateToCompare()
            print(self._DateToCompare)
        if self._DateToCompare > self._Get_DateFileModification(file):
            print('la date a comparer est plus garnde je ne fais rien')
        else:
            print('la date a comparer est plus petite je  fais qqchose')
            scheduler.reschedule_job('sched_plugin', trigger='cron', minute='*/1')
            self._Set_DateToCompare()
            scheduler.reschedule_job('sched_plugin', trigger='cron',second='*')
            

    def AddJob(self):
        #scheduler.add_job(self.CompareDate, trigger='cron', second='*',id='sched_plugin')
        if weather:
            scheduler.add_job(weather._output ,id='sched_weather')
            time.sleep(1)
            scheduler.reschedule_job('sched_weather',trigger='cron',  minute=2)

manageschedule = ManageSchedule()
scheduler = BackgroundScheduler(timezone="Europe/Paris",replace_existing=True)
manageschedule.AddJob()
manageschedule.LaunchSchedule()

try:
    # This is here to simulate application activity (which keeps the main thread alive).
    while True:
        pass
except:
    pass