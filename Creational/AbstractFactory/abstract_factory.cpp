#include "abstract_factory.h"

void SqlserverUser::InsertUser(User* user) {
    cout << "SqlserverUser insert user with user" << endl;
}
User SqlserverUser::GetUser(int id) {
    cout << "SqlserverUser get user with id" << endl;
    return User();
}


void AccessUser::InsertUser(User* user) {
    cout << "AccessUser insert user with user" << endl;
}
User AccessUser::GetUser(int id) {
    cout << "AccessUser get user with id" << endl;
    return User();
}
void SqlserverDepartment::InsertDepartment(Department *department) {
    cout << "Insert Department into Sqlserver" << endl;
}
Department SqlserverDepartment::GetDepartment(int id) {
    cout << "Get Department from Sqlserver" << endl;
    return Department();
}
void AccessDepartment::InsertDepartment(Department* department) {
  cout << "Insert Department into Access" << endl;
}

Department AccessDepartment::GetDepartment(int id) {
  cout << "Get Department from Access" << endl;
  return Department();
}
IUser *SqlserverFactory::CreateUser() {
    return new SqlserverUser();
}
IDepartment* SqlserverFactory::CreateDepartment() {
    return new SqlserverDepartment();
}
IUser* AccessFactory::CreateUser() {
    return new AccessUser();
}
IDepartment* AccessFactory::CreateDepartment() {
    return new AccessDepartment();
}