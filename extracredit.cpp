#include <iostream>
#include <iomanip> // For formatting a double-precision number
#include <string>

// Add this line to avoid repeating std::
using namespace std;

double extractNumeric(const string& input) {
    // initialize variables
    int length = input.length();
    double new_num;
    bool neg = false;
    double dec_index = 1.0;

    // Check if valid input
    int sign_count = 0;
    int dec_count = 0;
    if (input[0] == '.' || input[length - 1] == '.') { // if decimal in invalid index
        return -999999.99;
    }

    for (int i = 0; i < length; i++) {
        if (input[i] != '0' && input[i] != '1' && input[i] != '2' && input[i] != '3' && input[i] != '4' && // check if each character is valid
            input[i] != '5' && input[i] != '6' && input[i] != '7' && input[i] != '8' && input[i] != '9' && 
            input[i] != '.' && input[i] != '+' && input[i] != '-') {
                return -999999.99;
        } else if (input[i] == '+' || input[i] == '-'){ // count number of sign characters to make sure there's only one or zero
            sign_count++;
        } else if (input[i] == '.') { // count number of decimals to make sure there's one or zero
            dec_count++;
        }
    }

    for (int i = 1; i < length; i++) {
        if (input[i] == '-' || input[i] == '+') { // if sign characters are anywhere but index 0 it's invalid
            return -999999.99;
        }
    }

    if (sign_count > 1 || dec_count > 1 || length == 0 || length > 20) { // if there's too many signs/decimals or the input is too small/large
        return -999999.99;
    }

    // if valid input - begin conversion from string to int
    for (int i = 0; i < length; i++) { 
        if (input[i] == '-') { // check sign
            neg = true;
        } else if (input[i] == '+') { 
            ; // do nothing if positive
        } else if (input[i] == '.') { // if char is decimal
            dec_index /= 10.0;
            new_num += dec_index * (input[i] - '0');
            // cout << new_num << endl;
        } else { // at this point, it must be a number
            new_num = (input[i] - '0') + (new_num * 10);
        }
    }    
    if (neg == true) { // deal with - if negative
        new_num *= -1;
    }
    
    return new_num;
}



int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;
        
        if (input[0] == 'E' && input[1] == 'N' && input[2] == 'D') { // if user wants to end
            break;
        }

        double number = extractNumeric(input); // function call

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) // output number
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl; // or output invalid
        }
    }

    return 0;
}