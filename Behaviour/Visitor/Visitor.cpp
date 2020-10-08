#include "Visitor.h"

void Man::Accept(Action *action) {
    action->GetManConclusion(this);
}
void Woman::Accept(Action *action) {
    action->GetWomanConclusion(this);
}
void ObjectStructure::Attach(Person *person) {
    people.push_back(person);
}

void ObjectStructure::Detach(Person *person) {
    for(auto it = people.begin(); it != people.end(); ++it) {
        if(*it == person) {
            people.erase(it);
            return;
        }
    }
}

void ObjectStructure::Display(Action *action) {
    for(auto it = people.begin(); it != people.end(); ++it) {
        (*it)->Accept(action);
    }
}

void Success::GetManConclusion(Person *person) {
    cout << "man get success " << endl;
}

void Success::GetWomanConclusion(Person *person) {
    cout << "woman get success" << endl;
}