#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Context {
public:
    void SetText(string );
    string GetText();
private:
    string text_;
};

class Expression {
public:
    virtual ~Expression() {}
    void Interprete(Context*);

protected:
    virtual void Excute(std::string, double) = 0;
};

class Scale : public Expression {
private:
    void Excute(string, double);
};

class Note: public Expression {
private:
    void Excute(std::string, double);
};
class ExpressionFactory {
public:
    Expression* CreateExpression(Context*);
};