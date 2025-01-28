// #include<iostream>
// #include <list>
// #include<tuple>
// #include<vector>
// using namespace std;

// void load(const tuple<int, int, int, int>& memory,int ac) {
//     int val1 = get<0>(memory);
//     // int val2 = get<1>(memory);
//     // int val3 = get<2>(memory);
//     // int val4 = get<3>(memory);
//     ac=val1;
//     cout<<ac;
// }

// void store(){
    
// }

// void add(){
    
// }

// int main(){
//     cout<<"\t\t\tWelcome to CPU cycle journey!\n";
//     tuple<int, int, int,int> memory(300,301,302,303);


//     int pc=0, ac=0;
//     string ir;
// //      for (int value : myList) {
// //         cout << value << " ";
// //     }
// //     cout << endl;
// load(memory, ac);

// }


//bool tables:::
// #include <iostream>
// using namespace std;

// // Function prototypes
// void displayTruthTable(char operation);
// bool calculateResult(char operation, bool input1, bool input2);

// int main() {
//     char choice;
//     bool continueProgram = true;

//     while (continueProgram) {
//         // Asking for the operation type
//         cout << "Select the truth table you are interested in:\n";
//         cout << "'A' for AND\n'O' for OR\n'X' for XOR\n'N' for NAND\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         // Input validation for the operation
//         if (choice != 'A' && choice != 'O' && choice != 'X' && choice != 'N') {
//             cout << "Invalid choice. Please enter a valid option.\n";
//             continue;
//         }

//         // Asking for inputs
//         int input1, input2;
//         cout << "Enter input 1 (0 or 1): ";
//         cin >> input1;
//         cout << "Enter input 2 (0 or 1): ";
//         cin >> input2;

//         // Input validation for boolean values
//         if ((input1 != 0 && input1 != 1) || (input2 != 0 && input2 != 1)) {
//             cout << "Invalid inputs. Please enter 0 or 1 for both inputs.\n";
//             continue;
//         }

//         // Displaying the result
//         bool result = calculateResult(choice, input1, input2);
//         cout << "Result: " << result << endl;

//         // Asking for another query
//         char nextQuery;
//         cout << "Do you want to make another query? (Y/N): ";
//         cin >> nextQuery;
//         if (nextQuery == 'N' || nextQuery == 'n') {
//             continueProgram = false;
//         }
//     }

//     cout << "Exiting the program. Goodbye!" << endl;
//     return 0;
// }

// // Function to calculate the result based on operation type and inputs
// bool calculateResult(char operation, bool input1, bool input2) {
//     switch (operation) {
//         case 'A': return input1 && input2;   // AND
//         case 'O': return input1 || input2;   // OR
//         case 'X': return input1 != input2;   // XOR
//         case 'N': return !(input1 && input2); // NAND
//         default: return false;
//     }
// }












//calculator
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






















// #include <iostream>
// #include <list>
// #include <string>
// #include <bitset>

// using namespace std;

// struct InstructionMemory {
//     string address;
//     string value;
// };

// struct DataMemory {
//     string address;
//     string value;
// };


// void load(int& AC, const string& address, list<DataMemory>& datalist) {
//     auto it = datalist.begin();
//     for (; it != datalist.end(); ++it) {
//         if (it->address == address) {  
//             AC = stoi(it->value, nullptr, 2);  
//             cout << "\nLoaded data: " << it->value << " (" << AC << ") from memory address " << it->address << endl;
//             break;
//         }
//     }
// }


// void store(const string& address, int AC, list<DataMemory>& datalist) {
//     auto it = datalist.begin();
//     for (; it != datalist.end(); ++it) {
//         if (it->address == address) {  
//             it->value = bitset<8>(AC).to_string();  
//             cout << "\nStored data: " << it->value << " into memory address " << it->address << endl;
//             break;
//         }
//     }
// }


// void add(int& AC, const string& address, list<DataMemory>& datalist) {
//     auto it = datalist.begin();
//     for (; it != datalist.end(); ++it) {
//         if (it->address == address) { 
//             int dataValue = stoi(it->value, nullptr, 2);  
//             AC += dataValue;  
//             cout << "\nAdded data: " << it->value << " (" << dataValue << ") to Accumulator, New AC: " << AC << endl;
//             break;
//         }
//     }
// }


// void fetch(int& PC, string& IR, list<InstructionMemory>& memoryList) {
//     auto it = memoryList.begin();
//     advance(it, PC); 
//     IR = it->value;  
//     cout << "\tFetched instruction: " << IR << " from memory address " << it->address << endl;
// }


// void decode(const string& IR, string& opcode, string& address) {
//     opcode = IR.substr(0, 4);  
//     address = IR.substr(4, 4);  
   
// }

// int main() {
//     int PC = 0, AC = 0;  
//     string IR; 

//     list<InstructionMemory> memoryList;
//     list<DataMemory> datalist;
//     cout<<"\t\t\tCPU Information execution cycle\n\n";
    
//     memoryList.push_back({ "0000", "01010101" });  
//     memoryList.push_back({ "0001", "00010110" }); 
//     memoryList.push_back({ "0010", "00110111" });  

   
//     datalist.push_back({ "0101", "00000011" });  
//     datalist.push_back({ "0110", "00010110" });  
//     datalist.push_back({ "0111", "00110111" });  

    
//     while (PC < 3) {
//         fetch(PC, IR, memoryList);  

       
//         string opcode, address;
//         decode(IR, opcode, address);

       
//         if (opcode == "0101")  
//             load(AC, address, datalist);  
//         else if (opcode == "0001")  
//             add(AC, address, datalist);  
//         else if (opcode == "0011")  
//             store(address, AC, datalist);  

//         PC++;  
//     }

//     return 0;
// }









