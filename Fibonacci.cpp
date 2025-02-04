#include <iostream>
#include <vector>
using namespace std;
int main() {
    cout << "Enter the number of terms you want in the Fibonacci series:\t";
    int num;
    cin >> num;
    if (num <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }
    vector<int> series(num);
    series[0] = 0;
    if (num > 1) {
        series[1] = 1;
    }
    for (int i = 2; i < num; i++) {
        series[i] = series[i - 1] + series[i - 2];
    }
    cout << "Fibonacci series:\n";
    for (int i = 0; i < num; i++) {
        cout << series[i] << "\t";
    }
    cout << endl;
    return 0;
}
