**************************************
*
* Name: Victor Peralta
*
* Date: 03/20/2023
* 
*
* Program description:This program takes values from a table, sends them to a subroutine.
*	This subroutine then calculates the fibonacci seqeuence number for each given values with 4 byte precision.
*	Each of these results is then stored in a result "array"
*
* Pseudocode of Main Program:
*int main()
*{
*    unsigned int * NARR = [1,2,5,10,20,128,254,255, 0];
*    unsigned int * RESARR;	32 bytes
*    unsigned int UPPER;	2 bytes
*    unsigned int LOWER;	2 bytes
*   while(*NARR != 0)
*    {
*	   UPPER = sub(*NARR); (upper 2 bytes of return value)
*	   LOWER = sub(*NARR);	(Lower 2 bytes of return value)
*	   *RESARR(UPPER two bytes) =UPPER;
*        *RESARR(LOWER two bytes) = LOWER;
*	   NARR++;
*        RESARR+= 4 (increment pointer by 4 bytes)
*    }
*
*}
*---------------------------------------
*
* Pseudocode of Subroutine:
*unsigned int sub(unsigned int N)
*{
*    unsigned int RESULT;	(4 bytes)
*    unsigned int COUNT;	(1 byte)
*    unsigned int PREV;		(4 bytes)
*    unsigned int NEXT;		(4 bytes)
*    RESULT=1;
*    PREV=1;
*    COUNT = N;
*
*    while(COUNT>2)
*    {
*        NEXT = RESULT + PREV;
*        PREV = RESULT;
*        RESULT(upper 2 bytes) = NEXT(upper 2 bytes);
*	   RESULT(lower 2 bytes) = NEXT(lower 2 bytes);
*        COUNT--;
*    }
*    return RESULT;		Both the higher and lower bytes of RESULT
*}
*	N is passed by value over the register
*	X register is used for NARR
*	Y register is used for RESARR and Stack pointer(within sub routine)
*	All other variables should reside in memory
**************************************
* start of data section
        ORG $B000
NARR    FCB 1, 2, 5, 10, 20, 128, 254, 255, $00
SENTIN  EQU $00
        ORG $B010
RESARR  RMB 32
* define any variables that your MAIN program might need here
UPPER	RMB 2
LOWER	RMB 2
* REMEMBER: Your subroutine must not access any of the main
* program variables including NARR and RESARR.
        ORG $C000
        LDS #$01FF initialize stack pointer
* start of your main program
        LDX #NARR		unsigned int * NARR
	  LDY #RESARR	unsigned int * RESARR;
WHILE   LDAA 0,X
        CMPA  #SENTIN
        BEQ   ENDWLE	WHILE(*NARR !+ SENTIN)
        LDAA  0,X
	  PSHY		Push address of our result array onto stack so we do not lose this data after sub call
        JSR   SUB		sub(*NARR)

        PULA		Grabbing higher of 2 highest bytes from return value
	  PULB		Grabbing lower of 2 highest bytes from return value
	  STD   UPPER	UPPER = sub(*NARR) (Upper bytes of return value)
	  PULA		Grabbing Higher of 2 lowest bytes from return value
	  PULB 		Grabbing Lower of 2 lowest bytes from return value
	  STD	  LOWER	LOWER = sub(*NARR) (lower bytes of the return value)
	  PULY		Grab RESARR Adress (also "frees" the stack)

	  LDD	  UPPER
	  STD	  0,Y		*RESARR (UPPER TWO BYTES)= UPPER

	  LDD	  LOWER
	  STD	  2,Y		*RESARR (LOWER TWO BYTES) = LOWER

	  LDAB  #4
	  ABY			RESARR += 4  (Move up 4 bytes in the table)
	  INX			NARR++
        BRA   WHILE
ENDWLE
DONE	STOP
* define any variables that your SUBROUTINE might need here
RESULT  RMB 4
PREV  RMB 4
NEXT  RMB 4
COUNT RMB 1
N     RMB 1
        ORG $D000
* start of your subroutine
SUB
      PULY		   	Grab return address before we set up stack
      DES            	Open hole for our 4 byte return variable (call by value over stack)
      DES
      DES
      DES		    	four bytes of holes for return variable
      PSHY			Place return address back on stack
	TSY		  	Y register now holds our pointer to stack which we will use later to populate return param
      STAA N         	Store into local variable (pass by value in register A)
      LDD #0        	clear upper two bytes of RESULT
      STD RESULT
      STD PREV      	clear upper two bytes of PREV
      LDD #1
      STD RESULT+2   	RESULT = 1
      STD PREV+2    	PREV = 1
      LDAA N
      STAA COUNT
WHILE2 LDAA COUNT   COUNT = N
      CMPA #2       while(COUNT>2){
      BLS ENDWHILE2
      LDD RESULT+2
      ADDD PREV+2   NEXT(lower two bytes) = RESULT (lower two bytes)
      STD NEXT+2                          +PREV (lower two bytes);
      LDD RESULT    NEXT(upper two bytes) = RESULT (upper two bytes);
IF    BCC ENDIF     IF_C-Flag ==1)
THEN  ADDD #1       NEXT(upper two bytes) = ++;
ENDIF ADDD PREV
      STD NEXT      NEXT(upper two bytes) += PREV (upper two bytes);
      LDD RESULT
      STD PREV      PREV(upper two bytes) = RESULT (upper two bytes);
      LDD RESULT+2
      STD PREV+2    PREV(lower two bytes) = RESULT (lower two bytes);
      LDD NEXT
      STD RESULT    RESULT(upper two bytes) = NEXT (upper two bytes);
      LDD NEXT+2
      STD RESULT+2  RESULT(lower two bytes) = NEXT (lower two bytes);
      DEC COUNT     COUNT--;
      BRA WHILE2     }
ENDWHILE2
	LDD	RESULT
	STD	2,Y		return RESULT (HIGHER bytes)
	LDD	RESULT+2
	STD	4,Y		return RESULT (LOWER BYTES)
      RTS
