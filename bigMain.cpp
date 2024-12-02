//
//  main.cpp
//  CMPT 275 :: Lab 6
//
//  Created by Andrew Tappenden
//

#include "BigInt.h"
#include <iomanip>
#include <cmath>

using namespace CMPT275;
using namespace std;


int main ()
{

  const int NUMBER_STRING_WIDTH = BigInt::PRECISION + (BigInt::PRECISION/3 - 1);
  const int LENGTH_WIDTH = ceil(log10(BigInt::PRECISION));

  cout << "BigInt: Precise up to "<< BigInt::PRECISION << " digits." << endl << endl;
  
  BigInt a;
  BigInt b;
  BigInt c;

  // Default Constructor & toString() Tests
  cout << "a = " << a.toString();
  cout << " [LENGTH=" << setw(LENGTH_WIDTH)<< a.length() << "]" << endl;
  cout << "b = " << b.toString();
  cout << " [LENGTH=" << setw(LENGTH_WIDTH)<< b.length() << "]" << endl;
  cout << "c = " << c.toString();
  cout << " [LENGTH=" << setw(LENGTH_WIDTH)<< c.length() << "]" << endl;
  cout << endl;

  string userInput;
  
  // Constructor Test (string w/ error checking)
  cout << "Input a big int >" << endl;
  cin >> userInput;
  a = BigInt(userInput);
  
  while(a.isInvalid()) {
    cout << "Invalid input!" << endl;
    cout << "Input a big int >" << endl;
    cin >> userInput;
    a = BigInt(userInput);
  }
  cout << endl;
  
  // Constructor Test (char[] w/ error checking)
  cout << "Input a big int >" << endl;
  cin >> userInput;
  b = BigInt( userInput.c_str() );
  
  while(b.isInvalid()) {
    cout << "Invalid input!" << endl;
    cout << "Input a big int >" << endl;
    cin >> userInput;
    b = BigInt( userInput.c_str() );
  }
  cout << endl;
  
    
  // Addition T
  c = a.add(b);
  cout <<" " << setw(NUMBER_STRING_WIDTH+1) << a.toString();
  cout << " [LENGTH=" << setw(LENGTH_WIDTH)<< a.length() << "]" << endl;
  
  cout <<"+" << setw(NUMBER_STRING_WIDTH+1) << b.toString();
  cout << " [LENGTH=" << setw(LENGTH_WIDTH)<< b.length() << "]" << endl;
  cout << setfill('-') << setw(NUMBER_STRING_WIDTH+3) << "" << endl;
  cout << setfill(' ');
  cout << setw(NUMBER_STRING_WIDTH+2) << c.toString();
  cout << " [LENGTH=" << setw(LENGTH_WIDTH)<< c.length();
  if (c.isOverflow())
    cout << ", OVERFLOW]";
  else
    cout << "]";
  cout << endl;

  return 0;
}


