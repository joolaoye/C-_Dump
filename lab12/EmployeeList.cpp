// Implementation for the EmployeeList class

#include <iostream> // Needed for cin and cout
#include "EmployeeList.h" // Needed for the EmployeeList class
#include <cstdlib> // Needed for the exit function

/**
* Initializes the data members of an EmployeeList object with default values
* @pre None
* @post An EmployeeList object is created with the number of employees set to 0
*/
EmployeeList::EmployeeList()
{
    this->numEmployees = 0;
}

/** 
* Adds an Employee object to the array if not already present in the database 
* @pre A valid reference to an Employee object
* @post If the input parameter is valid and the Employee is not already in the database,
*       the array and the number of employees are updated
*/
bool EmployeeList::add(Employee& e)
{
    if (numEmployees >= MAX)
    {
        return false;
    }

    for (int i = 0; i < numEmployees; i++)
    {
        if (List[i] == e)
        {
            return false;
        }
    }

    List[numEmployees++] = e;
    return true;
}

/** 
* Removes an existing Employee object from the database 
* @pre A valid reference to an Employee object
* @post If the input parameter is valid and the Employee is already in the database,
*       the array and the number of Employees are updated. The removed Employee is replaced
*       by shifting the subsequent elements in the array
*/
bool EmployeeList::remove(Employee& e)
{
    int index = -1;

    for (int i = 0; i < numEmployees; i++)
    {
        if (List[i] == e)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        return false;
    } 
    
    for (int i = index; i < numEmployees - 1; i++)
    {
        List[i] = List[i + 1];
    }

    List[numEmployees - 1] = Employee();
    numEmployees--;
    return true;
}

/** 
* Modifies the attributes of an existing Employee object in the database 
* @pre A valid index to an Employee object
* @post The attributes of the Employee at the specified index may be modified based on user input.
*       The user is prompted to change the ID, first name, last name, hourly rate, and hours worked.
*       If the user chooses to modify a specific attribute, the corresponding setter method is called
*       to update the Employee's information
*/
void EmployeeList::changeInfo(int index)
{
    if (index >= numEmployees)
    {
        std::cout<< "No Change because of invalid index." << std::endl;
        return;
    }
	
    int id;
    std::string firstName, lastName;
    double hours, rate;

    char answer;
    
    std::cout << "Change id? y/n --> ";
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        std::cout <<"Enter new ID: ";
        std::cin >> id;
        List[index].setId(id);
        std::cout << "The Id has been changed." << std::endl;
    }
    
    std::cout << std::endl;
    
    std::cout << "Change first name? y/n --> ";
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        std::cout << "Enter new first name: ";
        std::cin >> firstName;
        List[index].setFirstName(firstName);
        std::cout << "The first name has been changed." << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << "Change last name? y/n --> ";
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        std::cout <<"Enter new last name: ";
        std::cin >> lastName;
        List[index].setLastName(lastName);
        std::cout << "The last name has been changed." << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << "Change rate? y/n --> ";
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        std::cout <<"Enter new rate: ";
        std::cin >> rate;
        List[index].setRate(rate);
        std::cout << "The rate has been changed." << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << "Change hours worked? y/n --> ";
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        std::cout <<"Enter new hours: ";
        std::cin >> hours;
        List[index].setHours(hours);
        std::cout << "The hours has been changed." << std::endl;
    }
}

/** 
* Searches for an Employee in the database and returns the index if found
* @pre A valid ID for an Employee object
* @post If the Employee with the specified ID is in the Database,
*       the function returns the index of the Employee; otherwise, it returns -1
*/
int EmployeeList::search(int id) const
{
    for (int i = 0; i < numEmployees; i++)
    {
        if (List[i].getID() == id)
        {
            return i;
        }
    }   

    return -1;
}

/** 
* Returns the number of Employees in the Database
* @pre None
* @post Returns the number of Employees in the Database
*/
int EmployeeList::returnSize() const
{
    return numEmployees;
}

/** 
* Returns Employees at an index 
* @pre A valid index for an Employee in the array
* @post Returns the Employee located at the specified index
*       If the index is not valid, the program terminates with an error message
*/
Employee EmployeeList::returnEmployee(int index) const
{
    if (index < 0 || index >= this->numEmployees)
    {
        std::cout << "Invalid index" << std::endl;
        exit(EXIT_FAILURE);
    }

    return List[index];
}
