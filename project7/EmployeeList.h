#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include "Employee.h"

const int MAX = 100;

class EmployeeList
{
    int size;
    Employee employeeList[MAX];
public: 
    EmployeeList();
    bool addEmployee(const Employee&);
    bool deleteEmployee(const Employee&);
    int searchEmployeeList(int ID);
    void modifyEmployee(int index);
    int returnSize();
    Employee returnEmployee(int index);
};


#endif // EMPLOYEELIST_H