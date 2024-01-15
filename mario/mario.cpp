#include <iostream>

int get_height();

void print_bricks(int);

int main(){

    int height = get_height();

    print_bricks(height);

}

int get_height(){
    int n;

    std::cout << "Height: ";

    while (!(std::cin >> n)){
        std::cin.clear();
        std::cin.ignore(std::streamsize("streamsize"),'\n');
        std::cout << "Height: ";
    }

    return n;
}

void print_bricks(int height){
    for (int i = 1; i <= height; i++){
        for (int space = 0; space < height - i; space++){
            std::cout << ' ';
        }

        for (int j = 0; j < i; j++){
            std::cout << "#";
        }

        std::cout << ' ';

        for (int j = 0; j < i; j++){
                std::cout << "#";
        }
        std::cout << std::endl;

    }

}