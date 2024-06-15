/*
Universal variable:
  Student ID --> id --> char(string) --> %s
  Full name --> name --> char(string) --> %s
  Birthdate --> dob --> char(string) --> %s
  Algebra grade --> Linear --> float --> %.2f
  Calculus grade --> Calculus --> float --> %.2f
  Basic Programming --> bp --> float --> %.2f
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Task7.h"

//Task 1: Enter student number: The program asks users to enter number of students (maximum 1000)
int main() 
{
    int len;
    int n; //declare variable with data type integer and variable name n
    printf("Enter a number of students (n<1000): \n"); //to enter an integer number as input
    scanf("%d", &n); //use the integer number(input) that user entered to assign for variable named n
    getchar();
    while (1)   //to begin the loop and make sure that the inside loop can always start
    {
        if (n<1 || n>1000) //to check if n <1 or n>1000
        { 
            printf("ERROR! Maximum number of students allowed is 1000.\n");
            printf("Please enter an integer number again:\n"); //when one of two condition of if statement is true, notify the user to re-enter an integer
            scanf("%d", &n); //use the integer number that user re-entered above to assign for variable named n
            continue; //excute the next iteration of the loop until the if statement is not satisfied
        }
        
        printf("The number of student is: %d \n", n); //when the if statement is not satisfied, print n as the number of student in output
        break; //terminate the loop
    }

//Task 2: Enter students’ information: for each student, user type the studentID, full name, birthdate, overall grades of three subjects (Algebra, Calculus, Basic Programming).
    struct Student_Info students[n];       //struct nameDataTable [X] 
    for (int i = 0; i < n; i++)    //i: row number in data table --> i: Student number in the data table
                                  //Because initial student starts at 0 --> i < n (Ex: if i <= n with n = 2 --> output: 3 information of student need to input. While n is total students have in the data table)
                                  //i++: Next to next student after finish run the loop (first i = 0 --> Input the first student name then i = i+1 = 0+1 = 1 --> Input the second student name --> Until i<n)                               
    {
        // ID of the student
        printf ("\nEnter student ID of student %d:\n", i + 1);     //Because array start at 0 but in table can output student 0 --> Use: i + 1 --> Output: student 1
		fgets(students[i].id, sizeof(students[i].id), stdin);
		len = strlen(students[i].id);
		if (students[i].id[len - 1] == '\n')
        {
   		students[i].id[len - 1] = '\0'; // remove the newline character
		}
        fflush (stdin);	
        
        // Name of the student
        printf ("Enter full name of student %d:\n", i + 1);     
        fgets(students[i].name, sizeof(students[i].name), stdin);
		int len = strlen(students[i].name);
		if (students[i].name[len - 1] == '\n')
        {
   		students[i].name[len - 1] = '\0'; // remove the newline character
		}	

        // DoB of the student
        printf ("Enter birthdate of student %d:\n", i + 1);      
        scanf("%d/%d/%d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year);
        getchar();

        //Algebra grade of student
        printf ("Enter Algebra grade of student %d:\n", i + 1);      
        scanf ("%f", &students[i].linear);         
        getchar();

        //Calculus grade of student
        printf ("Enter Calculus grade of student %d:\n", i + 1);      
        scanf ("%f", &students[i].calculus);       
        getchar();

        //Basic Programming grade of student
        printf ("Enter Basic Programming grade of student %d:\n", i + 1);      
        scanf ("%f", &students[i].bp);             
        getchar();
    }


//Task 3: Print student list as a table to screen
    // Print out the list of the student
    printf("\nStudent List\n");
    printf("====================================================================================================\n");
    printf("%-10s%-24s%-15s%-15s%-15s%-15s%s\n", "ID", "Name", "DOB", "Algebra", "Calculus", "Programming", "GPA"); //%-a number s%: After printing that word, spaced a characters
    printf("====================================================================================================\n");

    // Print out the data of the student
    for (int i = 0; i < n; i++)
    {
        students[i].gpa = (students[i].linear*4  +students[i].calculus*4 + students[i].bp*4) / 12; //GPA = ((linear*4) + (calculus*4) + (bp*4))/12
        printf("%-10s%-24s%02d/%02d/%-10d%-15.2f%-15.2f%-15.2f%.2f\n", 
            students[i].id, students[i].name, students[i].dob.day, students[i].dob.month,
            students[i].dob.year, students[i].linear, students[i].calculus, students[i].bp,
            students[i].gpa); 
    }
   

// Task 5: Process grades: find the students having highest GPA, lowest GPA, highest BP grade. 
//Find the students having highest GPA grade
struct Student_Info;  
    // we need to assign the value 0 to variable 'temp1' so that we can assign for both arrays later and connect them
    int temp1 = 0; 
    for (int i = 0; i < n; i++) 
    {
		if (students[temp1].gpa < students[i].gpa) // comparing students[temp1].gpa to students[1].gpa, then to students[2].gpa,..
        {       
			temp1 = i;        // placing higher value to gpa[temp1]
		}
	}
    printf("\nStudent %s has the highest GPA of %.2f\n", students[temp1].name, students[temp1].gpa); 

//Find the students having lowest GPA grade
struct Student_Info;  
    // we need to assign the value 0 to variable 'temp2' so that we can assign for both arrays later and connect them
    int temp2 = 0;      
    for (int i = 0; i < n; i++) 
    {
		if (students[temp2].gpa > students[i].gpa) // comparing students[temp2].gpa to students[1].gpa, then to students[2].gpa,..
        {       
			temp2 = i;        // placing lower value to gpa[temp2]
		}
	}
    printf("\nStudent %s has the lowest GPA of %.2f\n", students[temp2].name, students[temp2].gpa); 

//Find the students having highest Basic Programming grade
struct Student_Info;  
    // we need to assign the value 0 to variable 'temp3' so that we can assign for both arrays later and connect them
    int temp3 = 0;      
    for (int i = 0; i < n; i++) 
    {
		if (students[temp3].bp < students[i].bp) // comparing students[temp3].bp to students[1].bp, then to students[2].bp,..
        {       
			temp3 = i;        // placing higher value to bp[temp3]
		}
	}
    printf("\nStudent %s has the highest Basic Programming of %.2f\n", students[temp3].name, students[temp3].bp); 

//Task 7: Find the oldest student: print the oldest student with his/her ID, fullname, and birthdate

    //Hypothesis that Student 1 is the oldest student
    int oldest_index;
    oldest_index = 0; 
    int oldest_day = students[0].dob.day;   
    int oldest_month = students[0].dob.month;
    int oldest_year = students[0].dob.year;
    for (int i = 0; i < n; i++) 
    {
        if (students[i].dob.year < oldest_year)  //Student i was born earlier than oldest_index --> Student i is the oldest student
        {
        oldest_index = i;
        oldest_year = students[i].dob.year;
        oldest_month = students[i].dob.month;
        oldest_day = students[i].dob.day;
        } 
        else if (students[i].dob.year == oldest_year) 
        {
            if (students[i].dob.month < oldest_month) 
            {
                oldest_index = i;
                oldest_year = students[i].dob.year;
                oldest_month = students[i].dob.month;
                oldest_day = students[i].dob.day;
            } 
            else if (students[i].dob.month == oldest_month) 
            {
                if (students[i].dob.day < oldest_day) 
                {
                    oldest_index = i;
                    oldest_year = students[i].dob.year;
                    oldest_month = students[i].dob.month;
                    oldest_day = students[i].dob.day;
                }
            }
        }
    }  
    printf("\nThe oldest student with id %s - %s is and was born on %d/%d/%d.\n",students[oldest_index].id, students[oldest_index].name, students[oldest_index].dob.day, students[oldest_index].dob.month, students[oldest_index].dob.year); 



//Task 4: Print student list as a table to a text file
// Open the file for writing
FILE *fp;
fp = fopen("student_list.txt", "w");

// Print out the list header of the student to file
fprintf(fp, "ID\t\t\tName\t\t\t\tDOB\t\t\t\tAlgebra\t\t\tCalculus\t\tProgramming\t\tGPA\n");

// Print the data of the student to file
for (int i = 0; i < n; i++) 
    {
        fprintf(fp, "%-10s%-20s%02d/%02d/%-13d%-15.2f%-15.2f%-15.2f%.2f\n", 
            students[i].id, students[i].name, 
            students[i].dob.day, students[i].dob.month,students[i].dob.year, 
            students[i].linear, students[i].calculus, students[i].bp,
            students[i].gpa);
    }

// Close the file
fclose(fp);
printf("\nStudent list printed to file student_list.txt.\n");

    

//Task 6: Print out student lastName
struct Student_Info;      
    for (int i = 0; i < n; i++)    
    {
        char* lastWord = strrchr(students[i].name, ' ');
        char* last_name = strtok(students[i].name, " ");
        if (lastWord != NULL) 
        {
            lastWord++; 
        } 
        else 
        {
            lastWord = students[i].last_name; 
        }
        printf("\nLast name of student %d: %s\n", i +1, last_name);
        printf("Last word in name of student %d: %s\n", i +1, lastWord);
    }
    return 0; //report the program finised and return value 0
} 
