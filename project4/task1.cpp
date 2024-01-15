#include <iostream> // for I/O operations
#include <iomanip> // for formatting output field
#include <fstream> // for file handling

using namespace std;

// Function prototypes
void getEmployeeInfor(int& employee_id, double& pay_rate, double& hours_worked);
double calcWage(double pay_rate, double hours_worked);
void printWages(ofstream& outFile, int employee_id, double pay_rate, double hours_worked, double gross_wage);


int main(){
    // declaring variables
    int id;
    double pr, hw, gw;
    ofstream fout;
    char response = 'y';

    // opening in a file
    fout.open("employeeWages.dat");

    // this scope sort of set the file  
    {
    // print the table header
    fout << right << setw(10) << "ID";
    fout << right << setw(15) << "Hourly rate";
    fout << right << setw(10) << "Hours";
    fout << right << setw(15) << "Wage";

    // end the header row
    fout << endl;

    // shows seperator line
    fout << setw(50) << setfill('-') << '-' << endl;

    // set this back to default
    fout << setfill(' ');
    fout << fixed << setprecision(2);
    }

    while (response == 'y'){
        // get employee's information
        getEmployeeInfor(id, pr, hw);

        // this gets the gross_wage
        gw = calcWage(pr, hw);

        // this outputs employee info to the file
        printWages(fout, id, pr, hw, gw);

        // prompt user if they wanna continue
        cout << endl;
        cout << "Do you want to calculate another employee's gross wage? ";
        cin >> response;
        cout << endl;

    }

    cout << "The result is reported to the file \"employeeWages.dat\"" << endl;

    // this closes the file
    fout.close();
    
}

void getEmployeeInfor(int& employee_id, double& pay_rate, double& hours_worked){
    cout << "Enter an employee's information by the order of ID number, rate," << endl;
    cout << "hours:" << endl;

    cin >> employee_id >> pay_rate >> hours_worked;

    while (employee_id < 0 || pay_rate < 0 || hours_worked < 0){
        cout << "You must enter a non negative value. Try again!" << endl;

        cin >> employee_id >> pay_rate >> hours_worked;
    }

    return;
}

double calcWage(double pay_rate, double hours_worked){

    return pay_rate * hours_worked;
}

void printWages(ofstream& outFile, int employee_id, double pay_rate, double hours_worked, double gross_wage){
    outFile << right << setw(10) << employee_id;
    outFile << right << setw(15) << pay_rate;
    outFile << right << setw(10) << hours_worked;
    outFile << right << setw(15) << gross_wage;

    outFile << endl;
}