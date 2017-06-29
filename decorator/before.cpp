#include <iostream>

using namespace std;

class A
{
public:
    virtual void do_it(){cout<<"A"<<endl;}
};

class AX: public A
{
public:
    void do_it() {
        A::do_it(); 
        do_x();
    }
protected:
    void do_x() {cout<<"X"<<std::endl;}
};

class AY: public A
{
public:
    void do_it() {
        A::do_it(); 
        do_y();
    }
protected:
    void do_y() {cout<<"Y"<<std::endl;}
};

class AZ : public A
{
public:
    void do_it(){
        A::do_it(); 
        do_z();
    }
protected:
    void do_z() {cout<<"Z"<<std::endl;}
};

class AXYZ : public AX, public AY, public AZ
{
public:
    void do_it() {
        AX::do_it(); 
        AY::do_y();
        AZ::do_z();
    }
};

int main()
{
    AX ax;
    AXYZ  axyz;
    ax.do_it();
    std::cout<<endl;
    axyz.do_it();
}
