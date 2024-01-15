#include <iostream>
#include <random>
#include <string>
#include <cmath>

int get_level(std::string);

int generate_integer(int level);

int main(){

    auto score = 0;

    try{
        auto n = get_level("Level: ");

        for (int i = 0; i < 10; i++){
            auto X  = generate_integer(n);
            auto Y = generate_integer(n);

            auto sum =  X + Y;

            int choice;


            auto trials = 0;

            while (trials < 3){
                
                try{
                    std::cout << std::to_string(X) + " + " + std::to_string(Y) + " = ";
                    if (!(std::cin >> choice)){
                        throw 2;
                    }

                    if (choice == sum){
                        score++;
                        break;
                    }
                }

                catch(int& ex){
                    if (ex == 2){
                        std::cin.clear();
                        std::cin.ignore(std::streamsize("streamsize"), '\n');
                    }
                }

                std::cout << "EEE" << std::endl;
                trials++;


            }

            if (trials == 3){
                std::cout << std::to_string(X) + " + " + std::to_string(Y) + " = " << sum << std::endl;
            }

        }

    }

    catch(int& ex){
        if (ex == 3){
            return 1;
        }

    }

    std::cout << "Score: " << score << std::endl;

}

int get_level(std::string prompt){
    int input;

    std::cout << prompt;
    
    while (!(std::cin >> input) || !(input >= 1 && input <= 3)){
        std::cin.clear();
        std::cin.ignore(std::streamsize("streamsize"), '\n');
        std::cout << prompt;
    }

    return input;
}

int generate_integer(int level){
    if (!(level >= 1 && level <= 3)){
        throw 3;
    }

    auto n = (int) pow(10.0, (int) level);

    std::random_device rd;
    std::mt19937 gen(rd() + 1);
    std::uniform_int_distribution<int> dis(1, n - 1);

    return dis(gen);

}