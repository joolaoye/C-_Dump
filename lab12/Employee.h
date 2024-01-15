// Header file for the Employee class

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // Needed for string

/**
 * @brief Represents an Employee with attributes such as ID, first name, last name, hourly rate, and hours worked
 */
class Employee
{
private:
    int id; /**< The ID of the Employee */
    std::string firstName; /**< The first name of the Employee */
    std::string lastName; /**< The last name of the Employee */
    double rate; /**< The hourly rate of the Employee */
    double hours; /**< The hours worked of the Employee */

public:
    // Constructors
    Employee();
    Employee(int, std::string, std::string, double, double);

    // Setter methods
    void setLastName(std::string);
    void setFirstName(std::string);
    void setId(int);
    void setRate(double);
    void setHours(double);

    // Getter methods
    std::string getLastName() const;
    std::string getFirstName() const;
    int getID() const;
    double getRate() const;
    double getHours() const;
    double getWages() const;

    // Operator overloads
    bool operator== (const Employee&);
    bool operator!= (const Employee&);

    // Friend functions for stream operators
    friend std::ostream& operator<< (std::ostream&, const Employee&);
    friend std::istream& operator>> (std::istream&, Employee&);
};

#endif // EMPLOYEE_H
