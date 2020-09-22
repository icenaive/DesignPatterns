#include <iostream>
using namespace std;

class LeiFeng {
public:
    virtual void sweep() {
        cout << "sweep \n";
    }
    virtual void wash() {
        cout << "wash \n";
    }
    virtual void buy_rice() {
        cout << "buy rice\n";
    }
};

class Undergraduate : public LeiFeng {

};
class Volunteer : public LeiFeng {

};

class IFactory {
public:
    IFactory() {};
    virtual ~IFactory() {};
    virtual LeiFeng *create_leifeng() = 0;
};

class UndergraduateFactory : public IFactory{
public:
    LeiFeng* create_leifeng() {
        LeiFeng *leifeng = new Undergraduate();
        return leifeng;
    }
};

class VolunteerFactory : public IFactory{
public:
    LeiFeng* create_leifeng() {
        LeiFeng *leifeng = new Volunteer();
        return leifeng;
    }
};

