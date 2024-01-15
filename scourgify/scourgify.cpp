#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define print(x) std::cout << x << std::endl;

void strip(std::string& string, char chr = ' '){
    int l = 0;
    int j = l;

    while (j < string.length() && string[j] == chr) j++;

    if (l <= j){
        string.erase(l, j - l);
    }

    int r = string.length() - 1;
    j = r;

    while (j >= 0 && string[j] == chr) j--;

    if (j <= r){
        string.erase(j + 1, r - j + 1);
    }

}

std::vector<std::string> split(std::string& string, std::string del = " "){
    std::vector<std::string> array;
    int start = 0;
    int end = 0;

    while (end != -1){
        end = string.find(del, start);
        array.push_back(string.substr(start, end - start));
        start = end + del.size();
    }

    return array;
}

std::string join(std::vector<std::string> array, std::string del = " "){
    std::string new_str;

    for (int i = 0; i < array.size() - 1; i++) new_str += array[i] + ",";

    new_str += array.back();

    return new_str;
}

std::string edit(std::string& string){
    std::vector<std::string> array = split(string, ",");
    for(auto& item: array) strip(item);
    for(auto& item: array) strip(item, '"');
    
    return join(array, ",");
}

std::vector<std::string> load_file(std::string filename){
    std::ifstream file(filename);

    std::vector<std::string> contents;

    if (!file.is_open()){
        throw 2;
    }

    std::string line;
    std::vector<std::string> temp;

    while (std::getline(file, line)){
        auto temp = edit(line);
        contents.push_back(temp);
    }

    return contents;

}

void write_file(std::string filename, std::vector<std::string> contents){
    std::ofstream file(filename);

    contents[0] = "first,second,house";

    if (!file.good()){
        throw 3;
    }

    for (auto& dict : contents){
        file << dict << std::endl;
    }
}

int main(int argc, const char* argv[]){
    if (argc < 3){
        print("Too few command-line arguments  ")
        return 1;
    }

    else if (argc > 3){
        print("Too many command-line arguments  ")
        return 1;
    }

    std::string filename = argv[1];
    std::string returnfile = argv[2];

    int len_f = filename.length();
    int len_rf = returnfile.length();

    if (!((len_f > 4 && len_rf > 4) && (filename.substr(len_f - 4, 4) == returnfile.substr(len_rf - 4, 4) && filename.substr(len_f - 4, len_f - 1) == ".csv"))){
        print("Both files should be Csv files")
        return 1;
    }

    try{
        auto parsed_file = load_file(filename);
        write_file(returnfile, parsed_file);
    }

    catch(int e){
        if (e == 2){
            print("Could not read " << filename)
            return 1;
        }

        if (e == 3){
            print("Something went wrong : Could not write file " << returnfile)
            return 1;
        }
    }
}