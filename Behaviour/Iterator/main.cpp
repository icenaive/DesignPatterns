#include "Iterator.h"

int main() {
    ConcreteAggregate *a = new ConcreteAggregate();
    a->Push("ni ");
    a->Push("hao\n");

    Iterator *it = new ConcreteIterator(a);
    while(!it->IsDone()) {
        cout << it->CurrentItem() << endl;
        it->Next();
    }

    delete it;
    delete a;
    return 0;
}