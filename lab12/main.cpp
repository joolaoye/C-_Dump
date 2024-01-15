/*
Payroll System

Name: Joshua O Olaoye
starID: ********
Section Number: 03

Description:
This program simulates a Payroll System for XXXX Company. It allows users to create, modify,
delete, and display employee information. The data can be stored in a file named "xxxxx.dat"

* The program creates an Employee Database
* The user is prompted to add a new Employee to the database
* The program continues to prompt the user to add more employees until they respond 'no'
* The program displays a menu and prompts the user to input their choice:
   - If the user selects '1', the program adds a new employee to the database
     The program continues to prompt the user to add more employees until they respond 'no'
   - If the user selects '2', the program modifies the information of an employee based on their ID
     The program continues to prompt the user to modify more employees until they respond 'no'
   - If the user selects '3', the program deletes an employee specified by the user if the employee is in the database
     The program continues to prompt the user to delete more employees until they respond 'no'
   - If the user selects '4', the program displays the database information to the console
   - If the user selects '5', the program saves the database information to an output file and quits
*/

#include <iostream> // Needed for cin and cout
#include <fstream> // Needed for ofstream
#include <iomanip> // Needed for formatting output field
#include "Employee.h" // Needed for the Emloyee class
#include "EmployeeList.h" // Needed for the EmployeeList class

// Global Variables
std::string prompt = "Another employee? y/n --> "; // Prompt for the addNewEmployees function
std::ofstream outFile("xxxxx.dat"); // Output file to save employee information
bool writeToFile = false; // Flag indicating whether to write to console or file

// Function Declarations
void addNewEmployees(EmployeeList&);
void modifyEmployeeData(EmployeeList&);
void deleteEmployees(EmployeeList&);
void displayEmployeeData(const EmployeeList&);


int main()
{
    std::cout << "Create the employee database: " << std::endl << std::endl;

    EmployeeList employeeDatabse; // EmployeeList object representing the Employee Database object
    int userResponse = 1; // User response to the menu

    // Iterate till the user selects 5
    while (userResponse != 5)
    {
        // Add a new Employee if the user selects one
        if (userResponse == 1)
        {
            addNewEmployees(employeeDatabse);
            prompt = "Another one? "; // Change the prompt from default
        }

        // Modify the attributes of an existing Employee in the Database
        else if (userResponse == 2)
        {
            modifyEmployeeData(employeeDatabse);
        }

        // Delete an existing Employee from the Database 
        else if (userResponse == 3)
        {
            deleteEmployees(employeeDatabse);
        }

        // Display the Database information to the console
        else if (userResponse == 4)
        {
            displayEmployeeData(employeeDatabse);
        }

        std::cout << std::endl;

        // Display the Menu Options
        std::cout << "******************************************************" << std::endl;
        std::cout << "**                      Menu                        **" << std::endl;
        std::cout << "** 1. Add new employees to the database.            **" << std::endl;
        std::cout << "** 2. Modify employee data in the data base.        **" << std::endl;
        std::cout << "** 3. Delete employees from the database.           **" << std::endl;
        std::cout << "** 4. Display employee data to the screen.          **" << std::endl;
        std::cout << "** 5. Quit the system                               **" << std::endl;
        std::cout << "******************************************************" << std::endl;

        // Prompt the user for their selection
        std::cout << "Please enter your choice: ";
        std::cin >> userResponse;
        std::cout << std::endl;
    }

    // Write the Database information to an output file
    writeToFile = true;
    displayEmployeeData(employeeDatabse);
    outFile.close();

    // Display the exit message
    std::cout << "Thanks for using XXXX Company Payroll System! All employee" << std::endl;
    std::cout << "information can be viewed in the file \"xxxxx.dat\"" << std::endl;
}

/** 
* Adds new Employees to the database
* @pre A valid reference to an EmployeeList object representing the database
* @post Allows the user to input data for new Employee objects and adds them to the database
*       If an employee with the same ID is already in the database, a message is displayed,
*       and the employee is not added
*/
void addNewEmployees(EmployeeList& database)
{

    Employee newEmployee;
    char response = 'y';

    while (response == 'y' || response == 'Y')
    {
        std::cout << "Enter an employee's data by the order of ID number, first name, last" << std::endl;
        std::cout << "name, rate, hours: " << std::endl;
        std::cin >> newEmployee;
        std::cout << std::endl;

        if  (!database.add(newEmployee))
        {
            std::cout << "This employee has already been in the database." << std::endl;
        };

        std::cout << prompt;
        std::cin >> response;
    }
}

