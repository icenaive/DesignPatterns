#include "Visitor.h"

int main() {
    Man *man = new Man();
    Woman *woman = new Woman();
    ObjectStructure *obj = new ObjectStructure();
    Success *success = new Success();

    obj->Attach(man);
    obj->Attach(woman);
    obj->Display(success);

    return 0;
}