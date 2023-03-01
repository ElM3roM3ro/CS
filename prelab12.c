#include<stdio.h>
#include<string.h>

#define FILENAME "movies.dat"

struct movie{
    char title[30];
    long grosses[11];
    char years [4];
};
int readMovies(struct movie films[15] , char * FileName);
//void printMovies();
//void sortMovies();
int main(void)
{
    char title[30];
    char grosses[11];
    char years[4];

    struct movie movies[15];

    readMovies(movies, FILENAME);
}

int readMovies(struct movie films[15], char * FileName)
{
    FILE * fp = fopen(FileName,"r");
    int count =0;

    if(NULL !=fp)
    {
        while(!feof(fp))
    :    {
            if(0!=fscanf(fp,"%s %s %s \n", films[count].title, films[count].grosses, films[count].years))
            {
                count++;
            }
        }
        fclose(fp);

    }
    else
    {
        printf("Unable to open file %s\n", FILENAME); 
    }

    return count;
}





