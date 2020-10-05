#include "facade.hpp"

int main() {
    Fund *fund = new Fund();
    fund->buy_fund();
    fund->sell_fund();
    delete fund;
    return 0;
}