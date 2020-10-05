#include "composite.h"

Company::Company() {}
Company::Company(string name) : name_(name) {}

HrDepartment::HrDepartment() {}
HrDepartment::HrDepartment(string name) : Company(name) {}
void HrDepartment::Add(Company*) {}
void HrDepartment::Display(int depth) {
    for(int i = 0; i < depth; ++i) {
        cout << "--";
    }
    cout << name_ << endl;
}
void HrDepartment::ListOfDuty() {
    cout << name_ << " hr" << endl;
}

FinanceDepartment::FinanceDepartment() {}
FinanceDepartment::FinanceDepartment(string name) : Company(name) {}
void FinanceDepartment::Add(Company*) {}
void FinanceDepartment::Display(int depth) {
    for(int i = 0; i < depth; ++i) {
        cout << "--";
    }
    cout << name_ << endl;
}
void FinanceDepartment::ListOfDuty() {
    cout << name_ << " finance" << endl;
}

ConcreteCompany::ConcreteCompany() {}
ConcreteCompany::ConcreteCompany(string name) : Company(name) {}
void ConcreteCompany::Add(Company* company) {
    companies_.push_back(company);
}
void ConcreteCompany::Display(int depth) {
    for(int i = 0; i < depth; ++i) cout << "--";
    cout << name_ << endl;
    for(auto it = companies_.begin(); it != companies_.end(); ++it) 
        (*it)->Display(depth + 1); 
}
void ConcreteCompany::ListOfDuty() {
    for(auto it = companies_.begin(); it != companies_.end(); ++it) 
        (*it)->ListOfDuty(); 
}