#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Stooge
{
public:
    static Stooge *make_stooge(int choice);
    virtual void slap_stick() = 0;
};

class Larry : public Stooge
{
public:
    void slap_stick() {
        std::cout<<"Larry: poke"<<std::endl;
    }
};

class Moe: public Stooge
{
public:
    void slap_stick() {
        std::cout<<"Moe: slap head"<<std::endl;
    }
};
