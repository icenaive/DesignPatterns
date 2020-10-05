#include "adapter.h"

void Forward::Attack() {
    cout << "forward" << name_ << "attack" << endl;
}

void Forward::Defense() {
    cout << "forward" << name_ << "defense" << endl;
}

void Center::Attack() {
    cout << "center" << name_ << "attack" << endl;
}
void Center::Defense() {
    cout << "center" << name_ << "defense" << endl;
}

void ForeignCenter::Gong() {
    cout << "foreign center" << name_ << "gong" << endl;
}
void ForeignCenter::Shou() {
    cout << "foreign center" << name_ << "shou" << endl;
}

Translator::Translator(string name) : Player(name) {
    foreign_center_ = new ForeignCenter(name);
}
Translator::~Translator() { delete foreign_center_; }
void Translator::Attack() { foreign_center_->Gong();}
void Translator::Defense() { foreign_center_->Shou();}