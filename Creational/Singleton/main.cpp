#include "Singleton.h"
#include <iostream>
using namespace std;

int main() {
    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();

    if(s1 == s2) cout << "s1 == s2\n";
    return 0;
}