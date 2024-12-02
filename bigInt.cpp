#include "BigInt.h"
using namespace CMPT275;

const char ZERO = '0';
const int INT_TO_CHAR_CONVERSION = 48;

// constructors 
BigInt::BigInt() {
    // Initialize digits to zero
    for (int i = 0; i < BigInt::PRECISION; i++) {
        digits[i] = 0; // set default to zero
        
    }
    
//        set length to 1
//        length_ = 1;
//        set valid to true || set invalid to false
//        let overflow to false 
//        overflow_ = false;

}


BigInt::BigInt(const char digitString[]) {
    fromString(digitString);
}

BigInt::BigInt(const std::string &digitString) {
    fromString(digitString);
}

// accessors
int BigInt::length() const {
    int num_digits = PRECISION;
    while (num_digits > 1 && digits[PRECISION - num_digits] == 0) {
        num_digits--;
    }
    return num_digits == 0 ? 1 : num_digits;
}

bool BigInt::isOverflow() const {
    // Check if the number exceeds the allowed PRECISION
    return digits[0] > 0;
}

bool BigInt::isInvalid() const {
    for (int i = 0; i < PRECISION; i++) {
        if (digits[i] < 0 || digits[i] > 9)
            return true;
    }
    return false;
}

int BigInt::fromString(const std::string &inputString) {
    if (inputString.length() > BigInt::PRECISION)
        return -1;

    std::string stringHolder = inputString;

    // Remove leading zeros
    if (inputString.length() > PRECISION) {
        stringHolder = "";
        bool leadingZeros = true;
        for (char c : inputString) {
            if (c == ZERO && leadingZeros) continue;
            leadingZeros = false;
            stringHolder += c;
        }
    }

    // Reset digits[] array
    for (int i = 0; i < PRECISION; i++) {
        digits[i] = 0;
    }

    // Fill the array from the string, backwards
    int Index = inputString.length() - 1;
    int arr = BigInt::PRECISION - 1;

    while (Index >= 0) {
        char strChar = inputString[Index];
        if (!isdigit(strChar))
            return -1;
        digits[arr] = strChar - INT_TO_CHAR_CONVERSION; // convert to int/digit
        Index--;
        arr--;
    }

    return inputString.length();
}


// Convert the BigInt to a string 
std::string BigInt::toString() const {
    int count = 0;
    bool leadingZeros = true;
    std::string bigIntString = "";

    for (int i = 0; i < PRECISION; i++) {
        if (digits[i] != 0 || !leadingZeros) {
            leadingZeros = false; // Ignore leading zeros

            //using i instead of count helps iterate from left to right 
            if (count > 0 && i % 3 == 0) { 
                bigIntString += ","; // Add a comma every 3 digits
            }

            bigIntString += (digits[i] + INT_TO_CHAR_CONVERSION);
            count++;
        }
    }

    if (bigIntString.empty()) {
        return "0"; // Return 0 if the string is empty
    }

    return bigIntString;
}

// Add two BigInts
BigInt BigInt::add(const BigInt &other) const {
    BigInt results;
    int carry = 0;

    for (int i = PRECISION - 1; i >= 0; i--) {
        int sum = digits[i] + other.digits[i] + carry;
        results.digits[i] = sum % 10;
        carry = sum / 10;
    }

    return results;
}
