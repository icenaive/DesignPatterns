#include <iostream>
using namespace std;

class Pen {

};
class Graphics {

};
class PersonBuilder {
public:
    PersonBuilder() {}
    virtual ~PersonBuilder() {}
    PersonBuilder(Pen* pen, Graphics* graphics) : pen_(pen), graphics_(graphics) {}
    virtual void build_head() {}
    virtual void build_body() {}
protected:
    Pen *pen_;
    Graphics *graphics_;
};

class PersonThinBuilder : public PersonBuilder {
public:
    PersonThinBuilder(Pen* pen, Graphics* graphics) : PersonBuilder(pen, graphics) {}
    void build_head() {
        cout << "build thin head\n";
    }
    void build_body() {
        cout << "build thin body \n";
    }
};

class PersonFatBuilder : public PersonBuilder {
public:
    PersonFatBuilder(Pen* pen, Graphics* graphics) : PersonBuilder(pen, graphics) {}
    void build_head() {
        cout << "build fat head" << endl;
    }
    void build_body() {
        cout << "build fat body\n";
    }
};
class PersonDirector {
public:
  PersonDirector(PersonBuilder* person_builder) : person_builder_(person_builder) {}
  void CreatePerson() {
      person_builder_->build_body();
      person_builder_->build_head();
  }
private:
    PersonBuilder* person_builder_;
};