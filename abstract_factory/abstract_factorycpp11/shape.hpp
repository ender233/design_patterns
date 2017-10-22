//
// Created by xps on 22.10.2017.
//
#ifndef ABSTRACT_FACTORYCPP11_SHAPE_HPP
#define ABSTRACT_FACTORYCPP11_SHAPE_HPP
#endif //ABSTRACT_FACTORYCPP11_SHAPE_HPP

#include <iostream>
using namespace std;
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
    void draw()override {cout<<"circle "<<id_<<":draw"<<std::endl;}
};

struct Square : public Shape
{
    void draw() override {cout<<"square "<<id_<<": draw"<<std::endl;}
};


struct Ellipse : public Shape
{
void draw() override {cout<<"ellipse "<<id_<<" draw"<<std::endl;}
};

struct Rectangle : public Shape
{
    void draw() override {cout<<"Rectangle "<<id_<<" draw"<<std::endl;}
};
