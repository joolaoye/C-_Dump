#include <iostream>

int get_int(std::string s="");

bool check_prime(int num);

int main(){
    
    int number = get_int("Enter number: ");

    std::string res = "Not prime";

    if (check_prime(number) == 1){
        res = "Prime";
    }

    std::cout << res << std::endl;
}

int get_int(std::string s){
    int n;

    std::cout << s;
    std::cin >> n;

    return n;
}

bool check_prime(int num){
    if (num < 2){
        return false;
    }

    else if (num % 2 == 0){
        return num == 2;
    }

    for (int i = 2; i * i <= num; i++){
        if (num % i == 0){
            return false;
        }
    }

    return true;
}