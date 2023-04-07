**************************************
*
* Name: Victor Peralta
*
* Date: 03/01/23
*
*
* Program description:This assembly program generates the Nth number Fibonacci sequence.
*	It produces a 4 byte answer stored in RESULT. (Unsigned from 1-255)
*
* Pseudocode:
*
*
* unsigned int N = 10; //1 byte variable
* unsigned int RESULT; //4-byte variable
*
* unsigned int COUNT; //1 byte variable
* unsigned int PREV; //4-byte variable
* unsigned int NEXT; //4-byte variable
*
*
* RESULT=1;
* PREV=1;
* NEXT=0;
* COUNT = N;
* while(COUNT>2){
*       NEXT = RESULT + PREV;
*       PREV = RESULT;
*       RESULT = NEXT;
*       COUNT--;
* }
*
* //variables are stored in memory
*
**************************************

* start of data section

	ORG $B000
N       	FCB    	40

	ORG $B010
RESULT  	RMB	      4

* define any other variables that you might need here

COUNT		RMB		1
PREV		RMB		4
NEXT		RMB		4

* start of your program

	ORG  	$C000
	LDAA	#0
	LDAB	#1
	STAA	RESULT+2
	STAB	RESULT+3		RESULT = 1;
	CLR	RESULT
	CLR	RESULT+1

	STAA	PREV+2
	STAB	PREV+3		PREV = 1;
	CLR	PREV
	CLR	PREV+1

	CLR	NEXT			NEXT = 0;
	CLR	NEXT+1
	CLR	NEXT+3
	CLR	NEXT+2

	LDAA	N
	STAA	COUNT		COUNT = N;
WHILE	LDAA	COUNT
	CMPA	#2		while(COUNT>2){
	BLS	ENDWHILE


	LDAB	RESULT+3	 Load the lower 2 bytes of RESULT into A/B registers. Here and subsequent instructions load and manipulate 4 byte data in pairs of 2 bytes. The 2 least signifigant bytes and the 2 most signifigant.
	LDAA	RESULT+2
	ADCB	PREV+3
	ADCA	PREV+2	 Add the lower 2 bytes of PREV into these registers.The carry flag is included so we can maintain a 4 byte result later on
	STAA	NEXT+2
	STAB	NEXT+3	 Store those summed bytes into the lower 2 bytes of NEXT
	LDAB	RESULT+1
	LDAA	RESULT	 Load the upper 2 bytes of RESULT into A/B registers
	ADCB	PREV+1
	ADCA	PREV		 Add with carry the upper 2 bytes of PREV into these registers. (To maintain 4 byte precison as said before)
	STAA	NEXT
	STAB	NEXT+1	NEXT = RESULT + PREV;	Store those summed bytes into the upper 2 bytes of NEXT


	LDAA	RESULT+2
	LDAB	RESULT+3	Load the lower 2 bytes of RESULT into A/B registers
	STAA	PREV+2
	STAB	PREV+3	Store those bytes into the lower 2 bytes of PREV
	LDAB	RESULT+1
	LDAA	RESULT	Load the upper 2 bytes of RESULT into A/B registers
	STAB	PREV+1
	STAA	PREV		PREV = RESULT; Store those bytes into the upper 2 bytes of PREV


	LDAA	NEXT+2
	LDAB	NEXT+3	Load the lower 2 bytes of NEXT into A/B registers
	STAA	RESULT+2
	STAB	RESULT+3	Store those bytes into the lower 2 bytes of RESULT
	LDAB	NEXT+1
	LDAA	NEXT		Load the upper 2 bytes of NEXT into A/B registers
	STAB	RESULT+1
	STAA	RESULT	RESULT = NEXT; Store those bytes into the upper 2 bytes of RESULT

	DEC	COUNT             	COUNT--;
	BRA	WHILE	 	}
ENDWHILE
DONE	STOP
	END
