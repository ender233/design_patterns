#include <iostream>
using namespace std;
//#define SIMPLE
#define ROBUST

class Shape
{
public:
    Shape() {
        id_ = total_++; 
    }
    virtual void draw() = 0;

protected:
    int id_;
    static int total_;
};

int Shape::total_ = 0;

struct Circle : public Shape
{
    void draw(){cout<<"circle "<<id_<<":draw"<<std::endl;}
};

struct Square : public Shape
{
    void draw() {cout<<"square "<<id_<<": draw"<<std::endl;}
};


truct Ellipse : public Shape
{
    void draw() {cout<<"ellipse "<<id_<<" draw"<<std::endl;}
};

struct Rectangle : public Shape
{
    void draw() {cout<<"Rectangle "<<id_<<" draw"<<std::endl;}
};


class Factory 
{
public:
    virtual Shape *createCuredInstance() = 0;
    virtual Shape *createStraightInstance() = 0;
};

struct SimpleShapeFactory : public Factory
{
    Shape *createCuredInstance() {return new Circle;}
    Shape *createStraightInstance() {return new Square;}
};

struct RobustShapeFactory : public Factory
{
    Shape *createCuredInstance() {return new Ellipse;}
    Shape *createStraightInstance() {return new Rectangle;}
};

int main()
{
    #ifdef SIMPLE
    Factory *factory = new SimpleShapeFactory;
    #else
    Factory *factory = new RobustShapeFactory;
    #endif

    Shape *shapes[3];
    shapes[0] = factory->createCuredInstance();
    shapes[1] = factory->createStraightInstance();
    shapes[2] = factory->createCuredInstance();

    for(int i=0; i<3; ++i) {
       shapes[i]->draw();
    }
}

