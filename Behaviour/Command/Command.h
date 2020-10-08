#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class Barbecuer {
public:
    void BakeMutton();
    void BakeChicken();
};

class Command{
public:
    Command() {}
    Command(Barbecuer*);
    virtual ~Command() {}
    virtual void ExecuteCommand() = 0;
protected:
    Barbecuer *barbecuer_;
};

class BakeMuttonCommand : public Command {
public:
    BakeMuttonCommand() {}
    BakeMuttonCommand(Barbecuer*);
    void ExecuteCommand();
};

class BakeChickenCommand : public Command {
public:
    BakeChickenCommand() {}
    BakeChickenCommand(Barbecuer*);
    void ExecuteCommand();
};

class Waiter {
public:
    void SetOrder(Command*);
    void CancelOrder(Command*);
    void Notify();
private:
    vector<Command*> commands_;
};