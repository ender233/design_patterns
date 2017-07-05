#include <iostream>
#include <vector>
using namespace std;

struct Stooge
{
    virtual Stooge *clone() = 0;
    virtual void slap_stick() = 0;
};

class Factory
{
public:
    static Stooge *make_stooge(int choice);

private:
    static Stooge *s_prototypes[4];
};

struct Larry:public Stooge 
{
    void slap_stick() {std::cout<<"Larry:poke eyes"<<endl;}

    // invoke copy-constrction function
    Stooge *clone() {return new Larry;}
};

struct Moe: public Stooge
{
    void slap_stick() {std::cout<<"Moe: slap head"<<std::endl;}
    Stooge *clone() {return new Moe;}
};

struct Curly: public Stooge
{
    void slap_stick() {std::cout<<"Curly:suffer abuse"<<std::endl;}
    Stooge *clone() {return new Curly;}
};


// implementation

Stooge *Factory::s_prototypes[] = {0, new Larry, new Moe, new Curly};

Stooge *Factory::make_stooge(int choice) {
    return s_prototypes[choice]->clone();
}


int main()
{
    vector<Stooge *> roles;

    roles.push_back(Factory::make_stooge(1));
    roles.push_back(Factory::make_stooge(2));
    roles.push_back(Factory::make_stooge(3));

    for(auto role : roles) {
        role->slap_stick(); 
    }

    for(auto role : roles) {
        delete role;
    }
}
