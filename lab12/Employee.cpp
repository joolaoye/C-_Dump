// Implementation file for the Employee class

#include "Employee.h" // Needed for the Employee class
#include <iostream> // Needed for cout
#include <cstdlib> // Needed for the exit function


/**
* Initializes the data members of an Employee object with default values
* @pre None
* @post The Employee object is created with default values for its attributes
*/
Employee :: Employee()
{
   this->id = 0; 
   this->firstName = "";
   this->lastName = "";
   this->rate = 0;
   this->hours = 0;
}

/**
 * Initializes the data members of an Employee object with the provided input parameters
 * @pre Valid input parameters for the id, first name, last name, rate, and hours
 * @post The Employee object is created with the provided input parameters for its attributes
 */
Employee::Employee(int id, std::string firstName, std::string lastName, double rate, double hours)
{
   this-> id = id; 
   this-> firstName = firstName;
   this-> lastName = lastName;
   this-> rate = rate;
   this-> hours = hours;
}

/**
 * Updates the last name of the Employee with the provided input parameter
 * @pre A valid non-empty input parameter for the last name
 * @post The Employee's last name is updated with the provided input parameter
 *
 * If the input parameter is an empty string, an error message is displayed, and the program exits
 */
void Employee::setLastName(std::string name)
{
   if (name != "")
   {
      this-> lastName = name;
   }

   else
   {
      std::cout << "Invalid last name" << std::endl;
      exit(EXIT_FAILURE);
   }
}

/**
 * Updates the first name of the Employee with the provided input parameter
 * @pre A valid non-empty input parameter for the first name
 * @post The Employee's first name is updated with the provided input parameter
 *
 * If the input parameter is an empty string, an error message is displayed, and the program exits
 */
void Employee::setFirstName(std::string name)
{
   if (name != "")
   {
      this-> firstName = name;
   }

   else
   {
      std::cout << "Invalid first name" << std::endl;
      exit(EXIT_FAILURE);
   }
}

/**
 * Updates the ID of the Employee with the provided whole number input parameter
 * @pre A valid positive whole number input parameter for the ID
 * @post The Employee's ID is updated with the provided input parameter
 *
 * If the input parameter is not a positive whole number, an error message is displayed, and the program exits
 */
void Employee::setId(int value)
{
   if (value > 0)
   {
      this-> id = value;
   }

   else
   {
      std::cout << "Invalid ID" << std::endl;
      exit(EXIT_FAILURE);
   }
}

/**
 * Updates the hourly rate of the Employee with the provided positive real number input parameter
 * @pre A valid positive real number input parameter for the hourly rate
 * @post The Employee's hourly rate is updated with the provided input parameter
 * If the input parameter is not a positive real number, an error message is displayed, and the program exits
 */
void Employee::setRate(double value)
{
   if (value > 0)
   {
      this-> rate = value;
   }

   else
   {
      std::cout << "Invalid hourly rate" << std::endl;
      exit(EXIT_FAILURE);
   }
}

/**
 * Updates the hourly rate of the Employee with the provided positive real number input parameter
 * @pre A valid positive real number input parameter for the hours worked
 * @post The Employee's hours worked is updated with the provided input parameter
 * If the input parameter is not a positive real number, an error message is displayed, and the program exits
 */
void Employee::setHours(double value)
{
   if (value > 0)
   {
      this-> hours = value;
   }

   else
   {
      std::cout << "Invalid hours worked" << std::endl;
      exit(EXIT_FAILURE);
   }
}

/**
 * Returns the last name of the Employee
 * @pre None
 * @post Returns the last name of the Employee
 */
std::string Employee::getLastName() const
{
   return this->lastName;
}

/**
 * Returns the first name of the Employee
 * @pre None
 * @post Returns the first name of the Employee
 */
std::string Employee::getFirstName() const
{
   return this->firstName;
}

/**
 * Returns the ID of the Employee
 * @pre None
 * @post Returns the ID of the Employee
 */
int Employee::getID() const
{
   return this->id;
}

/**
 * Returns the hourly rate of the Employee
 * @pre None
 * @post Returns the hourly rate of the Employee
 */
double Employee::getRate() const
{
   return this->rate;
}

/**
 * Returns the hours worked of the Employee
 * @pre None
 * @post Returns the hours worked of the Employee
 */
double Employee::getHours() const
{
   return hours;
}

/**
 * Calculates and returns the wages of the Employee
 * @pre None
 * @post Calculates and returns the wages of the Employee
 */
double Employee::getWages() const
{
   return this->rate * this->hours;
}

/**
 * Compares two Employee objects for equality based on their attributes,
 * including ID, first name, last name, hourly rate, worked hours, and total wage
 * @pre Both Employee objects should be valid and properly initialized
 * @post The function returns true if all corresponding attributes of the two
 *       Employee objects are equal, indicating that the objects are identical
 *       Otherwise, it returns false
 */
bool Employee::operator== (const Employee& e)
{
   return (this->id == e.id && 
	   this->firstName == e.firstName && 
	   this->lastName == e.lastName &&
	   this->rate == e.rate &&
	   this->hours == e.hours);   
}	

/**
 * Compares two Employee objects for inequality based on their attributes,
 * including ID, first name, last name, hourly rate, worked hours, and total wage
 * @pre Both Employee objects should be valid and properly initialized
 * @post The function returns false if all corresponding attributes of the two
 *       Employee objects are equal, indicating that the objects are identical
 *       Otherwise, it returns true
 */
bool Employee::operator!= (const Employee& e)
{
   return (!(this->id == e.id && 
	   this->firstName == e.firstName && 
	   this->lastName == e.lastName &&
	   this->rate == e.rate &&
	   this->hours == e.hours));
}	

/**
 * Outputs the attributes of an Employee object to the specified output stream,
 * including ID, first name, last name, hourly rate, worked hours, and total wage
 * @pre Both the Employee object and the output stream should be valid and properly initialized
 * @post The Employee's attributes, including ID, first name, last name, hourly rate,
 *       worked hours, and total wage, are displayed to the specified output stream
 */
std::ostream& operator<< (std::ostream& strm, const Employee& e)
{
   strm << e.id << " "
      << e.firstName << " " 
      << e.lastName << " " 
      << e.rate << " "
      << e.hours << " "
      << e.getWages();
 
   return strm;
}

/**
 * Extracts the attributes of an Employee object from the specified input stream,
 * including ID, first name, last name, hourly rate, worked hours, and total wage
 * @pre Both the Employee object and the input stream should be valid and properly initialized
 * @post The Employee's attributes, including ID, first name, last name, hourly rate,
 *       worked hours, and total wage, are extracted from the specified input stream
 *       and stored in the provided Employee object
 */
std::istream& operator>> (std::istream& strm, Employee& e)
{
   strm >> e.id;
   strm >> e.firstName;
   strm >> e.lastName;
   strm >> e.rate;
   strm >> e.hours;
 
   return strm;
}
