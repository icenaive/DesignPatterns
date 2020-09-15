#include "factory.hpp"

int main() {
    LeiFeng *leifeng;
    IFactory *ifactory = new UndergraduateFactory();
    leifeng = ifactory->create_leifeng();
    leifeng->wash();

    ifactory = new VolunteerFactory();
    leifeng = ifactory->create_leifeng();
    leifeng->sweep();

    delete ifactory;
    delete leifeng;

    return 0;
}