// Header file for the EmployeeList class

#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include "Employee.h" // Needed for the Emloyee class

// Maximum numbers of Employees
const int MAX = 100;

/**
 * @brief Represents a database of Employees with attributes such as the number of employees
 * and an array for storing Employee objects
 */
class EmployeeList
{
private:
    int numEmployees; /**< The number of Employees in the Database */
    Employee List[MAX]; /**< The array that stores the Employees */

public:
    // Constructor
    EmployeeList();

    // Modifiers
    bool add(Employee&);
    bool remove(Employee&);
    void changeInfo(int);

    // Getters 
    int search(int) const;
    int returnSize() const;
    Employee returnEmployee(int) const;
};


#endif // EMPLOYEELIST_H
