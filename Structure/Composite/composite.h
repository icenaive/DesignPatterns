#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Company {
public:
    Company();
    Company(string);
    virtual void Add(Company *) = 0;
    // virtual void Remove() = 0;
    virtual void Display(int) = 0;
    virtual void ListOfDuty() = 0;
protected:
    string name_;
};

class HrDepartment : public Company {
public:
    HrDepartment();
    HrDepartment(string);
    void Add(Company*);
    void Display(int);
    void ListOfDuty();
};

class FinanceDepartment : public Company {
public:
    FinanceDepartment();
    FinanceDepartment(string);
    void Add(Company*);
    void Display(int);
    void ListOfDuty();
};
class ConcreteCompany : public Company {
public:
    ConcreteCompany();
    ConcreteCompany(string);
    void Add(Company*);
    void Display(int);
    void ListOfDuty();
private:
    vector<Company*> companies_;
};
