#include <iostream>
#include <iomanip> // For formatting a double-precision number
#include <string>

// Add this line to avoid repeating std::
using namespace std;

// Prototype for the extractNumeric function
double extractNumeric(const strings& str);

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == 'END') {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

double extractNumeric(input) {
    int length = input.length();
    double new_num;
    string number[length];

    // Check if valid input
    int sign_count = 0;
    int dec_count = 0;

    for (int i = 0; i < length; i++) {
        if (input[i] != '0' && input[i] != '1' && input[i] != '2' && input[i] != '3' && input[i] != '4' &&
            input[i] != '5' && input[i] != '6' && input[i] != '7' && input[i] != '8' && input[i] != '9' && 
            input[i] != '.' && input[i] != '+' && input[i] != '-') {
                new_num = -999999.99;
        } else if (input[i] == '+' || input[i] == '-'){
            sign_count++;
        } else if (input[i] == '.') {
            dec_count++;
        }
    }

    if (sign_count > 1 || dec_count > 1) {
        new_num = -999999.99
    }
    return new_num

    // if valid input
    
}