#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Iterator {
public:
    virtual string First() = 0;
    virtual string Next() = 0;
    virtual bool IsDone() = 0;
    virtual string CurrentItem() = 0;
    virtual ~Iterator() {}
};

class Aggregate {
public:
    virtual Iterator *CreateIterator() = 0;
    virtual void Push(string) = 0;
    virtual string Pop(int) = 0;
    virtual int Count() = 0;
};

class ConcreteIterator : public Iterator {
public:
    ConcreteIterator(Aggregate *);
    string First();
    string Next();
    bool IsDone();
    string CurrentItem();
private:
    Aggregate *aggregate_;
    int index_;
};

class ConcreteAggregate : public Aggregate {
public:
    ConcreteAggregate();
    ~ConcreteAggregate();
    Iterator *CreateIterator();
    int Count();
    void Push(string);
    string Pop(int);
private:
    vector<string> items_;
    Iterator *interator_;
};
