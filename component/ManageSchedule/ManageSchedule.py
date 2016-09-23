import os, datetime, sys

from apscheduler.schedulers.background import BackgroundScheduler
from component.ManageObject.ManageObject import ManageObject
from component.Device.Device import Device

class ManageSchedule(ManageObject,Device):
    
    def __init__(self):
        """Constructeur de notre classe"""
        self._timezone = Device.config['timezone']
        self._connexion_mode = Device.config['connexion_mode']
        self._scheduler = ''
        self._DateToCompare = ''
        self._Now = ''
        self.DateFileModification =''
        
    def _Get_Timezone (self):
        return self._timezone
    
    def _Set_Scheduler_With_Timezone (self,_timezone):
        self._scheduler = BackgroundScheduler(timezone=_timezone,replace_existing=True)

    def _Set_DateToCompare(self):
        self._DateToCompare = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        
    def _Get_DateFileModification(self,file):
        return datetime.datetime.fromtimestamp(os.stat(file).st_mtime).strftime('%Y-%m-%d %H:%M:%S')
    
    def LaunchSchedule(self,):
        self._Set_Scheduler_With_Timezone(self._timezone)
        self.DefaultJob()
        self._scheduler.start()  
        
    def updateSchedule(self,_file,_state,_type,id_sched):
        if self._DateToCompare =='':
            self.UpdateObject(_file,_state,_type)
            self._Set_DateToCompare()
        if self._DateToCompare > self._Get_DateFileModification(_file):
            print('la date a comparer est plus grande je ne fais rien')
        else:
            print('la date a comparer est plus petite je  fais qqchose')
            self._scheduler.reschedule_job(id_sched, trigger='cron', minute='*/1')
            self.UpdateObject(_file,_state,_type)      
            self._Set_DateToCompare()
            self._scheduler.reschedule_job(id_sched, trigger='cron',second='*')     
                
    def DefaultJob(self):
        self._scheduler.add_job(self.updateSchedule,args=['main.json','enable','component','sched_component'], trigger='cron', second='*',id='sched_component')
        self._scheduler.add_job(self.updateSchedule,args=['main.json','enable','plugins','sched_plugin'], trigger='cron', second='*',id='sched_plugin')
