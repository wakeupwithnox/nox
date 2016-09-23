#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyleft GLC

class common:
	
def convert_celcius_to_fahrenheit(pvalue):
	"""
		convert celcius value to fahrenheit value
		parameters:
			pvalue : it is the value to convert
	"""
	return (pvalue * 9 / 5) + 32

def convert_fahrenheit_to_celcius(pvalue):
	"""
		convert fahrenheit value to celcius value
		parameters:
			pvalue : it is the value to convert
	"""
	return (pvalue -32) * 5 / 9

