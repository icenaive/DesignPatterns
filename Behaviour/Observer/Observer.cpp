#include "Observer.hpp"

int main() {    
    Boss *boss= new Boss();
    StockObserver *stock_observer = new StockObserver("A");
    NbaObserver *nba_observer = new NbaObserver("N");
    boss->SetState("boss is back");

    stock_observer->SetNotifier(boss);
    nba_observer->SetNotifier(boss);
    boss->Attach(stock_observer);
    boss->Attach(nba_observer);
    boss->Notify();

    boss->Detach(nba_observer);
    boss->Notify();

    // delete boss;
    // delete nba_observer;
    // delete stock_observer;


    return 0;
}