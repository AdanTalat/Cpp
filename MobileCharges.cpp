#include <iostream>
#include <iomanip> // For std::setprecision
using namespace std;
int main() {
    int calls, sms;
    double callRate, smsRate, total, discount, tax, finalAmount;
    cout << "Enter the number of calls made: ";
    cin >> calls;
    cout << "Enter the number of SMS sent: ";
    cin >> sms;
    // Determine call rate
    if (calls < 100) {
        callRate = 10.0; // 10 Rs per call
    } else {
        callRate = 9.0; // 9 Rs per call
    }
    // Determine SMS rate
    if (sms < 100) {
        smsRate = 1.0; // 1 Rs per SMS
    } else {
        smsRate = 0.9; // 0.9 Rs per SMS
    }
    // Calculate total charges
    double callCharges = calls * callRate;
    double smsCharges = sms * smsRate;
    total = callCharges + smsCharges;
    // Check for discount eligibility
    if (calls > 200 || sms > 200) {
        discount = 50.0; // 50 Rs discount
    } else {
        discount = 0.0; // No discount
    }
    // Apply discount
    total -= discount;
    // Calculate sales tax (16.5%)
    tax = total * 0.165;
    finalAmount = total + tax;
    // Output the results
    cout << fixed << setprecision(2); // Set precision for currency format
    cout << "Total Call Charges: Rs " << callCharges << endl;
    cout << "Total SMS Charges: Rs " << smsCharges << endl;
    cout << "Total Before Discount: Rs " << total + discount << endl; // Before discount
    cout << "Discount Applied: Rs " << discount << endl;
    cout << "Total After Discount: Rs " << total << endl;
    cout << "Sales Tax (16.5%): Rs " << tax << endl;
    cout << "Final Amount to be Paid: Rs " << finalAmount << endl;
    return 0;
}
