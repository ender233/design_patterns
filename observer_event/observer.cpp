#include <iostream>
#include <vector>
using namespace std;

class Observer
{
public:
    virtual void update(int value) {}
};

class Subject
{
    int m_value;
    vector<Observer *> m_views;
public:
    void attach(Observer *obs) {
        m_views.push_back(obs);
    }
    
    void set_val(int value)
    {
        m_value = value; 
        notify();
    }
    void notify()
    {
        for(auto view : m_views) {
           view->update(m_value) ;
        }
    }
};

class DivObserver: public Observer
{
    int m_div;
public:
    DivObserver(Subject *model, int div) {
        model->attach(this) ;
        m_div = div;
    }

    void update(int v) {
        std::cout<<v<<" div"<<m_div<<" is "<< v%m_div<<std::endl;
    }

};


int main()
{
    Subject subj;
    DivObserver div1(&subj, 4);
    DivObserver div2(&subj, 3);

    subj.set_val(5);
}


