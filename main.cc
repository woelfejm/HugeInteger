//John Woelfel
#include "HugeInteger.cc"
#include <iostream>
#include "sstream"
using std::stringstream;
#include "vector"
using namespace std;

int main(){
  cout<<"Test: No Arguement Constructor\n";
  HugeInteger *a = new HugeInteger();
  cout<<"value of a: "<<a->toString()<<endl;

  cout<<"**************\n";
  cout<<"Test: HugeInt string constructor\n";
  HugeInteger *b = new HugeInteger("0032ase642346dfgh9");
  cout<<b->toString()<<endl;
  HugeInteger *c = new HugeInteger("326423a46as");
  cout<<c->toString()<<endl;
  HugeInteger *d = new HugeInteger("9\nasd!@^#$@a\naw23\1241999999909");
  cout<<d->toString()<<endl;
  HugeInteger *e = new HugeInteger("099199999909");
  cout<<e->toString()<<endl;

  cout<<"**************\n";
  cout<<"Test: HugeInt reference constructor\n";
  HugeInteger *a2 = new HugeInteger(*a);
  HugeInteger *b2 = new HugeInteger(*b);
  cout<<a->toString()<<" = "<<a2->toString()<<endl;
  cout<<b->toString()<<" = "<<b2->toString()<<endl;

  cout<<"**************\n";
  cout<<"Test: isZero"<<endl;
  cout<<a->toString()<<" yeilds "<<a->isZero()<<endl;
  cout<<b->toString()<<" yeilds "<<b->isZero()<<endl;
  cout<<c->toString()<<" yeilds "<<c->isZero()<<endl;
  cout<<d->toString()<<" yeilds "<<d->isZero()<<endl;

  cout<<"**************\n";
  cout<<"Test: Operator >\n";
  cout<<(*a > *b)<<endl;
  cout<<(*b > *a)<<endl;
  cout<<(*b > *b)<<endl;
  cout<<(*a > *a)<<endl;
  //std::cout<<(*b) > (*a)<<std::endl;
  cout<<"**************\n";
  cout<<"Test: Operator ==\n";
  std::cout<<((*c)==(*b))<<std::endl;
  cout<<b->toString()<<endl;
  b->removePadding();
  cout<<b->toString()<<endl;
  std::cout<<((*c)==(*b))<<std::endl;
  std::cout<<((*c)==(*c))<<std::endl;


  cout<<"**************\n";
  cout<<"Test: Operator +\n";
  HugeInteger *sum = new HugeInteger(*b + *c);
  cout<<"sum is "<<sum->toString()<<endl;
  sum = new HugeInteger(*d + *e);
  cout<<"sum is "<<sum->toString()<<endl;
  sum = new HugeInteger(*a + *a);
  cout<<"sum is "<<sum->toString()<<endl;

  //delete all the dynamically allocated variables
  delete a, b, c, d, e, a2, sum;
}
