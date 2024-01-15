#include "EmployeeList.h"

EmployeeList::EmployeeList(){
    this->size = 0;
}

bool EmployeeList::addEmployee(const Employee& employee)
{
    if (this->size >= MAX){
        return false;
    }

    for (int i = 0; i < this->size; i++){
        if (this->employeeList[i] == employee){
            return false;
        }
    }

    this->employeeList[this->size++] = employee;

    return true;
}

bool EmployeeList::deleteEmployee(const Employee& employee)
{
    int index = -1;
    Employee temp;

    for (int i = 0; i < this->size; i++){
        if (this->employeeList[i] == employee){
            index = i;
            break;
        }
    }

    if (index != -1){
        for (int i = index; index < this->size; i++){
            temp = this->employeeList[i];
            this->employeeList[i] = this->employeeList[i + 1];
            this->employeeList[i + 1] = temp;
        }

        this->size--;

        return true;
    }

    return false;
}

int EmployeeList::searchEmployeeList(int ID){
    for (int i = 0; i < this->size; i++) {
        if (this->employeeList[i].getID() == ID){
            return i;
        }
    }

    return -1;
}

void EmployeeList::modifyEmployee(int index){
    if (!(0 <= index && index <= MAX)){
        throw 2;
    }

    char prompt;

    std::cout << "Change id? y/n -->";
    std::cin >> prompt;

    if (prompt == 'y')
    {
        int id;
        std::cout << "Enter new ID: ";
        std::cin >> id;

        this->employeeList[index].setID(id);

        std::cout << "ID has changed." << std::endl;
    }

    std::cout << "Change first name? y/n -->";
    std::cin >> prompt;

    if (prompt == 'y')
    {
        std::string fName;
        std::cout << "Enter new first name: ";
        std::cin >> fName;

        this->employeeList[index].setFirstName(fName);
        
        std::cout << "first name has changed." << std::endl;
    }

    std::cout << "Change last name? y/n -->";
    std::cin >> prompt;

    if (prompt == 'y')
    {
        std::string lName;
        std::cout << "Enter new last name: ";
        std::cin >> lName;

        this->employeeList[index].setFirstName(lName);
        
        std::cout << "last name has changed." << std::endl;
    }

    std::cout << "Change rate? y/n -->";
    std::cin >> prompt;

    if (prompt == 'y')
    {
        double rate;
        std::cout << "Enter new rate: ";
        std::cin >> rate;

        this->employeeList[index].setRate(rate);
        
        std::cout << "rate has changed." << std::endl;
    }

    std::cout << "Change hours? y/n -->";
    std::cin >> prompt;

    if (prompt == 'y')
    {
        double hour;
        std::cout << "Enter new hours: ";
        std::cin >> hour;

        this->employeeList[index].setHours(hour);
        
        std::cout << "hours has changed." << std::endl;
    }

}

int EmployeeList::returnSize(){
    return this->size;
}

Employee EmployeeList::returnEmployee(int index){
    if (!(0 <= index && index <= MAX)){
        throw 2;
    }

    return this->employeeList[index];
}