#include <iostream>
using namespace std;

class User {

};

class IUser {
public:
    virtual void InsertUser(User*) = 0;
    virtual User GetUser(int) = 0;
};
class SqlserverUser : public IUser {
public:
    void InsertUser(User*);
    User GetUser(int);
};
class AccessUser : public IUser {
public:
    void InsertUser(User*);
    User GetUser(int);
};
class Department {};
class IDepartment {
public:
    virtual void InsertDepartment(Department*) = 0;
    virtual Department GetDepartment(int) = 0;
};
class SqlserverDepartment : public IDepartment{
public:
    void InsertDepartment(Department*);
    Department GetDepartment(int);
};

class AccessDepartment : public IDepartment{
public:
    void InsertDepartment(Department*);
    Department GetDepartment(int);
};
class IFactory {
public:
    virtual IUser* CreateUser() = 0;
    virtual IDepartment* CreateDepartment() = 0;
};
class SqlserverFactory : public IFactory {
public:
    IUser* CreateUser();
    IDepartment* CreateDepartment();
};
class AccessFactory : public IFactory {
public:
    IUser* CreateUser();
    IDepartment* CreateDepartment();
};