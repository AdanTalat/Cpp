#include <iostream>
using namespace std;

int main()
{
    cout << "\t\t\t\t\tArray Diagonal entries only:" << endl;
    int arr[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = 0;
        }
    }
    cout << "Enter values for diagonal entries." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value for " << "(" << i << i << ")" << " diagonal entry ";
        cin >> arr[i][i];
    }
    cout << "The matirx is:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
