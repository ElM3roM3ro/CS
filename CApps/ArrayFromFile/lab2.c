#include "lab2.h"

/* createIntArrayFromFile
	This function takes in file pointer, allocates enough memory to hold 
	the contents of this file, and places the contents of the file in a 
	tempory integer array allocated by malloc. Also assigns the size of
	the allocated array into the value pointed to by the size pointer.
	Returns a pointer to the array on success, or NULL on error
*/
int * createIntArrayFromFile(FILE * file, int *size)
{

	//Grab amount of numbers in file from the first element of the file
	//and place it into size
	fscanf(file, "%d", size);
	
	//Define an integer pointer, and allocate the size of however many
	//integers there are in the file and the size of one 
	//integer(which will hold the size of the allocated array).
	int * array;
	array = malloc((*size)*sizeof(int) + sizeof(int));
	
	//Put the size of the allocated array into the zeroth elemement of 
	//the array (to be hidden later using pointer arithmitic)
	array[0] = *size;
 	

	int count = 1;  //Simple variable for loop iteration
	
	//Check to see if malloc failed
	if(array != NULL)
	{	
		//Traverse through the file, assigning all values to our
		//allocated array.
		while(!feof(file))
		{
			if(0!=fscanf(file, "%d", &array[count]))
			{
				count++;
			}
		}
	}
	else
	{
		printf("ERROR: Array could not be allocated.\n");
		return NULL;
	}
	
	return ++array;	//Pre increment pointer to "hide" size of array.
}

/* lastAddressOf
	This function takes an int array pointer and, depending 
	on the query element, finds the last instance of that 
	element within the array. The address of the last instance 
	is placed into the result double pointer.
	Returns 0 if a the element was found or 1 if not.
*/
int lastAddressOf(int *array, int size, int **result, int element)
{
	
	int elementFound = 1;	//Simple "status" variable to be returned
	for(int x = 0;x< size;x++)
	{
		//Simply check if array value matches the element
		if(array[x] == element)
		{
			//Sets "status" to found
			elementFound = 0;
			//Sets the value of the double pointer to the address
			//of the current array value
			*result = array+x;
		}

	}

	return elementFound; 
}

/* freeArray
	This function takes an array pointer and frees the memory allocated 
	to the array.
*/
void freeArray(int *a)
{
	free(--a); // Pre increment int pointer to free originally allocated address
		
}	
