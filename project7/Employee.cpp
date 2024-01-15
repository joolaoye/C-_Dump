#include "Employee.h"
#include <iostream>
#include <iomanip>

Employee::Employee(){
    this->id = 0;
    this->firstName = "";
    this->lastName = "";
    this->rate = 0;
    this->hours = 0;
}


Employee::Employee(int id, std::string firstName, std::string lastName, double rate, double hours){
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->rate = rate;
    this->hours = hours;
}


void Employee::setLastName(std::string lastName){
    this->lastName = lastName;
}


void Employee::setFirstName(std::string firstName){
    this->firstName = firstName;
}


void Employee::setID(int id){
    this->id = id;
}


void Employee::setRate(double rate){
    this->rate = rate;
}


void Employee::setHours(double hours){
    this->hours = hours;
}


int Employee::getID(){
    return this->id;
}


double Employee::getRate(){
    return this->rate;
}


double Employee::getHours(){
    return this->hours;
}


double Employee::getWages(){
    return this->rate * this->hours;
}


bool Employee::operator == (const Employee& employee){
    return (
        this->id == employee.id
        && this->firstName == employee.firstName
        &&  this->lastName == employee.lastName
        && this->rate == employee.rate
        && this->hours == employee.hours
    );
}


bool Employee::operator != (const Employee& employee){
    return !(
        this->id == employee.id
        && this->firstName == employee.firstName
        &&  this->lastName == employee.lastName
        && this->rate == employee.rate
        && this->hours == employee.hours
    );
}


std::ostream& operator << (std::ostream& outputStream, const Employee& employee){
    outputStream << std::left << std::setw(10) << std::setfill(' ') << employee.id
        << std::left << std::setw(10) << std::setfill(' ') << employee.firstName
        << std::left << std::setw(10) << std::setfill(' ') << employee.lastName
        << std::left << std::setw(10) << std::setfill(' ') << employee.rate
        << std::left << std::setw(10) << std::setfill(' ') << employee.hours << std::endl;

    return outputStream;
}


std::istream& operator >> (std::istream& inputStream, Employee& employee){
    std::cout << "Enter the employee's data to delete by the order of id, first Name," << std::endl;
    std::cout << "last Name, rate, hours:" << std::endl;

    inputStream >> employee.id >> employee.firstName >> employee.lastName
    >> employee.rate >> employee.hours; 

    return inputStream;
}