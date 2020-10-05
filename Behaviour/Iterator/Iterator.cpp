#include "Iterator.h"

ConcreteIterator::ConcreteIterator(Aggregate *a) {
    index_ = 0;
    aggregate_ = a;
}

string ConcreteIterator::First() { return aggregate_->Pop(0); }
string ConcreteIterator::Next() {
    string str;
    index_++;
    if(index_ < aggregate_->Count()) str = aggregate_->Pop(index_);
    return str;
}
bool ConcreteIterator::IsDone() {
    return index_ >= aggregate_->Count();
}
string ConcreteIterator::CurrentItem() { return aggregate_->Pop(index_); }

ConcreteAggregate::ConcreteAggregate() {
    interator_ = nullptr;
    items_.clear();
}
ConcreteAggregate::~ConcreteAggregate() {
    if(interator_) {
        delete interator_;
        interator_ = nullptr;
    }
}
Iterator* ConcreteAggregate::CreateIterator() {
    if(interator_ == nullptr) interator_ = new ConcreteIterator(this);
    return interator_;
}

int ConcreteAggregate::Count() { return items_.size();}
void ConcreteAggregate::Push(string s) { items_.push_back(s); }
string ConcreteAggregate::Pop(int index) {
    string str;
    if(index < Count()) {
        str = items_[index];
    }
    return str;
}