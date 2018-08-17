/*John Woelfel
 *CS 343 Murphy Spring 2018
 *PA#1
 *This program contains methods related to creating and modifying integers too large for primitive types using
 *the C++STL class vector. Doesn't support negative numbers.
*/


#include "HugeInteger.h"
#include <iostream>
#include "sstream"
using std::stringstream;
#include "vector"
using namespace std;

HugeInteger::HugeInteger(){
  digits.push_back(0);
}

string HugeInteger::toString() const{
  stringstream stream;
  for(int i = 0; i < digits.size(); i++){
    stream << digits[i];
  }
  return stream.str();//this.digits[0];
}

HugeInteger::HugeInteger(const HugeInteger& other){
  for(int i = 0; i < other.digits.size(); i++){
    digits.push_back(other.digits[i]);
  }
}

HugeInteger::HugeInteger(const string& s) {
  string x;
  for(int i = 0; i < s.length(); i++){
    x = s[i];
    int numb;
    if(istringstream ( x ) >> numb)
      digits.push_back(numb);
  }
  this->removePadding();

}

//Method I made that modifies calling HugeInteger by removing leading 0s from a HugeInteger. This is only used in the string arg constructor.
void HugeInteger::removePadding(){
  int first = digits[0];
  while(first == 0 && digits.size() >= 1){
    digits.erase(digits.begin());
    first = digits[0];
  }
  return;
}

//Check if two values are equal returns true (1) if they are equal
bool HugeInteger::operator==(const HugeInteger& rightSide){
  if(rightSide.digits.size() != digits.size()){
    return false;
  }
  for(int i = 0; i < digits.size(); i++){
    if(digits[i] != rightSide.digits[i])
      return false;
    }

  return true;
}

//Returns true if the calling HugeInteger is larger than the parameter (rightSide)
bool HugeInteger::operator>(const HugeInteger& rightSide){
  vector<int> left, right;
  if(this->isZero() || digits.size() <= 0)
    return false;
  else if(rightSide.isZero() || rightSide.digits.size() <= 0)
    return true;
  for(int i = 0; i < digits.size(); i-- ){
    if(digits[i] > rightSide.digits[i] ){
      return true;
    }
    else if(digits[i] < rightSide.digits[i] ){
      return false;
    }
  }
  return false;

}

//Return true if value is zero (0=00=000)
bool HugeInteger::isZero() const{
  for(int i = 0; i < digits.size(); i++){
    if(digits[i] != 0)
      return false;
  }
  return true;
}

const HugeInteger HugeInteger::operator+(const HugeInteger& rightSide){
  vector<int> sum;
  int x, y, carry = 0, total, vecSize;
  //sets vecSize to larger sized vector
  if(rightSide.isZero() && isZero())
    return HugeInteger();
  if(rightSide.digits.size() > digits.size())
    vecSize = rightSide.digits.size();
  else
    vecSize = digits.size();
  for(int i = 0; i < vecSize; i++){
    //to stay in index of vector(could be different sizes)
    if(i < digits.size()){
      x = digits[digits.size() - 1 - i];
    }
    else x=0;
    if(i < rightSide.digits.size()){
      y = rightSide.digits[ rightSide.digits.size() - 1 -i];
    }
    else y=0;
    total = x+y+carry;
    if(total >= 10){
      sum.push_back(total - 10);
      carry = 1;
    }
    else{
      sum.push_back(total);
      carry = 0;
    }
  }

  stringstream value;
  value<<carry; //last digit to add
  for(int j = 0; j <vecSize; j++){

    if(j == 0)
      value << (sum[vecSize - 1 - j]);

    else{
      value << sum[vecSize - 1 - j];
    }
  }

  return HugeInteger(value.str());

}
