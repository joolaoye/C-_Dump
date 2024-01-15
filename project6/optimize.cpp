/*
Pay roll System

Build Employee Database
    * The program asks the user to enter an employee’s ID, hours worked and hourly pay rate
    * The program calculates the gross wage for that employee by computing the product of hours worked and hourly pay
    * The program stores this information in arrays and writes it to an output file
    * The program asks the user if they want to calculate the gross wage for another employee. 
      It only responds to input ‘y’ or ‘n’
    * If the user enters 'n', the program displays instructions on how to access the 
      file containing the employee data and then proceeds to the next section of the program
    * Else if user enters ‘y’, the program repeats the steps 1 through 4
    * Else the program exits abruptly

Display Employee Database
    * The program prompts the user for an option from 1 through 6 
    * If the user enters '1', the program displays a well-formatted table
      of the employees' information in the order they were entered
    * If the user enters '2', the program displays a well-formatted table
      of the employees' information in ascending order of their ids
    * If the user enters '3', the program displays a well-formatted table
      of the employees' information in ascending order of their hourly rates
    * If the user enters '4', the program displays a well-formatted table
      of the employees' information in ascending order of their hours worked
    * If the user enters '5', the program displays a well-formatted table
      of the employees' information in ascending order of their wages
    * If the user enters '6', the program displays an exit message and terminates

Name: Joshua O Olaoye
StarID: ********
Section Number: 03
*/

#include <iostream> // for I/O operations
#include <iomanip> // for formatting output field
#include <fstream> // for file handling
#include <cmath> // for rounding up values

const int SIZE = 20; // Maximum size for arrays

// Function prototypes
void getEmployeeInfor(int& employee_id, double& pay_rate, double& hours_worked, int employee_ids[], double pay_rates[],
                      double hours[], int length);
double calcWage(double pay_rate, double hours_worked, double Wages[], int& length);
void printWages(std::ofstream& outFile, int employee_id, double pay_rate, double hours_worked, double gross_wage);
void displayWages(int ids[], double prs[], double hws[], double wages[], int index);
void selection_sort(int ids[], double prs[], double hws[], double wages[], int index, bool sort_id, bool sort_pr, bool sort_hw,
                    bool sort_wages);

