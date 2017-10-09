#include <iostream>
using namespace std;

class SingleClass
{
    static SingleClass *instance_;

public:
    static SingleClass *getInstance(){
        if(!instance_) {
            instance_ = new SingleClass(); 
        }
        return instance_;
    }
    void printSingleClass() {
        std::cout<<"SingleClass print"<<std::endl;
    }

private:
    SingleClass() {}
    SingleClass(SingleClass &);
    SingleClass & operator =(const SingleClass &);
};

SingleClass *SingleClass::instance_ = NULL;

int main()
{
    SingleClass *p = SingleClass::getInstance();    
    p->printSingleClass();
}
