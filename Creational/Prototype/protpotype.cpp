#include "prototype.hpp"

int main() {
    Resume *resume1, *resume2;
    resume1 = new Resume("A");
    resume1->set_person_info("n", "123");
    resume1->set_work_experence("google","beijing");
    resume2 = resume1->clone();
    resume1->print_resume();
    resume2->print_resume();
    resume2->set_name("B");
    resume2->set_person_info("f", "12");
    resume1->print_resume();
    resume2->print_resume();
    delete resume1;
    delete resume2;
    return 0;
}