#include <iostream>

std::string get_string(std::string);

bool valid(std::string);

int main(){
    std::string password = get_string("Enter your password: ");

    if (valid(password)){
        std::cout << "Your password is valid!" << std::endl;
    }

    else{
        std::cout <<"Your password needs at least one uppercase letter, lowercase letter, number and symbol" << std::endl;
    }
}

std::string get_string(std::string s){
    std::string input;

    std::cout << s;
    std::cin >> input;

    return input;
}

bool valid(std::string s){
    auto caps = false;
    auto lower = false;
    auto num = false;
    auto symbol = false;

    for (int i = 0; i < s.length(); i++){
        auto val = (int) s[i];

        if ((65 <= val) && (val <= 90)){
            caps = true;
        }

        else if ((97 <= val) && (val <= 122)){
            lower = true;
        }

        else if ((48 <= val) && (val <= 57)){
            num = true;
        }

        else if ((32 <= val) && (val <= 127)){
            symbol = true;
        }
    }

    return caps && lower && num && symbol;

}