/** 
* Modifies existing Employees attributes in the database
* @pre A valid reference to an EmployeeList object representing the database
* @post Allows the user to input the current ID of an employee whose data needs modification
*       If the specified employee is found in the database, the current data is displayed,
*       and the user is prompted to modify the attributes. If the employee is not found,
*       a message is displayed indicating that there is no such employee
*/
void modifyEmployeeData(EmployeeList& database)
{
    int id;
    char response = 'y';

    while (response == 'y' || response == 'Y')
    {
        std::cout << "Enter employee's current id: ";
        std::cin >> id;

        int index = database.search(id);

        if (index < 0)
        {
            std::cout << "No such employee in the database." << std::endl;
        }

        else
        {
            Employee currentEmployee = database.returnEmployee(index);

            std::cout << std::endl << "This employee has following data: " << std::endl;
            std::cout << currentEmployee << std::endl;

            database.changeInfo(index);
        }

        std::cout << std::endl << "Modify another employee? y/n --> ";
        std::cin >> response;
    }

}

/** 
* Removes existing Employees from the database
* @pre A valid reference to an EmployeeList object representing the database
* @post Allows the user to input data for an employee to be removed from the database
*       If the specified employee is found and removed, a message is displayed,
*       indicating that the employee's data has been deleted. If the employee is not found,
*       a message is displayed indicating that there is no such employee
*/
void deleteEmployees(EmployeeList& database)
{
    Employee employeeOfChoice;
    char response = 'y';

    while (response == 'y' || response == 'Y')
    {
        std::cout << "Enter the employee's data to delete by the order of id, first Name," << std::endl;
        std::cout << "last Name, rate, hours:" << std::endl;
        std::cin >> employeeOfChoice;

        if (!database.remove(employeeOfChoice))
        {
            std::cout << "No such employee.";
        }

        else
        {
            std::cout << "This employee's data is deleted." << std::endl;
        }

        std::cout << std::endl << "Another employee to delete? y/n --> ";
        std::cin >> response;
    }
    
}

/** 
* Displays the information to either the console or file
* @pre A valid constant reference to an EmployeeList object representing the database
* @post Displays employee information, including ID, first name, last name, hourly rate, hours worked,
*       and total wage, either to the console or a file, based on the configuration
*/
void displayEmployeeData(const EmployeeList& database)
{
    if (writeToFile)
    {
        outFile << std::left << std::setw(10) << std::setfill(' ') << "ID" 
                  << std::left << std::setw(15) << std::setfill(' ') << "First Name"
                  << std::left << std::setw(13) << std::setfill(' ') << "Last Name"
                  << std::left << std::setw(7) << std::setfill(' ') << "Rate"
                  << std::left << std::setw(7) << std::setfill(' ') << "Hours"
                  << std::left << std::setw(6) << std::setfill(' ') << "Wage"
                  << std::left << std::endl;

        for (int i = 0; i < database.returnSize(); i++)
        {
            Employee currentEmployee = database.returnEmployee(i);

            outFile << std::setw(10) << std::setfill(' ') << currentEmployee.getID() 
                << std::setw(15) << std::setfill(' ') << currentEmployee.getFirstName()
                << std::setw(13) << std::setfill(' ') << currentEmployee.getLastName()
                << std::setw(7) << std::setfill(' ') << currentEmployee.getRate()
                << std::setw(7) << std::setfill(' ') << currentEmployee.getHours()
                << std::setw(6) << std::setfill(' ') << currentEmployee.getWages() 
                << std::endl;
        }
    }

    else
    {
        std::cout << std::endl << "XXX Company Payroll System:" << std::endl;

        std::cout << std::left << std::setw(10) << std::setfill(' ') << "ID" 
                  << std::left << std::setw(15) << std::setfill(' ') << "First Name"
                  << std::left << std::setw(13) << std::setfill(' ') << "Last Name"
                  << std::left << std::setw(7) << std::setfill(' ') << "Rate"
                  << std::left << std::setw(7) << std::setfill(' ') << "Hours"
                  << std::left << std::setw(6) << std::setfill(' ') << "Wage"
                  << std::left << std::endl;

        for (int i = 0; i < database.returnSize(); i++)
        {
            Employee currentEmployee = database.returnEmployee(i);
            
            std::cout << std::setw(10) << std::setfill(' ') << currentEmployee.getID() 
                      << std::setw(15) << std::setfill(' ') << currentEmployee.getFirstName()
                      << std::setw(13) << std::setfill(' ') << currentEmployee.getLastName()
                      << std::setw(7) << std::setfill(' ') << currentEmployee.getRate()
                      << std::setw(7) << std::setfill(' ') << currentEmployee.getHours()
                      << std::setw(6) << std::setfill(' ') << currentEmployee.getWages() 
                      << std::endl;
        }
    }    
}
