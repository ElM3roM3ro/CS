/************************************************************
 * Course:      CS 1050
 * Semester:    Fall 2021
 * Date:        November 19, 2021
 * Lab:         Lab 12
 * Author:      Victor Peralta
 ***********************************************************/
#include<stdio.h>
#include<string.h>

//define movie struct
struct movie{
    char title[45];
    long gross;
    int year;
};
//Prototypes
int readMovies(struct movie films[30], FILE * fp);
void printMovies(struct movie films[30], int count);
void sortMovies(struct movie films[30], int count, int sort);

int main(int argc,char *argv[])
{
    //creat a new array of "movie" struct titled movies
    struct movie movies[30];
    int count;

    FILE * fpIn;

    fpIn =fopen(argv[1],"r");

    //Check if file can be opened
    if(!fpIn)
    {
        printf("Could not open file %s \n", argv[1]);
        return -1;
    }

    //Assign count to the return value of readMovies function
    count = readMovies(movies, fpIn);

    //Close file to prevent data leakage
    fclose(fpIn);

    //Test if there are 3 arguments on the command line
    if(argc == 3)
    {
        //Check if the value of the 3rd argument is equal to "Gross"
        if(strcmp(argv[2], "Gross") == 0)
        {
            printf("Sorted movies: \n");
            //Call sortMovies function, passing in 2 in order to sort by gross
            sortMovies(movies,count,2);

            printMovies(movies,count);
        }
        //check if the value of the 3rd argument is equal to "Year"
        else if(strcmp(argv[2], "Year") == 0)
        {
            printf("Sorted movies: \n");
            //Call sortMovies function, passsing in 3 in order to sort by year
            sortMovies(movies,count,3);
            printMovies(movies,count);
        }
        //check if the value of the 3rd argument is equal to "Title"
        else if(strcmp(argv[2], "Title") == 0)
        {
            printf("Sorted movies: \n");
            //Call sortMovies function, passing in 1 in order to sort by title
            sortMovies(movies,count,1);
            printMovies(movies,count);
        }
        //If non of above strings match with the argument print this error message
        else
        {
            printf("sort_field must be one of \"Title\", \"Gross\" or \"Year\" if specified\n");
        }
    }
    //If the number of arguments is not 3, simply just sort movies by title and print them out
    else
    {
         printf("Sorted movies: \n");
         sortMovies(movies,count,1);
         printMovies(movies,count);

    }

}
//Function takes in an array of struct movie and a file pointer to the file on the command line
int readMovies(struct movie films[30], FILE * fp )
{
    int count = 0;
    //Ensure file is not nulll
    if(NULL != fp)
    {
        //Loop as long as program hasn't reached the end of the file
        while(!feof(fp))
        {
            //Scan a string, long, and int from the file into respective areas of each "film"
            if(0!=fscanf(fp,"%s %ld %d \n",films[count].title,&films[count].gross,&films[count].year))
            {
                count++;
            }
        }
    }
    //return the amount of movies scanned and read
    return count;
}
//Takes in an array of struct movie and an integer representing amount of movies
void printMovies(struct movie films[30], int count)
{
    int x;
    //Print and format respective titles for columns
    printf("%50s \t %10s \t %4s \n","Title", "Gross", "Year");
   //loop through struct
   for(x =0;x<count;x++)
    {
        //Print movies formatted into columns
        printf("%50s \t %10ld \t %4d\n",films[x].title, films[x].gross, films[x].year);
    }
}
//Function takes in array of struct movie, an integer representing amount of movies, and an integer representing what method of sorting the function will use. 1 =  sort by title/ 2 = sort by gross/ 3 = sort by year
void sortMovies(struct movie films[30], int count, int sort)
{

    for(int x = 0; x<count;x++)
    {
        for(int y = 0; y<count-1;y++)
        {
            //Check sort number to determine which method of sort to use
            if(sort == 1)
            {
                //See if string 1 is greater than string 2(accoridng to ascii)
                if(strcmp(films[y].title,films[y+1].title) > 0)
                {
                    //Exchange data in struct if above is true
                    struct movie temp;
                    temp = films[y];
                    films[y] = films[y+1];
                    films[y+1] = temp;
                }

            }
            else if(sort == 2)
            {
                if( films[y].gross > films[y+1].gross)
                {
                    struct movie temp;
                    temp = films[y];
                    films[y] = films[y+1];
                    films[y+1] = temp;
                }
            }
            else if(sort ==3)
            {
                if(films[y].year > films[y+1].year)
                {
                    struct movie temp;
                    temp = films[y];
                    films[y] = films[y+1];
                    films[y+1] = temp;
                }
            }

        }
    }

}
