#include <stdio.h>
#include "university.h"
#include <string.h>
#include <malloc.h>
/*****************************************************************************
 *   Course:        CS 1050
 *   Semester:      Fall 2021
 *   Date:          Dec 3 2021
 *   Lab:           Lab 13
 *   Author:        Victor Peralta
 *
 *****************************************************************************/

// Stubs for functions you need to implement
Course GetCourseByDeptAndNumber(char * dept, int number)
{
    Course course={-1};

    Course * c = GetAllCourses();

    for(int x=0; x<12; x++)
    {
        if(strcmp(c[x].dept, dept)==0 && c[x].number == number)
        {
            course = c[x];
        }
    }

    return course;
}

Course GetCourseByID(COURSE_ID id)
{
    Course course={-1};

    Course * c = GetAllCourses();

    for(int x=0;x<12;x++)
    {
        if(c[x].id == id)
        {
            course = c[x];
        }

    }

    return course;
}

void PrintCourse(Course course)
{
    if(course.id != -1)
    {
    printf("ID=%d, Name=%s, Dept=%s, Number=%d, Instructor=%s %s",course.id, course.name,course.dept,course.number,course.instructor_fname, course.instructor_lname);
    }
}




// main() - Don't change this
int main(int argc, char * argv[])
{
    Course c;

    printf("Test #1:\n");
    c=GetCourseByID(5);
    PrintCourse(c);

    printf("\nTest #2:\n");
    c=GetCourseByID(11);
    PrintCourse(c);

    printf("\nTest #3:\n");
    c=GetCourseByID(999);
    PrintCourse(c);

    printf("\nTest #4:\n");
    c=GetCourseByDeptAndNumber("CS",1050);
    PrintCourse(c);

    printf("\nTest #5:\n");
    c=GetCourseByDeptAndNumber("STAT",4540);
    PrintCourse(c);

    printf("\nTest #6:\n");
    c=GetCourseByDeptAndNumber("ZZZZZZZZ",1050);
    PrintCourse(c);

    printf("\nTest #7:\n");
    c=GetCourseByDeptAndNumber("CS",999999);
    PrintCourse(c);

  

    return 0;
}
