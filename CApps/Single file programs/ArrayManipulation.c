/*****************************************
 * Course:      CS 1050
 * Semester:    Fall 2021
 * Date:        October 8, 2021
 * Lab:         Lab 6
 * Author:      Victor Peralta
 ****************************************/
 #include<stdio.h>
 //Function will take in an array, traverse through and initialtize within a specified index
int initializeArray(int array[],int begin, int end, int increment)
{
    //initialize counter in order to count the amount of elements created
    int elements = 0;
    //Traverse from begining to end by a certain increment to find out how many elements are going to be initialized
    for(int i = begin; i <= end; i +=increment)
    {
        elements++;
    }
    //traverse through the array from sub zero to specified element cap
    for(int x = 0; x < elements; x++)
    {
        array[x] = begin + increment * x;
    }
    //return the amount of elements iniialized
    return elements;
}
//Function does the same as initializeArray fucntion, but inizializes elements of the array in descending order
int initializeDescending(int array[], int begin, int end, int decrement)
{
    int elements = 0;
    //Start from the end and travers until the begining in order to find amount of elements
    for(int i = end; i >= begin; i -=decrement)
    {
        elements++;
    }
    //initilize elements from sub zero to specified element cap
    for(int x = 0; x <  elements; x++)
    {
        array[x] = end - decrement * x;
    }
    //return amount of elements that were initialized
    return elements;
}
//Function mulitplies array at a certain element to another array at the same position.
void MultArrays(int array1[], int array2[],int arrayOut[], int size)
{
    //traverse through both arrays(which share the same size) and assign the product of both array value to a third array position
    for(int x = 0; x < size; x++)
    {
        arrayOut[x] = array1[x] * array2[x];
    }
}
//Function Prints out the containments of each of the 3 arrays passed in, formating them to sit beside each other
void printArrays(int array1[],int array2[],int array3[],int size)
{
    for(int x = 0; x < size; x++)
    {
        printf("Array %d Element %2d  = %2d Array %d Element %2d = %2d Array %d Element %2d = %2d\n", 1,x, array1[x],2,x,array2[x],3,x,array3[x]);
    }
}
int main(void)
{
    //Initialize 3 arrays
    int array1[100], array2[100], array3[100];
    //INitiallize 2 sizes, one to be used by first arrays, and the other
    //to be used for second arrays
    int size = 0, size2 =0;

    printf("First Arrays: \n");
    //Set size to the value returned by initializeArray
    size = initializeArray(array1, 1, 31, 3);

    //Use the value and array returned/initialized from initializeArray
    size = initializeArray(array2, 2, 52, 5);

    //Call MultArrays function
    MultArrays(array1, array2, array3, 11);
   // print all 3 arrays formated to sit beside each other
    printArrays(array1, array2, array3, size);

    printf("Second Arrays: \n");

    //Set size2 to the value returned by initializeDescending
    size2 = initializeDescending(array1,0,22,2);
    //use the value and array returned/initialized from initializeDescending
    size2 = initializeDescending(array2, 7,84,7);
    //Call MultArrays
    MultArrays(array1, array2, array3, 12);
    //Print all 3 arrays formated to sit beside each other
    printArrays(array1, array2, array3, size2);



}
