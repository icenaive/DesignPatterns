//#include "./CashSuper.h"
#include <string>
#include <iostream>
#include <sstream>

class CashSuper {
public:
    // virtual ~CashSuper();
    virtual double accept_cash(double) = 0;
};

class CashNormal: public CashSuper{
public:
    double accept_cash(double);
};
class CashRobate: public CashSuper{
public:
    CashRobate() {};
    CashRobate(double money_rebate) : money_rebate_(money_rebate){};
    double accept_cash(double);
private:
    double money_rebate_;
};

class CashReturn: public CashSuper {
public:
    CashReturn() {}
    CashReturn(double money_condition, double money_return) : money_condition_(money_condition), money_return_(money_return) {}
    double accept_cash(double);
private:
    double money_condition_;
    double money_return_;
};
class CashContenxt {
public:
    CashContenxt() {}
    CashContenxt(std::string, std::string);
    ~CashContenxt();
    double get_result(double);
private:
    CashSuper *cash_;
};
double CashNormal::accept_cash(double cash) { return cash; }
double CashRobate::accept_cash(double cash) { return cash * money_rebate_; }
double CashReturn::accept_cash(double cash) { return cash - (int)(cash / money_condition_) * money_return_;}
CashContenxt::CashContenxt(std::string type, std::string number) {
    if(type == "normal") {
        cash_ = new CashNormal();
    } else if(type == "robate") {
        std::stringstream ss;
        double money_rebate;
        ss << number;
        ss >> money_rebate;
        cash_ = new CashRobate(money_rebate);
    } else if(type == "return") {
        double money_condition, money_return;
        std::stringstream ss;
        ss << number;
        ss >> money_condition >> money_return;
        cash_ = new CashReturn(money_condition, money_return);
    } 
}

CashContenxt::~CashContenxt() { delete cash_; }
double CashContenxt::get_result(double cash) {
    double result = cash_->accept_cash(cash);
    std::cout << result << std::endl;;
    return result;
}