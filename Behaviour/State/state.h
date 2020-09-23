class State;

class Work {
public:
    Work();
    ~Work();
    void SetState(State *);
    void WriteData();
public:
    int hour_;
    bool finished_;
private:
    State *state_;
};

class State {
public:
    virtual ~State() {}
    virtual void WriteData(Work *) = 0;
};
class WorkingState : public State {
public:
    void WriteData(Work *);
};

class OvertimeState : public State {
public:
    void WriteData(Work *);
};

class SleepingState : public State {
public:
    void WriteData(Work *);
};