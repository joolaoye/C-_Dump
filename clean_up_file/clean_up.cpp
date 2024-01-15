#include <iostream>  
#include <fstream>  // Imports file handler module
#include <vector>  // Imports vector container

#define print(x) std::cout << x << std::endl;  // Hash defines print(x) to make programming pythonic for me

// Function performs insertion sort on an array
void insertion_sort(std::vector<int>& array){
    int cur;
    int j;
    for (int i = 1; i < array.size(); i++){
        cur = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > cur){
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = cur;
    }
}

//Function cleans up an existing file else throws an error
void edit_file(std::string filename){
    std::fstream file(filename, std::ios::in);  // Open the file in read mode

    std::vector<int> contents;  // Creates a container to store the contents of file

    // Checks if file exists, throws an error I handled in the main function
    if (!file.is_open()){
        throw 2;
    }

    int number;  // Variable to keep track of the current number in the file

    // Keeps looping while there is still content in the file
    while (file >> number){
        contents.push_back(number);  // Appends the numbers to the container discussed earlier
    }

    file.close();  // Close file in read-mode for safety measures

    insertion_sort(contents);  // Performs insertion sort on the container discussed before

    file.open(filename, std::ios::out);  // Reopens file in write-mode

    // Change each line of file with sorted numbers
    for (auto& number : contents){
        file << number << std::endl;  // Overwrites previous content of file with sorted number
    }

    file.close();  // Closes file in write-mode
}

// I expect a command line argument, you can tweak for your convenience
int main(int argc, const char* argv[]){
    // Checks if the user runs the script correctly and handles it appropriately if otherwise
    if (argc != 2){
        print("Usage: ./clean_up filename")
        return 1;
    }

    std::string filename = argv[1];  // Copies the file name will be the second element in the argument array 
    int len = filename.length();  // Gets the length

    // Makes sure the user inputed a txt file
    if (!(len > 4 && filename.substr(len - 4, len - 1) == ".txt")){
        print("Enter a txt file")
        return 1;
    }

    // Handles the exception discussed earlier
    try{
        edit_file(filename);  // Calls the edit file function
    }
    
    // Handles the exception
    catch(int e){
        if (e == 2){
            print("File does not exist")
            return 1;
        }
    }

}