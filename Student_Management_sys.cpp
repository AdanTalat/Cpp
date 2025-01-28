/*
1) Create a class named Student with attributes such as name, roll number, and an array of
marks for different subjects.
Declare an array of Student objects to store information for ten students.
Each student has five subjects. Generate random marks (between 0 and 100) for each
subject.
Calculate the average marks for each student and assign a grade based on the following
criteria:
A: 90-100
B: 80-89
C: 70-79
D: 60-69
F: Below 60
Display the details of all students along with their grades.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Student
{
    string name;
    int roll_number;
    int marks[5];
    double average;
    char grade;

public:
    Student(string name, int rollNumber)
    {
        this->name = name;
        this->roll_number = rollNumber;
        generateMarks();    // Generate random marks
        calculateAverage(); // Calculate average marks
        assignGrade();      // Assign grade based on average
    }

    void generateMarks()
    {
         srand(time(0) + roll_number);  // Ensuring different seed for each student
        for (int i = 0; i < 5; i++)
        {
            marks[i] = rand() % 101;
        }
    }

    void calculateAverage()
    {
        int total = 0;
        for (int i = 0; i < 5; i++)
        {
            total += marks[i];
        }
        average = total / 5.0;
    }

    void assignGrade()
    {
        if (average >= 90)
        {
            grade = 'A';
        }
        else if (average >= 80)
        {
            grade = 'B';
        }
        else if (average >= 70)
        {
            grade = 'C';
        }
        else if (average >= 60)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
    }
    void displayDetails()
    {
        cout << "Name: " << name << ", Roll No: " << roll_number << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Average Marks: " << average << ", Grade: " << grade << endl;
        cout << "-------------------------------------" << endl;
    }
};
int main()
{
    // Array of 10 students
    Student students[] = {
        Student("std A", 1),
        Student("std B", 2),
        Student("std C", 3),
        Student("std D", 4),
        Student("std E", 5),
        Student("std F", 6),
        Student("std G", 9),
        Student("std H", 8),
        Student("std I", 9),
        Student("std J", 10)
    };
    for (int i = 0; i < 10; ++i)
    {
        students[i].displayDetails();
    }

    return 0;
}
