#include <map>
#include <string>
#include <iostream>
using namespace std;

class User{
public:
    User() {}
    User(string);
    string GetName();
private:
    string name_;
};

class Website{
public:
    virtual void Use(User*) = 0;
};
class ConcreteWebsite : public Website {
public:
    ConcreteWebsite() {}
    ConcreteWebsite(string);
    void Use(User*);
private:
    string website_name_;
};
class WebsiteFactory {
public:
    ~WebsiteFactory();
    Website *GetWebsiteCategory(string);
    int GetWebsiteCount();
private:
    map<string, Website*> flyweights_;
};