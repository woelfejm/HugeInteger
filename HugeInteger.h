#pragma once
#include <iostream>
#include "sstream"
using std::stringstream;
#include "vector"
using namespace std;

class HugeInteger
{
public:
  vector<int> digits;
  HugeInteger();
  HugeInteger(const HugeInteger & other);
  HugeInteger(const string& s);
  string toString() const;
  bool operator==(const HugeInteger & rightSide);
  void removePadding();  //method to remove leading 0s
  bool operator>(const HugeInteger & rightSide);
  bool isZero() const;
  const HugeInteger operator+(const HugeInteger & rightSide);

};
