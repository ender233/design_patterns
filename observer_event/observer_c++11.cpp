#include <iostream>
#include <string>

#include <boost/noncopyable.hpp>
#include <functional>
#include <map>

using namespace std;

template<typename Func>
class Subject : public boost::noncopyable
{
public:
    Subject() {}
    ~Subject() {}

    void set_val(int value) {
        m_value = value; 
        notify(m_value);
    }

    int attach(Func &f) {
        return assign(f);
    }
    int attach(const Func &f) {
        return assign(f);
    }

    void disattach(int key) {
        m_connections.erase(key);
    }

    // notify all the observer
    template<typename... Args>
    void notify(Args&&... args)
    {
        for(auto &it : m_connections)  {
            it.second(std::forward<Args>(args)...);
        }
    }
private:
    template<typename F>
    int assign(F &&f) {
        int k = m_observerId++; 
        m_connections.emplace(k, std::forward<F>(f));
        return k;
    }

private:
    int m_observerId = 0;
    std::map<int, Func> m_connections;
    int m_value;
};

class DivObserver
{
    int m_div;
public:
    DivObserver(Subject<std::function<void(int)>> *model, int div) : m_div(div) {
        // lambda
        model->attach([&](int v){
                std::cout<<v<<" div"<<m_div<<" is:"<<v%m_div<<std::endl;
            });
        // member function
        model->attach(std::bind(&DivObserver::update, this, std::placeholders::_1));
    }

    void update(int v) {
        std::cout<<v<<" div"<<m_div<<" is:"<<v%m_div<<std::endl;
    }
};

int main()
{
    Subject<std::function<void(int)>> sub;
    DivObserver div1(&sub, 4);
    DivObserver div2(&sub, 3);
    
    sub.set_val(5);
    return 0;
}
