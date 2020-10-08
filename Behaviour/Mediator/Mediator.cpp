#include "Mediator.h"

void UnitedNationsSecurityCouncil::SetUsa(Country *usa) {
    usa_ = usa;
}

void UnitedNationsSecurityCouncil::SetIraq(Country *iraq) {
    iraq_ = iraq;
}

void UnitedNationsSecurityCouncil::Declare(string message, Country *country) {
    if(country == usa_) iraq_->GetMessage(message);
    else usa_->GetMessage(message);
}

Country::Country(UnitedNations *mediator): mediator_(mediator) {}
Usa::Usa(UnitedNations *mediator): Country(mediator) {}

void Usa::Declare(string message) {
    mediator_->Declare(message, this);
}

void Usa::GetMessage(string message) {
    cout << "usa got " << message << endl;
}

Iraq::Iraq(UnitedNations *mediator): Country(mediator) {}
void Iraq::Declare(string message) {
    mediator_->Declare(message, this);
}
void Iraq::GetMessage(string message) {
    cout << "Iraq got " << message << endl;
}