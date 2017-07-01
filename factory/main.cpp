#include <iostream>
#include <vector>
#include "factory.hpp"
using namespace std;

int main()
{
    vector<Stooge *> roles;
    roles.push_back(Stooge::make_stooge(1));
    roles.push_back(Stooge::make_stooge(2));
    for(auto p : roles) {
        p->slap_stick(); 
    }
}
