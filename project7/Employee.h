#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>


class Employee{
    int id;
    std::string firstName,lastName;
    double rate, hours;
public:
    Employee();
    Employee(int id, std::string firstName, std::string lastName, double rate, double hours);
    void setLastName(std::string lastName);
    void setFirstName(std::string firstName);
    void setID(int id);
    void setRate(double rate);
    void setHours(double hours);

    std::string getLastName();
    std::string getFirstName();
    int getID();
    double getRate();
    double getHours();
    double getWages();

    bool operator == (const Employee&);
    bool operator != (const Employee&);

    friend std::ostream& operator << (std::ostream& outputStream, const Employee&);
    friend std::istream& operator >> (std::istream& inputStream, Employee&);


};

#endif // EMPLOYEE_H