#include <iostream>
using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(int binary) {
    int decimal = 0, base = 1, remainder;
    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32];
    int index = 0;
    if (decimal == 0) {
        cout << 0;
        return;
    }
    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }
    // Print binary in reverse order
    for (int i = index - 1; i >= 0; i--) {
        cout << binary[i];
    }
}

// Function to add two binary numbers
void addBinary(int bin1, int bin2) {
    int num1 = binaryToDecimal(bin1);
    int num2 = binaryToDecimal(bin2);
    int sum = num1 + num2;
    cout << "The sum is: ";
    decimalToBinary(sum);
    cout << endl;
}

// Function to subtract two binary numbers
void subtractBinary(int bin1, int bin2) {
    int num1 = binaryToDecimal(bin1);
    int num2 = binaryToDecimal(bin2);
    int diff = num1 - num2;
    cout << "The difference is: ";
    decimalToBinary(diff);
    cout << endl;
}

int main() {
    int choice;
    bool continueProgram = true;

    while (continueProgram) {
        cout << "------ Binary Calculator ------\n";
        cout << "Select an operation:\n";
        cout << "1. Binary to Decimal\n";
        cout << "2. Decimal to Binary\n";
        cout << "3. Binary Addition\n";
        cout << "4. Binary Subtraction\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            int binary;
            cout << "Enter a binary number (4 bits minimum): ";
            cin >> binary;
            int decimal = binaryToDecimal(binary);
            cout << "The decimal value is: " << decimal << endl;
        }
        else if (choice == 2) {
            int decimal;
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "The binary value is: ";
            decimalToBinary(decimal);
            cout << endl;
        }
        else if (choice == 3) {
            int bin1, bin2;
            cout << "Enter first binary number (4 bits minimum): ";
            cin >> bin1;
            cout << "Enter second binary number (4 bits minimum): ";
            cin >> bin2;
            addBinary(bin1, bin2);
        }
        else if (choice == 4) {
            int bin1, bin2;
            cout << "Enter first binary number (4 bits minimum): ";
            cin >> bin1;
            cout << "Enter second binary number (4 bits minimum): ";
            cin >> bin2;
            subtractBinary(bin1, bin2);
        }
        else {
            cout << "Invalid choice. Please select a valid operation.\n";
        }

        char continueChoice;
        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> continueChoice;
        if (continueChoice == 'N' || continueChoice == 'n') {
            continueProgram = false;
        }
    }

    cout << "Thank you for using the Binary Calculator. Goodbye!\n";
    return 0;
}
