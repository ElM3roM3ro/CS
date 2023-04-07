#include "lab2.h"

int main() 
{
	FILE * fp;
	fp = fopen("numbers.txt","r");
	
	if(!fp)
	{
		printf("file was not found");
		return -1;
	}

	int * a;
	int size = 0;	

	a = createIntArrayFromFile(fp,&size);

	fclose(fp);
		
	for(int x =0; x< size; x++)
	{
		printf("%d\n", a[x]);
	} 
	
	int * result;
	int elementCondition =1;
	
	elementCondition = lastAddressOf(a, size, &result,39);
	
	printf("The element 74 status: %d. Its last address was %p\n",elementCondition, result);
	
	printf("\n%p\n", a+49);
	freeArray(a);
	
}

