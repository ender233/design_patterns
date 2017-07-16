#include <iostream>
#include <memory>
#include <typeinfo>
#include <loki/AbstractFactory.h>
#include <shape.hpp>

using namespace std;

// AbstractFactory
typedef Loki::AbstractFactory<LOKI_TYPELIST_2(Cured, Straight)> AbstractShapeFactory;
typedef Loki::ConcreteFactory<AbstractShapeFactory, Loki::OpNewFactoryUnit, LOKI_TYPELIST_2(Circle, Square)> EasyShapeFactory;
typedef Loki::ConcreteFactory<AbstractShapeFactory, Loki::OpNewFactoryUnit, LOKI_TYPELIST_2(Ellipse, Rectangle)> ComplexShapeFactory;

int main()
{
    std::auto_ptr<AbstractShapeFactory> easy(new EasyShapeFactory);

    Cured *c;
    c = easy->Create<Cured>();
    Straight *s;
    s = easy->Create<Straight>();

    c->draw();
    s->draw();


    std::auto_ptr<AbstractShapeFactory> com(new ComplexShapeFactory);
    Cured *c2;
    c2 = com->Create<Cured>();
    Straight *s2;
    s2 = com->Create<Straight>();

    c2->draw();
    s2->draw();

    std::cout<<"ok"<<std::endl;
}