int main()
{
    int id; // Employee's ID
    double pay; // Employee's hourly pay rate
    double hours; // Employee's hours worked
    double gross_wage; // Employee's gross_wage
    char user_response; // User response (y/n) for if they want to calculate another employee’s wage
    int choice; // user response (1 ~ 6) for the menu that displays employees' information
    int ids[SIZE]; // The array that tracks each employee's id
    double hourly_rates[SIZE]; // The array that tracks each employee's hourly rate
    double hours_worked[SIZE]; // The array that tracks of the hours each employee worked
    double Wages[SIZE]; // The array that tracks each employee's wages
    int employee_size = 0; // Variable keeps track of employees' size

    // Build Employee Database starts here
    {
        std::cout << "-- XXXXXX Payroll System --" << std::endl << std::endl;

        std::cout << "Build Employee Database" << std::endl << std::endl << std::endl << std::endl;

        std::ofstream file("employeeWages.dat"); // Creates and open a new output file "employeeWages.dat"

        // Display header row
        file << std::right << std::setw(10) << std::setfill(' ');
        file << "ID";
        file << std::right << std::setw(15) << std::setfill(' ');
        file << "Hourly Rate";
        file << std::right << std::setw(10) << std::setfill(' ');
        file << "Hours";
        file << std::right << std::setw(15) << std::setfill(' ');
        file << "Wage";

        // End header row
        file << std::endl;

        // Display the separator line
        file << std::right << std::setw(50) << std::setfill('-');
        file << "-";

        // End seperator line
        file << std::endl;

        // Loop to keep calculating employee wages until the user ends the program
        while (true)
        {
            // Get the employee’s ID, hours worked and hourly pay rate
            getEmployeeInfor(id, pay, hours, ids, hourly_rates, hours_worked, employee_size);

            // Calculate the employee's wage
            gross_wage = calcWage(pay, hours, Wages, employee_size);

            // Write the employees information to the output file
            printWages(file, id, pay, hours, gross_wage);

            std::cout << std::endl;

            // Prompt user if they want to calculate another employee's gross wage
            std::cout << "Do you want to calculate another employee's gross wage? ";
            std::cin >> user_response;

            std::cout << std::endl;

            // Check if the user responded with 'n' to exit the loop
            if (user_response == 'n')
            {
                // Exit the loop
                break;
            }
            // Check if the user responded with anything other than 'y' or 'n'
            else if (user_response != 'y')
            {
                // Close the file
                file.close();

                // Exit the program with an error code indicating abnormal termination
                return 1;
            }
        }

        // Close the file
        file.close();

        // Display to the user where to access the employee's information
        std::cout << "The result is reported to the file \"employeeWages.dat\"" << std::endl;
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    }
    // Build Employee Database ends here


    // Display Employee Data starts here
    {
        std::cout << std::fixed << std::setprecision(1);

        // Loop iterates till user selects option 6
        while (true)
        {
            // Display the menu options to the user
            std::cout << "-- XXXXXX Payroll System --" << std::endl << std::endl;
            std::cout << "Display Employee Data" << std::endl << std::endl << std::endl;
            std::cout << "\t1. Display employees' information to screen" << std::endl << std::endl;
            std::cout << "\t2. Display employees' information to screen according the order of ID" << std::endl << std::endl;
            std::cout << "\t3. Display employees' information to screen according the order of hourly rate" << std::endl << std::endl;
            std::cout << "\t4. Display employees' information to screen according the order of hours worked" << std::endl << std::endl;
            std::cout << "\t5. Display employees' information to screen according the order of wage" << std::endl << std::endl;
            std::cout << "\t6. Quit the system" << std::endl << std::endl << std::endl;

            // Prompt user for their selection
            std::cout << "Enter your option --> ";
            std::cin >> choice;

            std::cout << std::endl << std::endl;

            // If the user selected option '2'
            if (choice == 2)
            {
                // Sort the employees' database by 'employees id'
                selection_sort(ids, hourly_rates, hours_worked, Wages, employee_size, true, false, false, false);
            }

            // If the user selected option '3'
            else if (choice == 3)
            {
                // Sort the employees' database by 'hourly rates'
                selection_sort(ids, hourly_rates, hours_worked, Wages, employee_size, false, true, false, false);
            }

            // If the user selected option '4'
            else if (choice == 4)
            {
                // Sort the employees' database by 'hours worked'
                selection_sort(ids, hourly_rates, hours_worked, Wages, employee_size, false, false, true, false);
            }

            // If the user selected option '5'
            else if (choice == 5)
            {
                // Sort the employees' database by 'wages'
                selection_sort(ids, hourly_rates, hours_worked, Wages, employee_size, false, false, false, true);
            }

            // If the user selected '6'
            else if (choice == 6)
            {
                // Exit the loop
                break;
            }

            // Display all employees information in the database
            displayWages(ids, hourly_rates, hours_worked, Wages, employee_size);
        }

        // Display an exit message to the user
        std::cout << "Thank you for using XXXXXX Payroll System!" << std::endl;
    }
    // Display Employee Data ends here

    return 0;    
}


/** Get an employee's id, hourly pay rate, and hours worked from the user.
* @Pre: The memory addresses of the employee's id, hourly pay rate, and hours worked, as well as arrays that track these informations.
* @Post: The user-provided employee information is stored at the specified memory addresses and added to the arrays at the given index */
void getEmployeeInfor(int& employee_id, double& pay_rate, double& hours_worked, int employee_ids[], double pay_rates[],
                      double hours[], int length)
{
    std::cout << "Enter an employee's information by the order of ID number, rate," << std::endl;
    std::cout << "hours: " << std::endl;

    // Validate user input
    while (true)
    {
        std::cin >> employee_id;
        std::cin >> pay_rate;
        std::cin >> hours_worked;

        if (employee_id > 0 && pay_rate > 0 && hours_worked > 0)
        {
            break;
        }

        std::cout << "You must enter a non negative value. Try again!" << std::endl;
    }

    // Store the user input in the arrays
    employee_ids[length] = employee_id;
    pay_rates[length] = pay_rate;
    hours[length] = hours_worked;
}


