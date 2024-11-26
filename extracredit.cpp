#include <iostream>
#include <iomanip> // For formatting a double-precision number
#include <string>

// Add this line to avoid repeating std::
using namespace std;

double extractNumeric(const string& input) {
    int length = input.length();
    double new_num;
    bool neg = false;
    double dec_index = 1.0;

    // Check if valid input
    int sign_count = 0;
    int dec_count = 0;
    if (input[0] == '.' || input[length - 1] == '.') {
        return -999999.99;
    }

    for (int i = 0; i < length; i++) {
        if (input[i] != '0' && input[i] != '1' && input[i] != '2' && input[i] != '3' && input[i] != '4' &&
            input[i] != '5' && input[i] != '6' && input[i] != '7' && input[i] != '8' && input[i] != '9' && 
            input[i] != '.' && input[i] != '+' && input[i] != '-') {
                return -999999.99;
        } else if (input[i] == '+' || input[i] == '-'){
            sign_count++;
        } else if (input[i] == '.') {
            dec_count++;
        }
    }

    for (int i = 1; i < length; i++) {
        if (input[i] == '-' || input[i] == '+') {
            return -999999.99;
        }
    }

    if (sign_count > 1 || dec_count > 1 || length == 0 || length > 20) {
        return -999999.99;
    }

    // if valid input
    for (int i = 0; i < length; i++) {
        if (input[i] == '-') {
            neg = true;
        } else if (input[i] == '+') {
            ;
        } else if (input[i] == '.') {
            dec_index /= 10.0;
            new_num += dec_index * (input[i] - '0');
        } else {
            new_num = (input[i] - '0') + (new_num * 10);
        }
    }    
    if (neg == true) {
        new_num *= -1;
    }
    
    return new_num;
}



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