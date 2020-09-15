#include "template.hpp"

int main() {
    Student1 *test1 = new Student1();
    test1->question();
    Student2 *test2 = new Student2();
    test2->question();

    delete test1;
    delete test2;
    return 0;
}