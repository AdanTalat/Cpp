#include <iostream>
using namespace std;
int main(){
    cout<<"Enetr 5 numbers: ";
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    int arr[5]={a,b,c,d,e};
    int largest = arr[0];
    int smallest=arr[4];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    for (int i = 0; i < 5; i++) {
        if (arr[i] <smallest) {
           smallest = arr[i];
        }
    }
    cout << "The largest number is: " << largest << endl;
    cout << "The smallest number is: " << smallest << endl;
}
