#include <string>
#include <iostream>


class Person {
public:
    Person() {}
    Person(std::string name) : name_(name) {}
    virtual void show();
protected:
    std::string name_;
};

class Finery : public Person {
public:
    Finery() = default;
    Finery(Person *);
    void show();
protected:
    Person *base_;
};

class Tie : public Finery{
public:
    Tie() = default;
    Tie(Person*);
    void show();
};


class Suit : public Finery{
public:
    Suit() = default;;
    Suit(Person*);
    void show();
};

class Shoes : public Finery{
public:
    Shoes() = default;
    Shoes(Person*);
    void show();
};

void Person::show() {
    std::cout << name_ << std::endl;
}
Finery::Finery(Person *base): base_(base) {}
void Finery::show() {
    if(!base_) {
        base_->show();
    }
}

Tie::Tie(Person* base) : Finery(base) {}
void Tie::show() {
    std::cout << "Tie ";
    base_->show();
}
Suit::Suit(Person* base) : Finery(base) {}
void Suit::show() {
    std::cout << "Suit ";
    base_->show();
}
Shoes::Shoes(Person *base) : Finery(base) {}
void Shoes::show() {
    std::cout << "Shoes ";
    base_->show();
}