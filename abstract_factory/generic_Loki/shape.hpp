#pragma once
using namespace std;

struct Cured
{
    virtual void draw() = 0;
};
struct Straight
{
    virtual void draw() = 0;
};

/////////////////////////////
struct Circle: public Cured
{
    void draw() {std::cout<<"Circle"<<std::endl;}
};
struct Square : public Straight
{
    void draw() {std::cout<<"Square"<<std::endl;}
};

/////////////////////////////
struct Ellipse : public Cured
{
    void draw() {std::cout<<"Ellipse"<<std::endl;}
};
struct Rectangle : public Straight
{
    void draw() {std::cout<<"Rectangle"<<std::endl;}
};
