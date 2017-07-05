#include <iostream>
#include <vector>

using namespace std;

struct Stooge
{
    virtual void slap_stick() = 0;
};

struct Larry:public Stooge 
{
    void slap_stick() {std::cout<<"Larry:poke eyes"<<endl;}
};

struct Moe: public Stooge
{
    void slap_stick() {std::cout<<"Moe: slap head"<<std::endl;}
};

struct Curly: public Stooge
{
    void slap_stick() {std::cout<<"Curly:suffer abuse"<<std::endl;}
};

int main()
{
    vector<Stooge *> roles;

    roles.push_back(new Larry);
    roles.push_back(new Moe);
    roles.push_back(new Curly);

    for(auto role : roles) {
        role->slap_stick(); 
    }

    for(auto role : roles) {
        delete role;
    }
}
