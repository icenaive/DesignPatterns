#include "memento.h"
#include <iostream>
using namespace std;

int StateMemento::GetHp() {
    return hp_;
}
int StateMemento::GetMp() {
    return mp_;
}
GameRole::GameRole() : hp_(100), mp_(100) {}

StateMemento *GameRole::CreateMemento() {
    return new StateMemento(hp_, mp_);
}
void GameRole::StateDisplay() {
    cout << hp_ << " " << mp_ << endl;
}
void GameRole::Fight() {
    hp_ = 0;
    mp_ = 0;
}

void GameRole::RecoverState(StateMemento *memento) {
    hp_= memento->GetHp();
    mp_ = memento->GetMp();
}
StateCaretaker::StateCaretaker(StateMemento *memento) {
    state_memento_ = memento;
}
StateCaretaker::~StateCaretaker() {
    delete state_memento_;
}
StateMemento* StateCaretaker::GetMemento() {
    return state_memento_;
}