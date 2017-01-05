#!/usr/bin/env python
# -*- coding: utf-8 -*-

import logging
logger = logging.getLogger(__name__)

class Sensor():
    """ Classe permettant de gérer les données en provenance du spi"""
    
    def __init__(self):
        """Constructeur de notre classe"""
        pass
    
    def _write_json(self):
        logger.info('Write data to Json file')