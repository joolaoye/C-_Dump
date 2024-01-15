#include <iostream> // for I/O operations
#include <iomanip> // for formatting output field
#include <fstream> // for file handling
#include <cmath> // for rounding up values

using namespace std;

const int MAX = 20;

// Function prototypes
void getEmployeeInfor(int& employee_id, double& pay_rate, double& hours_worked);
double calcWage(double pay_rate, double hours_worked);
void printWages(ofstream& outFile, int employee_id, double pay_rate, double hours_worked, double gross_wage);
void fillArrays(int employee_id, double pay_rate, double hours_worked, double gross_wage, int ids[], double prs[], double hws[], double wages[], int& index);
void displayWages(int ids[], double prs[], double hws[], double wages[], int index);
void sortByIds(int ids[], double prs[], double hws[], double wages[], int index);
void sortByHourlyRates(int ids[], double prs[], double hws[], double wages[], int index);
void sortByHoursWorked(int ids[], double prs[], double hws[], double wages[], int index);
void sortByWages(int ids[], double prs[], double hws[], double wages[], int index);

int main(){
    // declaring variables
    int id;
    double pr, hw, gw;
    ofstream fout;
    char response = 'y';
    int choice;

    int employeeIds[MAX];
    double payRates[MAX];
    double hoursWorked[MAX];
    double Wages[MAX];

    int index = 0;

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

    


    cout << "-- XXXXXX Payroll System --" << endl << endl;;

    cout << "Build Employee Database" << endl << endl << endl;

    while (response == 'y'){
        // get employee's information
        getEmployeeInfor(id, pr, hw);

        // this gets the gross_wage
        gw = calcWage(pr, hw);

        // this outputs employee info to the file
        printWages(fout, id, pr, hw, gw);

        // fill arrays with employee's information
        fillArrays(id, pr, hw, gw, employeeIds, payRates, hoursWorked, Wages, index);

        // prompt user if they wanna continue
        cout << endl;
        cout << "Do you want to calculate another employee's gross wage? ";
        cin >> response;
        cout << endl;

    }

    cout << "The result is reported to the file \"employeeWages.dat\"" << endl << endl << endl;

    // this closes the file
    fout.close();

    // project 4 ends here

    // project 6 starts here

    cout << "-- XXXXXX Payroll System --" << endl << endl;

    cout << "Display Employee Data" << endl << endl << endl;

    cout << fixed << setprecision(1);

    while (choice != 6){

        cout << "1. Display employees' information to screen" << endl;
        cout << "2. Display employees' information to screen according the order of ID" << endl;
        cout << "3. Display employees' information to screen according the order of hourly rate" << endl;
        cout << "4. Display employees' information to screen according the order of hours worked" << endl;
        cout << "5. Display employees' information to screen according the order of wage" << endl;
        cout << "6. Quit the system" << endl << endl;

        cout << "Enter your option --> ";
        cin >> choice;

        cout << endl << endl;

        if (choice == 1){
            displayWages(employeeIds, payRates, hoursWorked, Wages, index);
        }

        else if (choice == 2){
            sortByIds(employeeIds, payRates, hoursWorked, Wages, index);
            displayWages(employeeIds, payRates, hoursWorked, Wages, index);
        }

        else if (choice == 3){
            sortByHourlyRates(employeeIds, payRates, hoursWorked, Wages, index);
            displayWages(employeeIds, payRates, hoursWorked, Wages, index);
        }

        else if (choice == 4){
            sortByHoursWorked(employeeIds, payRates, hoursWorked, Wages, index);
            displayWages(employeeIds, payRates, hoursWorked, Wages, index);
        }

        else if (choice == 5){
            sortByWages(employeeIds, payRates, hoursWorked, Wages, index);
            displayWages(employeeIds, payRates, hoursWorked, Wages, index);
        }


    }
    
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

    return round(pay_rate * hours_worked * 10) / 10;
}

