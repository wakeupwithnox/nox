#!/usr/bin/env python
# -*- coding: utf-8 -*-

import logging,os,sys
logger = logging.getLogger(__name__)

import json
from urllib.request import urlopen
AppPath = os.getcwd()
sys.path.append(AppPath+"\\component\\ManageSchedule") 
from ManageSchedule import ManageSchedule
from apscheduler.schedulers.background import BackgroundScheduler


class YahooWeather(ManageSchedule):
    """ Classe permettant de récupérer les données météo de yahoo
    à partir des parametres de localisation passés en variable
    - resultformet : format de sortie json ou xml
    - country : pays de la météo
    - town : ville de la météo """
    scriptpath = "./plugins/YahooWeather/"
    url = "https://query.yahooapis.com/v1/public/yql?q="
    yql = "select%20*%20from%20weather.forecast%20where%20u='c'%20and%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text="
    config = json.load(open(scriptpath+'YahooWeather.json','r'))

    def __init__(self):
        """Constructeur de notre classe"""


        self._resultformat = YahooWeather.config['resultformat']
        self._country = YahooWeather.config['country']
        self._town = YahooWeather.config['town']
        self._id_schedule = YahooWeather.config['schedule']['id']
        self._mode_schedule = YahooWeather.config['schedule']['mode']
        self._trigger_schedule = YahooWeather.config['schedule']['trigger']
        self._scheduler = BackgroundScheduler()
        self._output()

    
    def _get_resultformat(self):
        """méthode qui va lire l'attibut 'resultformat' depuis le fichier json du plugin"""
        
        return self._resultformat

    def _get_country(self):
        """méthode qui va lira l'attibut 'country' depuis le fichier json du plugin"""
        
        return self._country

    def _get_town(self):
        """méthode qui va lira l'attibut 'town' depuis le fichier json du plugin"""
        
        return self._town

    def _set_resultformat(self, resultformat):
        """Méthode appelée quand on souhaite modifier le format du résultat"""

        YahooWeather.config["resultformat"] = resultformat
        with open(YahooWeather.scriptpath+'YahooWeather.json', 'w', encoding='utf-8') as f:
            json.dump(YahooWeather.config, f, indent=4)
        self._resultformat = resultformat
    def _set_country(self, country):
        """Méthode appelée quand on souhaite modifier le pays"""

        YahooWeather.config["country"] = country
        with open(YahooWeather.scriptpath+'YahooWeather.json', 'w', encoding='utf-8') as f:
            json.dump(YahooWeather.config, f, indent=4)
        self._country = country
    def _set_town(self, town):
        """Méthode appelée quand on souhaite modifier la ville"""
        
        YahooWeather.config["town"] = town
        with open(YahooWeather.scriptpath+'YahooWeather.json', 'w', encoding='utf-8') as f:
            json.dump(YahooWeather.config, f, indent=4)
        self._town = town

    def _set_data2json(self):
        ''' Méthode appelée quand on souhaite modifier les paramètres du fichier config  '''
        
        pass

        
    def _output (self):
        """méthode qui va construire l'url de la météo de yahoo"""
        url = (YahooWeather.url+YahooWeather.yql+"\""+self._town+","+self._country+"\")&format="+self._resultformat)
        data = json.loads(urlopen(url).read().decode("utf-8"))
        logger.info('Get the weather data')
        weather = {}
        weather['temperature'] = data["query"]['results']['channel']['item']['condition']['temp']
        weather['max_temperature'] = data["query"]['results']['channel']['item']['forecast'][0]['high']
        weather['min_temperature'] = data["query"]['results']['channel']['item']['forecast'][0]['low']
        weather['humidity'] = data["query"]['results']['channel']['atmosphere']['humidity']
        weather['weather_context'] = data["query"]['results']['channel']['item']['condition']['text']
        weather['weather_icon'] = data["query"]['results']['channel']['item']['forecast'][0]['code']
        weather['sunrise'] = data["query"]['results']['channel']['astronomy']['sunrise']
        weather['sunset'] = data["query"]['results']['channel']['astronomy']['sunset']
        with open('weather.json', 'w', encoding='utf-8') as f:
            json.dump(weather, f, indent=4)
            logger.info('Write weather to Json file')
    
    def PersonalSchedule(self):
        self._scheduler.add_job(self._output, trigger=self._mode_schedule,hour=self._trigger_schedule, id=self._id_schedule)
        self._scheduler.start()

        

    resultformat = property(_get_resultformat,_set_resultformat)
    country = property(_get_country,_set_country)
    town = property(_get_town,_set_town)
    



