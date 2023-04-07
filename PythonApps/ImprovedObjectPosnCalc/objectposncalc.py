#Challange 3: Improved Object Position Calculation
#Victor Peralta

do_calculation = True       #initialize flag to True
while(do_calculation):      #Loop as long as user wants
    #Get user input
    while(True):        #loop until valid user input is recieved
        try:
            initial_pos = float(input('Enter your intitial position as a decimal value: '))
        except ValueError:
            print('Invalid input. Only numerical values are valid. ')
        else:
            break 
    while(True):
        try:
            initial_vel = float(input('Enter your initial velocity as a decimal value: '))
        except ValueError:
            print('Invalid input. Only numerical values are valid. ')
        else:
            break
    while(True):
        try:
            acceleration = float(input('Enter your acceleration as a decimal value: '))
        except ValueError:
            print('Invalid input. Only numerical values are valid. ')
        else:
            break
    while(True):
        try:
            time_passed = float(input('Enter your time as a non negative decimal value: '))
            if(time_passed <0):     #test if user input is negative. If so, reprompt user for info.
                print('Negative elapsed times are not allowed. Please enter a NON-NEGATIVE decimal value')
                continue
        except ValueError:
            print('Invalid input. Only numerical values are valid. ')
        else:
            break

    #Calculate and print out the finalpos
    final_pos = initial_pos + initial_vel * time_passed + 0.5 * acceleration * time_passed * time_passed
    print("Your final position is: %s" % final_pos)

    #Prompt user if they want to do another calculation.
    another_calculation = input('Do you want to perform another calculation? (y/n): ')
    if(another_calculation != 'y'):     #Test if the user wants to do another calculation
        do_calculation = False;
