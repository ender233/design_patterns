#include <iostream>
using namespace std;

class I
{
public:
    virtual void do_it() = 0;
};

class A : public I
{
public:
    virtual void do_it() {cout<<"A";}
};

class Decorator : public I
{
public:
    Decorator(I *inter) : impl(inter) {}
    virtual void do_it() {
        impl->do_it();
    }

protected:
    I *impl;
};


class X : public Decorator
{
public:
    X(I *inter) : Decorator(inter) {}
    virtual void do_it() {
        impl->do_it(); 
        cout<<"X";
    }
};

class Y : public Decorator
{
public:
    Y(I *inter) : Decorator(inter) {}
    virtual void do_it() {
        impl->do_it(); 
        cout<<"Y";
    }
};

class Z : public Decorator
{
public:
    Z(I *inter) : Decorator(inter) {}
    virtual void do_it() {
        impl->do_it(); 
        cout<<"Z";
    }
};

int main()
{
    I *ax = new X(new A);
    I *axyz = new Z(new Y(new X(new A)));

    ax->do_it();
    std::cout<<endl;
    axyz->do_it();
    std::cout<<endl;;
}

