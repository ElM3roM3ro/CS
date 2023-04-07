/*****************************************
 *  Course:     CS 1050
 *  Semester:   Fall 2021
 *  Date:       August 21,2021
 *  Lab:        Lab 5
 *  Author:     Victor Peralta
 ****************************************/
#include<stdio.h>
#include<math.h>

//Function that returns the factorial of parameter, n
long double factorial(int n)
{
    //Initialize double result, which will be returned out of the function
    long double result=1;
    //Loop through paremeter n, until it reaches 1
    for(int i=n;i>1;i--)
    {
        //multiply i with previous number contained in result
        result*=i;
    }
   //return the result of above for loop(the factorial)
    return  result;
}

//Function that returns e as a double
double calc_e(int i)
{
    //Declare variable, e, which will be used to store the irrational number e
    double e;

    //Store the sum of every factorial needed to get to 10 units of percision
    e = 1 + (1/factorial(1)) + (1/factorial(2)) + (1/factorial(3)) + (1/factorial(4)) + (1/factorial(5)) + (1/factorial(6)) + (1/factorial(7)) + (1/factorial(8)) + (1/factorial(9)) + (1/factorial(10)) + (1/factorial(11)) + (1/factorial(12)) + (1/factorial(13)) + (1/factorial(14));

    //return e out of the function
    return pow(e,i);
}


int main(void)
{
    //Initialize variable e, by calling calc_e function and storing the double into aforementioned variable
    double e = calc_e(2);
    //Print out e, or rather e as a double, with 10 units of percision
    printf("e= %.10lf", e);
}
