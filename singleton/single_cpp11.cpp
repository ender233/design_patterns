#include <iostream>
using namespace std;

template<typename T>
class SingleClass
{
private:
    static T* pInstance_;

public:
    template<typename... Args>
    static T *InitInstance(Args&&... args) {
        if(nullptr == pInstance_) {
            pInstance_ = new T(std::forward<Args>(args)...) ;
        }
        return pInstance_;
    }

    static T *getInstance() {
        if(pInstance_ == nullptr) {
            throw;
        }
        return pInstance_;
    }

    static void destroyInstance() {
        delete pInstance_; 
        pInstance_ = nullptr;
    }
};
template<typename T> T * SingleClass<T>::pInstance_ = nullptr;

struct TestA
{
private:
    friend class SingleClass<TestA>;
    TestA(int x) {
        std::cout<<"this is num:" <<x<<std::endl;
    }
};
struct TestB
{
private:
    friend class SingleClass<TestB>;
    TestB(int x, int y) {
        std::cout<<"this is num1:" <<x<<std::endl;
        std::cout<<"this is num2:" <<y<<std::endl;
    }
};

int main()
{
    TestA * p1 = SingleClass<TestA>::InitInstance(1);
    TestB * p2 = SingleClass<TestB>::InitInstance(1, 2);
}
