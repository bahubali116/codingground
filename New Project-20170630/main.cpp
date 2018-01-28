#include <iostream>
using namespace std;

class A {
  int a;
  public:
  A() { cout << "inside A default const \n";}
  A(int a): a(a) { cout << "inside A parameter const a= "<< a<< "\n";}
};

class B: public A {
    int b;
    public:
    B(int b): A(b), b(b){ cout << "inside b parameterised const b=" <<b <<"\n";}
};

int main() {
    
    B obj(23);
	// your code goes here//my code here
	return 0;
}
