#include <iostream>

int get_cents();

int calculate_quarters(int x);

int calculate_dimes(int x);

int calculate_nickels(int x);

int calculate_pennies(int x);

int main(){

    int cents = get_cents();

    int quarters, dimes, nickels, pennies;

    quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    pennies = calculate_pennies(cents);
    cents -= pennies * 1;


    std::cout << quarters + dimes + nickels + pennies << std::endl;



}

int get_cents(){
    int n;

    do{

    std::cout << "Change owed: ";
    std::cin >> n;
    }

    while (n < 0);

    return n;
}

int calculate_quarters(int x){
    int count = 0;
    while (x >= 25){
        x -= 25;
        count += 1;
    }
    return count;

}

int calculate_dimes(int x){
    int count = 0;
    while (x >= 10){
        x -= 10;
        count += 1;
    }
    return count;

}

int calculate_nickels(int x){
    int count = 0;
    while (x >= 5){
        x -= 5;
        count += 1;
    }
    return count;

}

int calculate_pennies(int x){
    int count = 0;
    while (x >= 1){
        x -= 1;
        count += 1;
    }
    return count;

}