################################################################################
#   Animal Generator
#   Victor Peralta 
#   This program asks the user what type of animal they make (Mammal or bird)
#   Depending on their answer, the program then prompts additional
#   info about the animal they want to create. It then creates either
#   Mammal or Bird object from the users respective choice. Finally
#   it prints information about the made animals out to the user
#
################################################################################
from Animals import *

#This function returns information obtained from asking a user the provided prompt
def get_info_with_prompt(prompt):  
    info = " "
    while(True):
        try:
            info = input(prompt)
        except:
            print('Something went wrong. Please try again')
            continue
        else:
            break
    return info
#This function creates a new Animal object given a name and the type of animal
def create_new_animal(name, animal_type, sub_type,add_info):
    if(int(animal_type) == 1):
        a = Mammal(name, sub_type, add_info)
    else:
        a = Bird(name, sub_type, add_info)
    return a

#This function creates a list of Animal objects. Animals will continue to be added as long as the user wants
def create_animal_list():
    animals = []
    while(True):
        animal_type = get_info_with_prompt("Would you like to create a mammal or bird? \n1.Mammal \n2.Bird \nWhich would you like to create? ")
        print("\n")
        try:            #Catching any answers that might not be numerical
            if(int(animal_type) == 1):          #test for a mammal
                sub_type = get_info_with_prompt("What type of mammal would you like to create? ")
                name = get_info_with_prompt("What is the mammal's name? ")
                additional_info = get_info_with_prompt("What color is the mammal's hair? ")
            elif(int(animal_type) == 2):        #Tes for a bird
                sub_type = get_info_with_prompt("What type of bird would you like to create? ")
                name = get_info_with_prompt("What is the bird's name? ")
                additional_info = get_info_with_prompt("Can the bird fly? ")
            else:       # if the user entered neither 1 or 2
                print("Please enter a valid number\n")
                continue
        except:
            print("Please enter an integer number\n")
            continue

        animals.append(create_new_animal(name, animal_type, sub_type, additional_info))         #create and add a new object to our list                 
        print("\n")
        another_creation = input("Would you like to add more animals? (y/n) ")
        print("\n")
        if(another_creation != 'y'):
            break
    return animals

#This function prints out information of the list of Animals provided
def print_animal_list(animals):
    print("Animal List: ")
    for animal in animals:
        print(f"{animal.get_name()} the {animal.get_animal_type()} is {animal.check_mood()}")

def main():
    print("Welsome to the animal genreator!")
    print("This program creates animal objects \n")
    animals = create_animal_list()
    print_animal_list(animals)
    

    
main()
