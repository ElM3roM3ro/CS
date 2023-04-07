**************************************
*
* Name: Victor Peralta
*
* Date: 02/20/2023
* 
*
* Program description: This assembly program generates the Nth number in the Fibonacci sequence. (range 1-255)
*
* Pseudocode:
*
*	unsigned int N = 10;
*	unsigned int result;
*	unsigned int I = 1;
* 	unsigned int first = 1;
* 	unsigned int second;
*	unsigned int increment =1;
*
*
* 	result =0;
*
*	second = 0;
*
*
*	do{
*				result = second + first;
*				first = second;
*				second = result;
*				I += increment;
*	}while(N>=I);
*
*
**************************************

* start of data section

				ORG 			$B000
N      			FCB    		10

				ORG 			$B010
RESULT  			RMB     		2
* define any other variables that you might need here
I				FDB 			$0001					I is loop counter, starting at a 1 to maintain the first 2 numbers of our sequence.
FIRST				FDB			$0001					First denotes the F(sub)N-2 number in our sequence. Initilized to 1 in order to achieve first two numbers in the sequence.
SECOND  			RMB			2					Second denotes the F(sub)N-1 number in our sequence. This number will later be set to 0 before any calculations are made.
INCREMENT			FDB			$0001					This variable will be used to add an increment to I later. (in this case, we increment by 1)
				ORG $C000
* start of your program
				CLR			RESULT				result = 0;
			  	CLR			RESULT+1
				CLR			SECOND				second = 0;
				CLR			SECOND+1				Assign variables that havent already been initilized to 0. Making sure to set both bytes of each.
DO				LDAB			SECOND+1				Loading the D register with the value of second, as we want to add FIRST to it later
				LDAA			SECOND
				ADDD			FIRST
				STD			RESULT				result=first+second. Storing the sum of 1st and 2nd into result so we know what the fibonacci sequence number is.
				LDAB			SECOND+1				Loading D register with Second again, but this time we will simply store the contents later in FIRST
				LDAA			SECOND
				STD			FIRST					first = second;
				LDAB 			RESULT+1				Loading D register with the contents of RESULT, so we can store them into SECOND later.
				LDAA			RESULT
				STD			SECOND				second=result;
				LDD			I
				ADDD			INCREMENT				I+=increment; This incrents the loop counter so we dont loop infinitely.
				STD 			I
UNTIL				LDAB			N					Load in N into d register, since it is a one byte variable. (makes it easier to compare to 2 byte variable later.
				CLRA
				CPD			I					Comparing our loop variable to N to see if the following branch will be taken.
				BHS			DO					while(N>=I);  Take branch only if N >= I. If not, we ENDDO
ENDDO 	STOP
