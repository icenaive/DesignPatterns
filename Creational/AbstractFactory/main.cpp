#include "abstract_factory.h"

int main() {
    IFactory *i_factory = new SqlserverFactory();
    
    IUser *i_user = i_factory->CreateUser();
    i_user->InsertUser(new User());
    i_user->GetUser(1);

    IDepartment *i_department = new SqlserverDepartment();
    i_department->InsertDepartment(new Department());
    i_department->GetDepartment(1);

    i_factory = new AccessFactory();
    i_user = i_factory->CreateUser();
    i_user->GetUser(1);

    i_department = new AccessDepartment();
    i_department->InsertDepartment(new Department());
    i_department->GetDepartment(1);

    delete i_department;
    delete i_user;
    delete i_factory;
    return 0;
    return 0;
}