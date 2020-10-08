#include <string>
#include <iostream>
using namespace std;

class Country;

class UnitedNations {
public:
    virtual void Declare(string, Country*) = 0;
};

class UnitedNationsSecurityCouncil : public UnitedNations {
public:
    UnitedNationsSecurityCouncil() {}
    void SetUsa(Country*);
    void SetIraq(Country*);
    void Declare(string, Country*);
private:
    Country *usa_;
    Country *iraq_;
};

class Country{
public:
    Country() {}
    Country(UnitedNations*);
    virtual void Declare(string) = 0;
    virtual void GetMessage(string) = 0;
protected:
  UnitedNations *mediator_;
};

class Usa: public Country {
public:
    Usa() {}
    Usa(UnitedNations*);
    void Declare(string);
    void GetMessage(string);
};

class Iraq: public Country {
public:
    Iraq() {}
    Iraq(UnitedNations*);
    void Declare(string);
    void GetMessage(string);
};
