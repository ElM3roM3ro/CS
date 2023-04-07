#######################################################################
#   Animal Class
#   VICTOR PERALTA
#   This program contains the Animal class, Mammal sublcass, and bird
#   subclass with attributes and methods.
######################################################################
import random

class Animal:
    def __init__(self, name, animal_type):   #initialize 3 attributes, name, type, and mood
        self.__animal_type = animal_type     #name and animal_type are provided when a Animal object is made
        self.__name = name
        select = random.randint(1,3)
        if(select == 1):        #the type attribute of an Animal object is determineed by a random numeber between 1-3
            self.__mood = "happy"
        elif(select == 2):
            self.__mood = "hungry"
        else:
            self.__mood = "sleepy"
    #This method returns the __animal_type of an Animal object
    def get_animal_type(self):
        return self.__animal_type
    #This method returns the __name of an Animal object
    def get_name(self):
        return self.__name
    #This method returns the __mood of an Animal object
    def check_mood(self):
        return self.__mood


class Mammal(Animal):
    def __init__(self, name, animal_type, hair_color):
        self.__hair_color = hair_color
        #Animal.__init__(self, name, animal_type)
        super().__init__(name, animal_type)
    def get_hair_color(self):
            return self.__hair_color
        
class Bird(Animal):
    def __init__(self, name, animal_type, can_fly):
        self.__can_fly = can_fly
        #Animal.__init__(self, name, animal_type)
        super().__init__(name, animal_type)
    def get_can_fly(self):
        return self.__can_fly


