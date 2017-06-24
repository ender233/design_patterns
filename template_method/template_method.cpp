#include <iostream>
#include <array>
using namespace std;

class Base
{
    void a() {
        std::cout<<"a ";
    }
    void c() {
        std::cout<<"c ";
    }
    void e() {
        std::cout<<"d ";
    }

    virtual void ph1() = 0;
    virtual void ph2() = 0;

public:
    void execute()
    {
        a(); 
        ph1();
        c();
        ph2();
        e();
    }
};

class One : public Base
{
    void ph1() {cout<<"b ";}
    void ph2() {cout<<"d ";}
};

class Two : public Base
{
    void ph1() {cout<<"2 ";}
    void ph2() {cout<<"4 ";}
};

int main()
{
    array<Base*, 2> b_ptr{new One(), new Two()};
    for(auto p : b_ptr) {
        p->execute(); 
        std::cout<<std::endl;
    }
}



