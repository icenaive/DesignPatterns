class StateMemento {
public:
    StateMemento() {}
    StateMemento(int hp, int mp) : hp_(hp), mp_(mp) {}
    int GetHp();
    int GetMp();
private:
    int hp_;
    int mp_;
};

class GameRole {
public:
    GameRole();
    StateMemento *CreateMemento();
    void StateDisplay();
    void Fight();
    void RecoverState(StateMemento*);
private:
    int hp_;
    int mp_;
};

class StateCaretaker {
public:
    StateCaretaker();
    StateCaretaker(StateMemento*);
    ~StateCaretaker();
    StateMemento* GetMemento();
private:
    StateMemento *state_memento_;
};