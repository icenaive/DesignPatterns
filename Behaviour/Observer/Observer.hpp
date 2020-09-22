#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Notifier;

class Observer {
public:
    Observer();
    Observer(string name) : name_(name) {}
    virtual ~Observer() {}
    void SetNotifier(Notifier *notifier) {
        notifier_ = notifier;
    }
    virtual void Update() = 0;
protected:
    string name_;
    Notifier *notifier_;
};

class Notifier {
public:
    Notifier() {}
    virtual ~Notifier() {}
    void Attach(Observer *observer) {
        observers_.push_back(observer);
    }
    void Detach(Observer *observer) {
        for(auto it = observers_.begin(); it != observers_.end(); ++it) if(*it == observer) {
            observers_.erase(it);
            return ;
        }
    }
    void SetState(string state) {
        state_ = state;
    }
    string GetState() {
        return state_;
    }
    void Notify() {
        for(auto it = observers_.begin(); it != observers_.end(); ++it) (*it)->Update();
    }
protected:
    vector<Observer*> observers_;
    string state_;
};

class StockObserver : public Observer {
public:
    StockObserver();
    StockObserver(string name) : Observer(name) {}
    void Update() {cout << name_ << " "<< notifier_->GetState() << " close" << endl;}
};

class NbaObserver: public Observer {
public:
  NbaObserver() {}
  NbaObserver(string name) : Observer(name) {}
  void Update() {cout << name_ << " "<< notifier_->GetState() << " close" << endl;}
};


class Secretary: public Notifier {
};

class Boss: public Notifier {
};