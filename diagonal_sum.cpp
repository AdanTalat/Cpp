#include <iostream>
using namespace std;

void fun()
{
    int a[4][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }
}

void lef_dia()
{
    int a[4][4];
    int res=0;
    for (int i = 0; i <= 3; i++)
    {

        res += a[i][i];
    }
    cout << "The sum of left diagonal is: " << res;
    cout << endl;
}
void ri8_dia()
{
    int a[4][4];
    int res=0;

    for (int i = 0; i <= 3; i++)
    {

        res += a[i][3 - i];
    }
    cout << "The sum of right diagonal is: " << res;
    cout << endl;
}
int main()
{
    cout << "Matrix:\n";
    fun();
    lef_dia();
    ri8_dia();
}
