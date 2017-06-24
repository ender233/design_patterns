#include <iostream>
#include <string>

class Strategy {
public:
    virtual void algo() = 0;
};

class Strategy1 : public Strategy {
public:
    void algo() {
        std::cout<<"Strategy1 algo"<<std::endl;
    }
};

class Strategy2 : public Strategy {
public:
    void algo() {
        std::cout<<"Strategy2 algo" << std::endl;
    }
};


class TestBed
{
public:
    TestBed() {strategy_=NULL;}
    enum StrategyType {
        One, Two
    };

    void setStrategy(int type) {
        if(type == One) strategy_ = new Strategy1();
        else if(type == Two) strategy_ = new Strategy2();
    }
    void doIt() {
        strategy_->algo(); 
    }

private:
    Strategy *strategy_;
};

int main()
{
    TestBed t;
    t.setStrategy(TestBed::One);
    t.doIt();

    TestBed t2;
    t2.setStrategy(TestBed::Two);
    t2.doIt();
    return 0;
}

