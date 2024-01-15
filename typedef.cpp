#include <iostream>

struct map{
    std::string name;
    int age;
    int vote;
    
};

typedef unsigned int uint_t;

int main(){
    uint_t age = 50;

    struct map Joshua;

    Joshua.age = age;

    std::cout << Joshua.age << std::endl;
}