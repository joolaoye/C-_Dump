#include <iostream>

int main(){
    int x, y;

    char oper;

    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter Operator: ";
    std::cin >> oper;
    std::cout << "Enter y: ";
    std::cin >> y;

    switch(oper){
        case '+':
            std::cout << x + y << std::endl;
            break;

        case '-':
            std::cout << x - y << std::endl;
            break;

        case '*':
            std::cout << x * y << std::endl;
            break;

        case '/':
            std::cout << x / y << std::endl;
            break;

        case '%':
            std::cout << x % y << std::endl;
            break;

        default:
            std::cout << "Not supported" << std::endl;
            break;
    }

}