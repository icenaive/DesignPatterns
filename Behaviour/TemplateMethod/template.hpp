#include <string>
#include <iostream>
using namespace std;

class TestPaper {
public:
    void question() {
        cout << "this answert is " << answer() << endl;
    }
protected:
    virtual string answer() = 0;
};

class Student1 : public TestPaper {
public:
    string answer() {
        return "2NB";
    }
};
class Student2 : public TestPaper {
public:
    string answer() {
        return "1NB";
    }
};