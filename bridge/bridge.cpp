#include <iostream>
#include <string>

using namespace std;

/***********************Impl*********************/
class TimeImp
{
public:
    TimeImp(int hr, int mi) : hr_(hr), min_(mi) {}

    virtual void tell() {
        cout<<"time is TimeImp"<<endl;
    }
     
protected:
    int hr_, min_;
};

class CivilianTimeTmp : public TimeImp
{
public:
    CivilianTimeTmp(int hr, int mi, int pm) : TimeImp(hr, mi) {
        if(pm) whichM_ = " PM";
        else whichM_ = " AM";
    }
    void tell() {
        cout<<"time is "<<hr_<<":"<<min_<<whichM_<<endl;
    }

private:
    string whichM_;
};

class ZuluTimeImp : public TimeImp 
{
public:
    ZuluTimeImp(int hr, int mi, int zone) : TimeImp(hr, mi) {
        if(zone == 5) zone_ = " Eastern Standard Time";
        else zone_ = " Central Standard Time";
    }
    void tell() {
        cout<<"time is "<<hr_<<":"<<min_<<zone_<<endl;
    }
protected:
    //char zone_[30];
    string zone_;
};

/***********************object*********************/
class Time
{
public:
    Time() {}
    Time(TimeImp *imp) : impl_(imp) {}
    virtual void tell() {impl_->tell();}

protected:
    TimeImp *impl_;
};

int main() {
 
    // CivilianTimeTmp + Time
    CivilianTimeTmp *imp = new CivilianTimeTmp(2, 2, 1);
    ZuluTimeImp *imp2 = new ZuluTimeImp(3,3,5);
    Time *t = new Time(imp);
    t->tell();

    // ZuluTimeImp + Time
    Time *t2 = new Time(imp2);
    t2->tell();
}


