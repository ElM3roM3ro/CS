#####################################################################
#   Number Stats 2
#   Victor Peralta 
#    This program reads a series of integer numbers from a file and
#   determines and displays the name of file, sum of numbers, count
#   of numbers, average of numbers, maximum value, minimum value,
#   and range, median and mode of values.
#####################################################################

#This functions asks the user for the name of a file, and returns the name
def get_file_name():  
    file_name = 0
    while(True):
        try:
            file_name = input('What is the name of your file? (please use .txt) ')
        except:
            print('Something went wrong. Please use (.txt).')
            continue
        else:
            break
    return file_name

#This function opens a file, alerts the user if there was an error opening/Reading.
#if the file is opened, the function returns a list of the numbers within file.
def get_numbers(file_path):
    f = None
    numbers = []
    try:
        f = open(file_path, "r")
    except:
        print("An error occured when trying to open",file_path)
    else:
        numbers = f.readlines()
        f.close()
    return numbers

#This function sums up the values in a given list, and returns the sum
def get_sum(number_list):
    total =0
    for num in number_list:
        total += int(num)
    return total

#This function returns the number of values in a given list
def get_count(number_list):
    return len(number_list)

#This function returns an average, given the sum and amount of numbers
def get_average(numbers_sum, count):
    return float(numbers_sum / count)

#This function returns the maximum number in a given list
def get_max_value(numbers_list):
    return max(numbers_list, key=int)

#This function returns the minimum number in a given list
def get_min_value(numbers_list):
    return min(numbers_list, key=int)

#This function returns the range of numbers, given a min and max
def get_range(numbers_min, numbers_max):
    return int(numbers_max - numbers_min)

#This function calculates and returns the median value for the provided list. (also accounts for odd count lists)
def get_median(numbers_list):
    numbers_list.sort(key=int)
    median = 0;
    count = len(numbers_list)
    index = count // 2
    if(count % 2 != 0):
        median = int(numbers_list[index])
        
        return median
    else:
        sum_middle = int(numbers_list[index-1]) + int(numbers_list[index])
        avg = float(sum_middle / 2)
        return avg
    median = int(numbers_list[0])
    return median

#This function calculates and returns the mode(s) in a list
def get_mode(numbers_list):
    number_counts={}
    maximum = 0
    for number in numbers_list:
        if(number in number_counts):
            number_counts[number] += 1
        else:
            number_counts[number] = 1
    for number in number_counts:
        count = number_counts[number]
        if(count > maximum):
            maximum = count
    mode_values = []
    for number in number_counts:
        count = number_counts[number]
        if(count == maximum):
            mode_values.append(int(number))
    return mode_values

#This function produces output for this challange
def produce_output(file_name, sum_num, count, avg, minimum, maximum, range_num, median, mode):
    print("File name:", file_name)
    print("Sum:",sum_num)
    print("Count:",count)
    print(f"Average: {avg}")
    print("Maximum:",maximum)
    print("Minimum:",minimum)
    print("Range:",range_num)
    print("Median:",median)
    print(f"Mode: {mode}")
    
def main():

    while(True):
        file_path = get_file_name()
        numbers = get_numbers(file_path)
        if(numbers):                #test if the list created is empty(denoting that an error had occured with file handling)
            sum_num = get_sum(numbers)
            count = get_count(numbers)
            avg = get_average(sum_num, count)
            maximum = int(get_max_value(numbers))
            minimum = int(get_min_value(numbers))
            range_num = get_range(minimum, maximum)
            median = get_median(numbers)
            mode = get_mode(numbers)
            produce_output(file_path, sum_num,count,avg,minimum,maximum,range_num, median,mode)
        else:
            print(f"There are no numbers in {file_path}. ")
        another_evaluation = input('\nWould you like to evaluate another file of numbers? (y/n) ')
        if(another_evaluation != 'y'):
            break

main()
    
    
