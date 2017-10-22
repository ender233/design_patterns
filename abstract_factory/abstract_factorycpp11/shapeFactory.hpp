//
// Created by xps on 22.10.2017.
//

#ifndef ABSTRACT_FACTORYCPP11_SHAPEFACTORY_HPP
#define ABSTRACT_FACTORYCPP11_SHAPEFACTORY_HPP

#endif //ABSTRACT_FACTORYCPP11_SHAPEFACTORY_HPP

#include <memory>
#include <functional>
#include <map>
#include "shape.hpp"
using namespace std;

class Factory
{
public:
    virtual unique_ptr<Shape> createCureInstance() = 0;
    virtual unique_ptr<Shape> createStaightInstance() = 0;
};

struct SimpleShapeFactory : public Factory
{
    unique_ptr<Shape> createCureInstance() override {
        return make_unique<Circle>();
    }
    unique_ptr<Shape> createStaightInstance() override {
        return make_unique<Square>();
    }
};

struct RobustShapeFactory : public Factory
{
    unique_ptr<Shape> createCureInstance() override {
        return make_unique<Ellipse>();
    }

    unique_ptr<Shape> createStaightInstance() override {
       return make_unique<Rectangle>();
    }
};

//////////////////////////
class ShapeFactory
{
    map<std::string, unique_ptr<Factory>> shape_factories;
    // 如果除了返回的映射工厂类，还有其他的活要做(比如一些初始化工作), 那么可以用function封装
    //map<std::string, std::function<unique_ptr<Factory>()>> shape_factories;
public:
    ShapeFactory() {
        shape_factories["simple"] = make_unique<SimpleShapeFactory>();
        shape_factories["robust"] = make_unique<RobustShapeFactory>();
    }

    unique_ptr<Factory> make_shape(const string& name) {
        return std::move(shape_factories[name]);
    }
};
