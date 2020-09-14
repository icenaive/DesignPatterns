#include "decorator.hpp"
using namespace std;

int main() {
    Person *xc = new Person("www");
    
    Tie *t = new Tie(xc);
    Suit *su = new Suit(t);
    Shoes *se = new Shoes(su);

    se->show();
    delete xc;
    delete t;
    delete su;
    delete se;
    return 0;
}