void printWages(ofstream& outFile, int employee_id, double pay_rate, double hours_worked, double gross_wage){
    outFile << right << setw(10) << employee_id;
    outFile << right << setw(15) << pay_rate;
    outFile << right << setw(10) << hours_worked;
    outFile << right << setw(15) << gross_wage;

    outFile << endl;
}

void fillArrays(int employee_id, double pay_rate, double hours_worked, double gross_wage, int ids[], double prs[], double hws[], double wages[], int& index){
    ids[index] = employee_id;
    prs[index] = pay_rate;
    hws[index] = hours_worked;
    wages[index] = gross_wage;

    index++;
}

void displayWages(int ids[], double prs[], double hws[], double wages[], int index){
    cout << left << setw(10) << "ID";
    cout << left << setw(15) << "Hourly rate";
    cout << left << setw(10) << "Hours";
    cout << left << setw(15) << "Wage";
    cout << endl;

    // Write each row
    for (int i = 0; i < index; i++){
        cout << left << setw(10) << ids[i];
        cout << left << setw(15) << prs[i];
        cout << left << setw(10) << hws[i];
        cout << left << setw(15) << wages[i];

        cout << endl;
    }

    cout << endl << endl;

}

void sortByIds(int ids[], double prs[], double hws[], double wages[], int index){
    // selection sort
    int tempI;
    double tempD;
    int min;

    for (int i = 0; i < index - 1; i++){
        min = i;

        for (int j = i + 1; j < index; j++){
            if (ids[min] > ids[j]){
                min = j;
            }
        }

        tempI = ids[i];
        ids[i] = ids[min];
        ids[min] = tempI;

        tempD = prs[i];
        prs[i] = prs[min];
        prs[min] = tempD;

        tempD = hws[i];
        hws[i] = hws[min];
        hws[min] = tempD;

        tempD = wages[i];
        wages[i] = wages[min];
        wages[min] = tempD;

    }
}

void sortByHourlyRates(int ids[], double prs[], double hws[], double wages[], int index){
    // selection sort
    int tempI;
    double tempD;
    int min;

    for (int i = 0; i < index - 1; i++){
        min = i;

        for (int j = i + 1; j < index; j++){
            if (prs[min] > prs[j]){
                min = j;
            }
        }

        tempI = ids[i];
        ids[i] = ids[min];
        ids[min] = tempI;

        tempD = prs[i];
        prs[i] = prs[min];
        prs[min] = tempD;

        tempD = hws[i];
        hws[i] = hws[min];
        hws[min] = tempD;

        tempD = wages[i];
        wages[i] = wages[min];
        wages[min] = tempD;

    }
}

void sortByHoursWorked(int ids[], double prs[], double hws[], double wages[], int index){
    // selection sort
    int tempI;
    double tempD;
    int min;

    for (int i = 0; i < index - 1; i++){
        min = i;

        for (int j = i + 1; j < index; j++){
            if (hws[min] > hws[j]){
                min = j;
            }
        }

        tempI = ids[i];
        ids[i] = ids[min];
        ids[min] = tempI;

        tempD = prs[i];
        prs[i] = prs[min];
        prs[min] = tempD;

        tempD = hws[i];
        hws[i] = hws[min];
        hws[min] = tempD;

        tempD = wages[i];
        wages[i] = wages[min];
        wages[min] = tempD;

    }
}

void sortByWages(int ids[], double prs[], double hws[], double wages[], int index){
    // selection sort
    int tempI;
    double tempD;
    int min;

    for (int i = 0; i < index - 1; i++){
        min = i;

        for (int j = i + 1; j < index; j++){
            if (wages[min] > wages[j]){
                min = j;
            }
        }

        tempI = ids[i];
        ids[i] = ids[min];
        ids[min] = tempI;

        tempD = prs[i];
        prs[i] = prs[min];
        prs[min] = tempD;

        tempD = hws[i];
        hws[i] = hws[min];
        hws[min] = tempD;

        tempD = wages[i];
        wages[i] = wages[min];
        wages[min] = tempD;

    }
}
