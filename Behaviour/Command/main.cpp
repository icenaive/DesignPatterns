#include "Command.h"

int main() {
    Barbecuer *barbecur = new Barbecuer();
    BakeMuttonCommand *bake_mutton_command1 = new BakeMuttonCommand(barbecur);
    BakeChickenCommand *bake_chicken_command = new BakeChickenCommand(barbecur);
    Waiter *waiter = new Waiter();
    waiter->SetOrder(bake_mutton_command1);
    waiter->SetOrder(bake_chicken_command);
    waiter->Notify();
    waiter->CancelOrder(bake_chicken_command);
    waiter->Notify();
    return 0;
}