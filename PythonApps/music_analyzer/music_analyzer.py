###################################################################
#   Music Analyzer
#   Victor Peralta
#   This Program prompts the user for a playlist data file from apple
#   music or itunes to analyze. The program then dislpays a report of
#   contents of the file.
#
####################################################################

import csv
#This function asks the user for the name of a file path and returns that name as a string
def get_user_info():  
    info = " "
    while(True):
        try:
            info = input("Please provide the name of your playlist data file: (.csv/.txt) ")
            if(".txt" not in info and ".csv" not in info):      #Ensures user at least submits a .txt/,csv file name
                print("Please enter a .txt or .csv file: ")
                continue
        except:
            print('Something went wrong. Please try again')
            continue
        else:
            break
    return info

#This function takes in the name of a file, opens it, reads the file as a tab delimited file, and puts that reading into a list
#This list is then returned from the function
def load_music(file_path):
    music_list = []
    try:
        with open(file_path, 'r', encoding='utf-16', newline='') as file:
            csv_reader = csv.reader(file, delimiter = '\t')
            for row_of_music_as_string in csv_reader:
                music_list.append(row_of_music_as_string)
    except:
        print(f"An error occured when trying to open {file_path}")

    return music_list

#This function calculates and prints the number of songs for each year within the playlist
def num_songs_in_year(mlist):          
    years = []              #This will hold the different years
    info2 = []              #This will hold all occurences of each year
    for row in mlist:       #traverse throught provided list, in order to populate our lists
        try:
            if(row[16] not in years):       #check for duplicates
                years.append(row[16])     
            info2.append(row[16])           #duplicates included
        except:
            continue
    
    years.remove("Year")
    years.sort()
    years.pop(0)            #Assumes that there was a blank year value in the file. Which is why we remove it from consideration
    info2.remove("Year")    #Both removes of year are just so we don't consider this string in calculations
    
    for year in years:      #Prints the number of songs for each year
        print(f"\nNumber of songs in the year {year}: {info2.count(year)}")

#This function finds the longest song with the greatest Time value in the given list.
#This song(or songs')'s info is then displayed to the user
def find_longest_song(mlist):
    info = []           #This will hold all instances of largest Time values
    largest = 0
    lindex = 0          #This is the index of the last value put into info (-1)
    for row in mlist:
        try:
            if(int(row[11]) >= largest):
               largest = int(row[11])
                  
               info.append(row)
               lindex+=1  
        except:
            continue

    llist = []          # This holds the rows of information that share the greatest values in Time
    llist.append(info[lindex-1])
    for row in info:
        if(row[11] == info[lindex-1]):      #We know that the last index in info is the greatest, but we check if any other song in info shares this Time value
            llist.append(row)   

    iterable = 0
    print(f"Longest song(s) (based on time):")
    for row in llist:
         print(f"Name: {llist[iterable][0]} Artist: {llist[iterable][1]} Time: {largest}")       
         iterable+=1
    print("\n")
#This function finds the shortest song with the least Time value in the given list
#The song's(or songs') info is then displayed to the user
def find_shortest_song(mlist):
    info = []       #This will hold every instance of the smallest value
    smallest = 999999999999999999999
    lindex = 0
    for row in mlist:
        try:
            if(int(row[11]) <= smallest):
               smallest = int(row[11])   
               info.append(row)
               lindex+=1  
        except:
            continue

    slist = []          #This will hold mutiple of songs that hold the same lowest Time value
    slist.append(info[lindex-1])
    for row in info:
        if(row[11] == info[lindex-1]):      #We know the last index of info is the shortest song, but we have to check entire list to see if any other songs have the same value 
            slist.append(row)     
    iterable2 = 0

    print(f"Shortest song(s) (based on time):")
    for row in slist:
         print(f"Name: {slist[iterable2][0]} Artist: {slist[iterable2][1]} Time: {smallest}")       
         iterable2 += 1
    print("\n")

#This function provides: the number of songs, the longest song by Name and
#Artist (list multiple if more than one), the shortest song by Name and Artist (
#list multiple if more than one), of each genre in the given list.
def collect_genre_info(mlist):
    index = 0
    genres = []         #this holds every genre in the list
    info2 = []          #this holds every instance of a genre in the list
    for row in mlist:
        try:
            if(row[9] not in genres):
                genres.append(row[9])
                
            info2.append(row[9])
        except:
            continue
        index+=1
    genres.remove("Genre")
    genres.sort()
    genres.pop(0)               #Assumes that ther is at least one blank genre spot, which is why it is removed
    
    info2.remove("Genre")
    
    for genre in genres:
        print(f"\nNumber of {genre} songs: {info2.count(genre)}")
        songs = []
        for row in mlist:
            if(row[9] == genre):
                songs.append(row)

        find_longest_song(songs)        
        find_shortest_song(songs)       #Calls to functions made earlier

#his function calculates the number of songs that have been played in a given list  
#This value is then returned
def get_num_songs_played(mlist):
    info = []
    for row in mlist:
        info.append(row[25])
    info.sort()
    
    info.pop(len(info)-1)   #Removes the "Plays' column in the first row
    count = 0
    for value in info:
        if(value.isnumeric()):
            count+=1
    return count

#This funciton calculates the number of songs that have not been played in a given list
#This value is then returned
def get_num_songs_not_played(mlist):
    info = []
    for row in mlist:
        info.append(row[25])
    info.sort()
    
    info.pop(len(info)-1)           #Removes the "Plays' column in the first row
    count = 0
    for value in info:
        if(not value.isnumeric()):
            count+=1
    return count
def main():
    while(True):
        file_path = get_user_info()
        mlist = load_music(file_path)
        if(mlist):
            print(f"Numer of songs in {file_path}: {len(mlist)-1}\n")
            num_songs_in_year(mlist)
            print("\n")
            find_longest_song(mlist)
            find_shortest_song(mlist)
            collect_genre_info(mlist)
            count = get_num_songs_not_played(mlist)
            print(f"\nThe amount of songs not played is {count}")
            count2 = get_num_songs_played(mlist)
            print(f"The amount of songs played is {count2}\n")
        another_analyze = input("\nWould you like to analyze another music file?: (y/n) ")
        if(another_analyze != 'y'):
            break

main()
