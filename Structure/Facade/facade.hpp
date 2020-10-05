#include <iostream>
using namespace std;

class Stock{
public:
    void buy() { cout << "buy stock\n"; }
    void sell() { cout << "sell stock\n"; }
};

class Reality{
public:
    void buy() { cout << "buy reality \n";}
    void sell() { cout << "sell reality\n"; }

};

class Fund {
public:
    Fund() {
        stock_ = new Stock();
        reality_ = new Reality();
    }
    ~Fund() {
        delete stock_;
        delete reality_;
    }
    void buy_fund() {
        stock_->buy();
        reality_->buy();
    }
    void sell_fund() {
        stock_->sell();
        reality_->sell();
    }
private:
    Stock *stock_;
    Reality *reality_;
};