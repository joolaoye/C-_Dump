#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <iostream>


class Employee{
    int id;
    std::string firstName, lastName;
    double rate, hours, wage;

public:
    Employee();

    Employee(int id, std::string firstName, std::string lastName, double rate, double hours);
    void setLastName(std::string name);
    void setFirstName(std::string name);
    void setId(int value);
    void setRate(double value);
    void setHours(double value);

    std::string getLastName() const;
    std::string getFirstName() const;
    int getId() const;
    double getRate() const;
    double getHours() const;
    double getWages() const;

    bool operator== (const Employee&);
    bool operator!= (const Employee&);
    friend std::ostream& operator<< (std::ostream&, const Employee&);
    friend std::istream& operator>> (std::istream&, Employee&);
};

#endif