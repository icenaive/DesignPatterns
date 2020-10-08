#include <vector>
#include <iostream>
using namespace std;

class Action;

class Person{
public:
    virtual ~Person() {}
    virtual void Accept(Action*) = 0;
};

class Man : public Person{
public:
    void Accept(Action*);
};

class Woman : public Person{
public:
    void Accept(Action*);
};

class ObjectStructure{
public:
    void Attach(Person*);
    void Detach(Person*);
    void Display(Action*);
private:
    vector<Person*> people;
};

class Action {
public:
    virtual void GetManConclusion(Person*) = 0;
    virtual void GetWomanConclusion(Person*) = 0;
};

class Success : public Action{
public:
    void GetManConclusion(Person*);
    void GetWomanConclusion(Person*);
};
