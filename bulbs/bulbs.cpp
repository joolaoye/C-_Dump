#include <iostream>

std::string get_string(std::string=": ");

void print_bulb(int bit);

int main(){
    std::string message = get_string("Message: ");

    for (int i = 0; i < message.length(); i++){
        auto val = (int) message[i];

        for (int j = 7; j >= 0; j--){
            print_bulb((val >> j) & 1);
        }

        std::cout << std::endl;
    }

}

std::string get_string(std::string prompt){
    std::string input;

    std::cout << prompt;
    std::cin >> input;

    return input;
}

void print_bulb(int bit)
{

    if (bit == 0)
    {
        // Dark emoji
        std::cout<<"0";
    }
    else if (bit == 1)
    {
        // Light emoji
        std::cout<<"1";
    }
}