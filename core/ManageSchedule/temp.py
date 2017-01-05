#!/usr/bin/env python
# -*- coding: utf-8 -*-

import logging
logger = logging.getLogger(__name__)

from apscheduler.schedulers.background import BackgroundScheduler




from component.ManageLog.ManageLog import *
from component.ManageSchedule.ManageSchedule import *




class ManageSchedule():
    """ Classe permettant de gérer les schedule
    
    from tzlocal import get_localzone
    tz = get_localzone()
    print(tz)    """

    
    def __init__(self):
        """Constructeur de notre classe"""
        pass

    def test(self):
        """scheduler.add_job(managenetwork.defineConnexionMode ,'interval', seconds=1,id='sched_connexion')
        scheduler.add_job(sensor._write_json ,'interval', seconds=15,id='sched_Sensor')
        scheduler.add_job(weather._output ,'cron',  hour='9,12,15,18,21',id='sched_weather')
        
        sched.add_job(my_job, trigger='cron', second='*') # trigger every second."""
        scheduler.start()