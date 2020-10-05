#include <string>
#include <iostream>
using namespace std;

class SchoolGirl {
public:
    SchoolGirl();
    SchoolGirl(string name) : name_(name) {}
    string get_name() const { return name_; }
private: 
    string name_;
};

class GiveGift {
public:
    virtual void give_flowers() = 0;
    virtual void give_dolls() = 0;
};

class Pursuit : public GiveGift {
public:
    Pursuit();
    Pursuit(SchoolGirl *girl) : girl_(girl) {}
    // ~Pursuit() { delete girl_; }
    void give_flowers() {
        cout << "give flowers to " << girl_->get_name() << endl;
    }
    void give_dolls() {
        cout << "give dolls to " << girl_->get_name() << endl;
    }
private:
    SchoolGirl *girl_;
};


class Proxy : public GiveGift {
public:
    Proxy();
    Proxy(SchoolGirl *girl) { pursuit_ = new Pursuit(girl); }
    ~Proxy() { delete pursuit_; }
    void give_flowers() {
        pursuit_->give_flowers();
    }
    void give_dolls() {
        pursuit_->give_dolls();
    }
private:
    Pursuit *pursuit_;
};