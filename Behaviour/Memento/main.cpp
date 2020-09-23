#include "memento.h"

int main() {
    GameRole *game_role = new GameRole();
    StateCaretaker *state_caretaker = new StateCaretaker(game_role->CreateMemento());
    game_role->StateDisplay();

    game_role->Fight();
    game_role->StateDisplay();

    game_role->RecoverState(state_caretaker->GetMemento());
    game_role->StateDisplay();

    delete state_caretaker;
    delete game_role;


    return 0;
}