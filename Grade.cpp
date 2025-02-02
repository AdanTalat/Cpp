/*
A professor generates letter grades using the following table.
Percentage 	Grade
0 – 60	F
61 – 70	D
71 – 80	C
81 – 90	B
91 – 100	A
Write a program that accepts a numeric grade and displays the corresponding letter grade.
Last digit 	Modifier
1 – 3 	-
4 – 7	<blank>
8 – 0	+
*/
#include <iostream>
using namespace std;
int main()
{
    cout << "Grade report: ";
    cout << "What is your number? \n";
    int num;
    cin >> num;
    char grade;
    string modifier = "";
    if (num >= 0 && num <= 60)
    {
        cout << "You've got 'F' grade!" << endl;
        return 0;
    }
    else if (num > 60 && num <= 70)
    {
        grade = 'D';
    }
    else if (num > 70 && num <= 80)
    {
        grade = 'C';
    }
    else if (num > 80 && num <= 90)
    {
        grade = 'B';
    }
    else if (num > 90 && num <= 100)
    {
        grade = 'A';
    }
    else
    {
        cout << "Invalid number!" << endl;
        return 1;
    }
    int lastDigit = num % 10;
    if (lastDigit >= 1 && lastDigit <= 3)
    {
        modifier = "-";
    }
    else if (lastDigit >= 8 || lastDigit == 0)
    {
        modifier = "+";
    }
    cout << "You've got '" << grade << modifier << "' grade!" << endl;
    return 0;
}
