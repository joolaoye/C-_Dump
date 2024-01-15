// Implementation file for the Rectangle class.
// This version has a constructor that accepts arguments.
#include "Employee.h"   // Needed for the Rectangle class
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function

//***********************************************************
// The constructor accepts arguments for width and length.  *
//***********************************************************

Employee :: Employee()
{
   id = 0; 
   firstName = "";
   lastName = "";
   rate = 0;
   hours = 0;
   wage = 0;
}

Employee::Employee(int id, std::string firstName, std::string lastName, double rate, double hours)
{
   this-> id = id; 
   this-> firstName = firstName;
   this-> lastName = lastName;
   this-> rate = rate;
   this-> hours = hours;
}

//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Employee::setLastName(std::string name)
{
   if (name != "")
      this-> lastName = name;
   else
   {
      std::cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}


void Employee::setFirstName(std::string name)
{
   if (name != "")
      this-> firstName = name;
   else
   {
      std::cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}

void Employee::setId(int value)
{
   if (value > 0)
      this-> id = value;
   else
   {
      std::cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}

void Employee::setRate(double value)
{
   if (value > 0)
      this-> rate = value;
   else
   {
      std::cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}

void Employee::setHours(double value)
{
   if (value > 0)
      this-> hours = value;
   else
   {
      std::cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

std::string Employee::getFirstName() const
{
   return firstName;
}

std::string Employee::getLastName() const
{
   return lastName;
}

int Employee::getId() const
{
   return id;
}

double Employee::getRate() const
{
   return rate;
}

double Employee::getHours() const
{
   return hours;
}

double Employee::getWages() const
{
   return rate * hours;
}

bool Employee::operator==(const Employee& e)
{
    return (id == e.id && 
	   firstName == e.firstName && 
	   lastName == e.lastName &&
	   rate == e.rate &&
	   hours == e.hours &&
      wage == e.wage);   
}	

bool Employee::operator!=(const Employee& e)
{
    return (!(id == e.id && 
	   firstName == e.firstName && 
	   lastName == e.lastName &&
	   rate == e.rate &&
	   hours == e.hours &&
      wage == e.wage));

     

}	

std::ostream& operator<< (std::ostream& strm, const Employee& e)
{
    strm << e.getId() << " "
        << e.getFirstName() << " " 
        << e.getLastName() << " " 
        << e.getRate() << " "
        << e.getHours() << " "
        << e.getWages();
 
    return strm;
}

std::istream& operator>> (std::istream& strm, Employee& e)
{
    strm >> e.id
        >> e.firstName 
        >> e.lastName  
        >> e.rate
        >>e.hours
        >> e.wage;
 
    return strm;
}