#include "Mediator.h"

int main() {
    UnitedNationsSecurityCouncil *unsc = new UnitedNationsSecurityCouncil();
    Usa *usa = new Usa(unsc);
    Iraq *iraq = new Iraq(unsc);

    unsc->SetIraq(iraq);
    unsc->SetUsa(usa);

    usa->Declare("stop nuclear");
    iraq->Declare("no nuclear");

    return 0;
}