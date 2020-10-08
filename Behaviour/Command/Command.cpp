#include "Command.h"

void Barbecuer::BakeMutton() {
    cout << "bake mutton\n";
}

void Barbecuer::BakeChicken() {
    cout << "bake chicken\n";
}
Command::Command(Barbecuer *barbecuer): barbecuer_(barbecuer) {}
BakeMuttonCommand::BakeMuttonCommand(Barbecuer *barbecuer): Command(barbecuer) {}
void BakeMuttonCommand::ExecuteCommand() {
    barbecuer_->BakeMutton();
}
BakeChickenCommand::BakeChickenCommand(Barbecuer *barbecuer): Command(barbecuer) {}
void BakeChickenCommand::ExecuteCommand() {
    barbecuer_->BakeChicken();
}

void Waiter::SetOrder(Command *command) {
    if(dynamic_cast<BakeChickenCommand*>(command)) {
        cout << "chicken sold out" << endl;
    } else {
        commands_.push_back(command);
        cout << "add: " << string(typeid(*command).name()).substr(2) << endl;
    }
}
void Waiter::CancelOrder(Command* command) {
    for(auto it = commands_.begin(); it != commands_.end(); ++it) {
        if(*it == command) {
            commands_.erase(it);
            cout << "cancel : " << string(typeid(*command).name()).substr(2) << endl;
            return ;
        }
    }
}

void Waiter::Notify() {
    for(auto it = commands_.begin(); it != commands_.end(); ++it) {
        (*it)->ExecuteCommand();
    }
}