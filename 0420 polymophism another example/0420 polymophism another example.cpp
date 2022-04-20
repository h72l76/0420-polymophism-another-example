// 0420 polymophism another example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Base {
public: 
    // need virtual keyword to make functions in base class virtual
    virtual void func() { std::cout << "hello from base. \n"; }
    
    // make a destructor virtual 
    virtual ~Base() = default; 
};

class Derived : public Base {
public: 
    // in child class, override virtual functions from base. 
    void func() override { std::cout << "hello from derived. \n"; }
};

// make sure to use either pointer or reference to support polymorphism 
void anotherFunc(Base& o) {
    o.func(); 
}


int main()
{
    // example of polymorphism using pointer
    Base* pb = new Base(); 
    pb->func();         // this will invoke "print base"
    delete pb; 
    pb = new Derived(); 
    pb->func();         // this will invoke "print derived". Note the function call is the same. 
    delete pb; 

    // example of polymorphism using reference
    Base b; 
    Derived d; 
    anotherFunc(b); 
    anotherFunc(d);

    return 0;
}
