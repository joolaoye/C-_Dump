#include <iostream>
#include <fstream> 
#include <vector>
#include <string>

#define print(x) std::cout << x << std::endl;

void strip(std::string& string){
    int l = 0;
    int j = l;

    while (j < string.length() && string[j] == ' ') j++;

    if (l <= j){
        string.erase(l, j - l);
    }

    int r = string.length() - 1;
    j = r;

    while (j >= 0 && string[j] == ' ') j--;

    if (j <= r){
        string.erase(j + 1, r - j + 1);
    }

}

std::vector<std::string> parse_file(std::string filename){
    std::vector<std::string> file_contents;
    std::ifstream file(filename);

    if (!file.is_open()){
        throw 2;
    }
    
    std::string line;

    while (std::getline(file, line)){
        strip(line);
        file_contents.push_back(line);
    }
    return file_contents;
}


int count_lines(std::vector<std::string>& file_contents){
    int count = 0;
    for (auto& line : file_contents){
        if (!line.empty() && !(line[0] == '/' && line[1] == '/')){
            count += 1;
        }
    }

    return count;
}

int main(int argc, const char* argv[]){
    if (argc < 2){
        print("Too few command-line arguments")
        return 1;
    }

    else if (argc > 2){
        print("Too many command-line arguments")
        return 1;
    }

    std::string filename = argv[1];
    int len = filename.length();

    if (!(len > 4 && filename.substr(len - 4, len - 1) == ".cpp")){
        print("Not a cpp file")
        return 1;
    }

    try{
        std::vector<std::string> parsed_file = parse_file(filename);
        int line_count = count_lines(parsed_file);

        print("Line Count: " << line_count)
    }

    catch(int e){
        if (e == 2){
            print("File does not exist")
        }
    }

}