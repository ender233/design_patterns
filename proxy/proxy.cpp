#include <iostream>
#include <vector>
using namespace std;

/*
 * Notes:
 * 1. add proxy class(PettyCash) to get additional operations
 * 2. init class array by static array(list/vector) and a count number
 *
 */

class Person
{
    class TooManyObjects{};
    string nameString;
    static string list[];
    static vector<std::string> vec1;
    static int next;

    public:
    Person(){
        if(next > vec1.size()) throw TooManyObjects();
        nameString = vec1[next++];
        //nameString = list[next++];
    }
    string name() {return nameString;}
};

vector<std::string> Person::vec1{"Tom", "Dick", "Harry", "Bubba"};
//string Person::list[] = {"Tom", "Dick", "Harry", "Bubba"};
int Person::next = 0;

class PettyCashProtected
{
    int balance;
public:
    PettyCashProtected() : balance(500) {}
    bool withdraw(int amount) {
        if(amount > balance)  return false;
        balance -= amount;
        return true;
    }
    int getBalance() {
        return balance ;
    }
};

class PettyCash
{
    PettyCashProtected realThing;

public:
    bool withdraw(Person &p, int amount) {
        if(p.name()=="Tom" || p.name()=="Harry" ||  p.name()=="Bubba") 
            return realThing.withdraw(amount);
        else
            return false;
    }
    int getBalance() {
        return realThing.getBalance(); 
    }
};

int main()
{
    PettyCash pc;
    Person workers[4];

    for(int i=0, amount=100; i<4; i++, amount+=100) {
        if(!pc.withdraw(workers[i], amount)) 
            cout<<"No money for " <<workers[i].name()<<std::endl;
        else
            cout<<amount<<" dollars for "<<workers[i].name()<<std::endl;
    }
    cout<<"Remainning ballance is "<<pc.getBalance()<<std::endl;
}
