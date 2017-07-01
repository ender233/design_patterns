#include "factory.hpp"

Stooge * Stooge::make_stooge(int choice)
{
    if(choice == 1) return new Larry;
    else if(choice == 2) return new Moe;
}
