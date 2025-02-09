#include <iostream>
using namespace std;
int main() {
    cout << "Let's learn about dynamic memory allocation!\n";
    // Step 1: Dynamically allocate an array of 5 integers
    int* array = new int[5];  
    cout << "Memory allocated for an array of 5 integers.\n";
    for (int i = 0; i < 5; i++) {
        array[i] = i;  // Same as *(array + i) = i;
    }
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << array[i] << "  ";
    }
    delete[] array;
    cout << "\nMemory has been deallocated!\n";
    return 0;
}
