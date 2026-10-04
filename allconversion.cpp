#include <iostream>
using namespace std;
int octaltodec(int octal){
	int sum=0;
	int base=1;
	while(octal>0){
		int digit=octal%10;
		sum+=digit*base;
		base*=8;
		octal/=10;
	}
	return sum;
}
int binarytodec(int binary){
	int sum=0;
	int base=1;
	while(binary>0){
		int digit=binary%10;
		sum+=digit*base;
		base*=2;
		binary/=10;
	}
	return sum;
}
int dectooct(int decimal) {
    int octal = 0;
    int base = 1;

    while (decimal > 0) {
        int remainder = decimal % 8;  // get last octal digit
        octal += remainder * base;    // build octal number
        base *= 10;                   // shift one decimal place
        decimal /= 8;                 // move to next digit
    }

    return octal;
}
int dectobin(int decimal) {
    int binary = 0;
    int base = 1;

    while (decimal > 0) {
        int remainder = decimal % 2;   // get binary digit (0 or 1)
        binary += remainder * base;    // add digit to binary result
        base *= 10;                    // shift place (units, tens, hundreds)
        decimal /= 2;                  // move to next bit
    }

    return binary;
}


int hextodec(string hex) {
    int decimal = 0;

    for (int i = 0; i < hex.length(); i++) {
        char ch = hex[i];
        int digit;

        // Convert each hex digit to its decimal value
        if (ch >= '0' && ch <= '9')
            digit = ch - '0';
        else if (ch >= 'A' && ch <= 'F')
            digit = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f')
            digit = ch - 'a' + 10;
        else {
            cout << "Invalid hex digit: " << ch << endl;
            return -1;
        }

        decimal = decimal * 16 + digit;  // accumulate value
    }

    return decimal;
}
string dectohex(int decimal) {
    if (decimal == 0)
        return "0";

    string hex = "";
    while (decimal > 0) {
        int rem = decimal % 16;
        char hexDigit;

        if (rem < 10)
            hexDigit = rem + '0';     // 0–9 ? '0'–'9'
        else
            hexDigit = rem - 10 + 'A'; // 10–15 ? 'A'–'F'

        hex = hexDigit + hex;  // prepend the digit
        decimal /= 16;
    }

    return hex;
}

