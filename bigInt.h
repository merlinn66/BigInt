#include<iostream>

namespace CMPT275 {
  class BigInt {
      
    public:
      static const int PRECISION = 30;

      // Constructors: 
      BigInt();
      BigInt(const char[]);
      BigInt(const std::string&);
  
      // Accessors
      int length() const;
      bool isOverflow() const;
      bool isInvalid() const;

      std::string toString() const;
      BigInt add (const BigInt&) const;

    private:
      // ADD YOUR OWN PRIVATE MEMBERS HERE
      using digit = int;
      
      digit digits[PRECISION];
      int fromString(const std::string &inputString);
      
      
  };
}

