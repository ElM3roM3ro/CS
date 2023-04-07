#ifndef _UNIVERSITY_H
#define _UNIVERSITY_H


////////////////////////////
// Types
////////////////////////////
typedef int COURSE_ID;

typedef struct _Course
{
    COURSE_ID id;
    char name[256];
    char dept[256];
    int number;
    char instructor_fname[256];
    char instructor_lname[256];
} Course;

typedef int STUDENT_NUMBER;

typedef struct _Student
{
    STUDENT_NUMBER number;
    char fname[256];
    char lname[256];
} Student;

////////////////////////////
// Prototypes
////////////////////////////
Course * GetAllCourses();
Student * GetAllStudents();
void PrintCourses(Course courses[]);
void PrintStudents(Student students[]);

Student * GetStudentsInCourse(COURSE_ID id);
#endif
