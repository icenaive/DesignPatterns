#include "state.h"
#include <iostream>
using namespace std;

Work::Work() {
    state_ = new WorkingState();
}

Work::~Work() {
    delete state_;
}

void Work::SetState(State *state) {
    delete state_;
    state_ = state;
}
void Work::WriteData() {
    state_->WriteData(this);
}

void WorkingState::WriteData(Work *work) {
    if(work->hour_ < 17) {
        cout << work->hour_ << " working\n";
    } else {
        work->SetState(new OvertimeState());
        work->WriteData();
    }
}
void OvertimeState::WriteData(Work *work) {
    if(work->finished_) {
        work->SetState(new SleepingState());
        work->WriteData();
    } else if(work->hour_ < 21) {
        cout << work->hour_ << " over time \n";
    } else {
        work->SetState(new SleepingState()) ;
        work->WriteData();
    }
}
void SleepingState::WriteData(Work *work) {
  cout << work->hour_ << " : sleeping" << endl;
}