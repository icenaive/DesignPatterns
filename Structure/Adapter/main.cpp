#include "adapter.h"
int main() {
    Forward *forward = new Forward("B");
    forward->Attack();
    forward->Defense();

    Center *center = new Center("CR");
    center->Attack();
    center->Defense();

    Translator *translater = new Translator("C");
    translater->Attack();
    translater->Defense();

    delete translater;
    delete center;
    delete forward;
    return 0;
}