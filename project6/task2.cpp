#include <iostream>

#include "Employee.h"

using namespace std;


int main()

{

Employee e1; //Define an employee object by the default constructor

Employee e2(12345, "John", "Smith", 12.5, 80); //test the constructor added


// Get employee e1's data from the keyboard to test operator >>.
cin >> e1; 

// Test operator == to see of e1 and e2 are same
cout << (e1 == e2) << endl;

// Test operator != to see if e1 and e1 are not same
cout << (e1 != e2) << endl;;


// Output e1 and e2 to the screen to test operator <<
cout << e1;
cout << e2;

return 0;

}