#include <iostream>
#include "shapeFactory.hpp"

/*
 * 说明:　工厂类，解耦了类和类对象按照类别生成(在这里就是解耦了shape.hpp shapeFactory.hpp)
 */

int main() {
    ShapeFactory fac;
    auto f = fac.make_shape("simple");

    auto s1 = f->createCureInstance();
    auto s2 = f->createStaightInstance();

    s1->draw();
    s2->draw();
}