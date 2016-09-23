import json

class ManageJson:
    """Classe représentant le réveil"""
    def __init__(self,file):
        """Constructeur de notre classe"""
        self.file = file

    def readJson(self):
        """ """
        
    
json_data=open('Bookmarks.txt')
data = json.load(json_data)
