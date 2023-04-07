#include "lab3.h"

int main()
{
	int * a;
	
	a = createCenteredArray(11);
        a[-5] = 4;
	a[-4] = 6;
	a[-3] = 90;
	a[-2] = 8;
	a[-1] = 0;
	a[0] = 2;
	a[1] = 2;
	a[2] = 2;
	a[3] = 2;
	a[4] = 2;
	a[5] = 2;
	
	float avg = 0;
	avg = averageUpperHalf(a,5);
	

	int number = 0;

	number = getAtIndex(a, 11, -5);
	
	printf("The number at index was: %d\n",number);
	printf("The average was: %f\n",avg);
	
	freeCenteredArray(a,11);

	
}
