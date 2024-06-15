struct Date
{
    int day;
    int month;
    int year;
};

struct Student_Info    //Name of data table: Student_Info
{
    int students[1000];
    char id [10];   //char nameVariable [X]; --> X: maximum of characters of variable
    char name [50];
    char last_name [50];
    struct Date dob;
    float linear;
    float calculus;
    float bp;
    float gpa;
};