/** Calculate the gross wage of an employee.
* @Pre: The employee's hourly pay rate, hours worked, the array to store each employee's calculated wage, and current index of the employee in the 'Wages' array.
* @Post: The calculated wage is stored in 'Wages' at the specified index (length) and returned rounded to one decimal place */
double calcWage(double pay_rate, double hours_worked, double Wages[], int& length)
{
    // Calculate the wage rounded to one decimal place and store it in the 'Wages' array 
    Wages[length] = round(pay_rate * hours_worked * 10) / 10;

    // Return the calculated wage rounded to one decimal place, as well as increment the index of the employee in the 'Wages' array
    return Wages[length++];
}


/** Writes an employee information to an output file.
* @Pre: The output file, employee's id, hourly pay rate, hours worked and gross wage.
* @Post: Writes that employee information at the current row of the output file */
void printWages(std::ofstream& outFile, int employee_id, double pay_rate, double hours_worked, double gross_wage)
{
    outFile << std::right << std::setw(10) << employee_id;
    outFile << std::right << std::setw(15) << pay_rate;
    outFile << std::right << std::setw(10) << hours_worked;
    outFile << std::right << std::setw(15) << gross_wage;
    outFile << std::endl;
}


/** Display the employees' database to the console
* @Pre: The arrays that store employees' information, and the number of employees
* @Post: The employee information is displayed in a well-formatted table to the console */
void displayWages(int ids[], double prs[], double hws[], double wages[], int index)
{
    // Display the table header
    std::cout << std::left << std::setw(10) << "ID";
    std::cout << std::left << std::setw(15) << "Hourly rate";
    std::cout << std::left << std::setw(10) << "Hours";
    std::cout << std::left << std::setw(15) << "Wage";
    std::cout << std::endl << std::endl;;

    // Loop for each employee in the database
    for (int i = 0; i < index; i++)
    {
        // Display the employee's information
        std::cout << std::left << std::setw(10) << ids[i];
        std::cout << std::left << std::setw(15) << prs[i];
        std::cout << std::left << std::setw(10) << hws[i];
        std::cout << std::left << std::setw(15) << wages[i];
        std::cout << std::endl << std::endl;
    }

    std::cout << std::endl;
}


/** Sorts the employees database based on a specified key
* @Pre: The arrays that store employees' information, the number of employees, as well as boolean flags that specifies what key we use for sorting
* @Post: The input arrays are sorted in ascending order based on the specified sorting key */
void selection_sort(int ids[], double prs[], double hws[], double wages[], int index, bool sort_id, bool sort_pr, bool sort_hw, 
                    bool sort_wages)
{

    int tempI; // Temporary container for integer data types
    double tempD; // Temporary container for double data types
    int min; // Variable that tracks index of minimum number

    // Loops for each employee in the database
    for (int i = 0; i < index - 1; i++)
    {
        min = i;

        // Loop for the subarray starting after the current employee
        for (int j = i + 1; j < index; j++)
        {
            // Check if we found a number less than the current minimum 
            if ((sort_id && ids[min] > ids[j]) || (sort_pr && prs[min] > prs[j]) || (sort_hw && hws[min] > hws[j]) || (sort_wages 
                    && wages[min] > wages[j]))
            {
                min = j;
            }
        }

        // Swap employees' ID
        tempI = ids[i];
        ids[i] = ids[min];
        ids[min] = tempI;

        // Swap employees' hourly rate
        tempD = prs[i];
        prs[i] = prs[min];
        prs[min] = tempD;

        // Swap employees' hours worked
        tempD = hws[i];
        hws[i] = hws[min];
        hws[min] = tempD;

        // Swap employees' wages
        tempD = wages[i];
        wages[i] = wages[min];
        wages[min] = tempD;
    }
}
