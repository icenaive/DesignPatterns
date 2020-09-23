#include "state.h"
int main() {
    Work *work = new Work();
    work->hour_ = 15;
    work->WriteData();
    work->hour_ = 20;
    work->WriteData();
    work->finished_ = true;
    work->WriteData();
    delete work;

    return 0;
}