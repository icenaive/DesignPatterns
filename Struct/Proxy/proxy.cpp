#include "proxy.hpp"

int main() {
    SchoolGirl *girl = new SchoolGirl("A");

    Proxy *proxy = new Proxy(girl);
    proxy->give_dolls();
    proxy->give_flowers();

    delete girl;
    delete proxy;

    return 0;
}