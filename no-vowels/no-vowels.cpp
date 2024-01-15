#include <iostream>
#include <array>

char* replace(char*);

int size_of_array(char*);

int main(int argc, char* argv[]){
    if (argc > 2 || argc < 2){
        std::cout << "Usage: ./no-vowels word" << std::endl;
        return 1;
    }

    int size = size_of_array(argv[1]);

    char* result = replace(argv[1]);

    for (int i = 0; i < size; i++){

    std::cout << *(result + i);
    }
    std::cout << std::endl;
}

int size_of_array(char* s){
    int count;
    
    for (char *p = s; *p != '\0'; ++p){
        count += 1;
    }

    return count;

}

char* replace(char* s){
    int size = size_of_array(s);

    for (int i = 0; i < size; i++){
        switch(s[i]){
            case 'a':
                s[i] = '6';
                break;

            case 'e':
                s[i] = '3';
                break;
            
            case 'i':
                s[i] = '1';
                break;

            case 'o':
                s[i] = '0';
                break;

            default:
                break;
        }

    }

    return s;
}