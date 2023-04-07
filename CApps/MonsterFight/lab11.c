/***************************************************************************
 * CS1050
 * Fall 2021
 * Lab 11
 * By Victor Peralta 
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "fight.h"

//constant for filename

#define FILENAME "monster.csv"

int main(int argc, char * argv[])
{
    // Uncomment the following line if you want to try a sample fight
    // Fight("JimR",21,900,10,"5d6+5","5d12+5","Lar",5,100,5,"1d6","N/A");

    FILE  *fp = fopen(FILENAME, "r");

    char name[256];

    //Define variables for fb(first beast). The name, AC,HP, hit bonus, thier first and second attacks
    char fbName[256];
    int  fbAC, fbHP, fbHB;
    char fbFA[256],fbSA[256];

    //Define variables for sb(second beast). The name, ac,hp, hit bonus, thier first and second attacks
    char sbName[256];
    int sbAC, sbHP, sbHB;
    char sbFA[256],sbSA[256];

    //Check if the file is able to be opened
    if(NULL != fp)
    {
        fgets(name,255,fp);
        name[255]='\0';

      //check if in file annd whether we've reached end of file
       if(fp && !feof(fp))
        {
            //define variables which will be scanned into
            int ac, hp, hitbonus;
            char firstAttack[256], secondAttack[256];

            //loop until the end of file
            while(!feof(fp))
            {
                //Scan all the elements of a monsters.
                if(0!=fscanf(fp,"%d, %d,%d,%[^,],%[^,],%s",&ac,&hp,&hitbonus,firstAttack,secondAttack,name))
                {
                    //Check if current name is equal to the first monster we're looking for.
                    if(strcmp(name,"FrostGiant")== 0)
                    {

                        //simply copy temporary scanned data into first monsters respective varibles
                        fbAC = ac;
                        fbHP = hp;
                        fbHB = hitbonus;
                        strcpy(fbName, name);
                        strcpy(fbFA,firstAttack);
                        strcpy(fbSA,secondAttack);

                    }
                    //Check if current name is equal to the second monster we're looking for.
                    if(strcmp(name,"Ahote")==0)
                    {
                        //Simply copy temporary scanned data into second monster's respective variables
                        sbAC = ac;
                        sbHP = hp;
                        sbHB = hitbonus;
                        strcpy(sbName, name);
                        strcpy(sbFA, firstAttack);
                        strcpy(sbSA, secondAttack);
                    }
                }
            }
        }
        //close file to prevent data leakage
        fclose(fp);
    }
    //if file cannot be opened, print out error message
    else
    {
        printf("File not found: %s", FILENAME);
    }

    //call the fight function, inputing variables obtained earlier for the first and second monster
    Fight(sbName, sbAC, sbHP,sbHB,sbFA,sbSA,fbName,fbAC,fbHP,fbHB, fbFA,fbSA);
}
