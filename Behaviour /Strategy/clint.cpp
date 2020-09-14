#include "./CashAlgor.hpp"
// #include "./CashSuper.h"
using namespace std;

int main() {
    CashContenxt *strategy = new CashContenxt("normal", "100");
    strategy->get_result(1000);
    return 0;
}