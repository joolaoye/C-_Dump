#include <iostream>
#include <string>
#include <fstream>
#include <vector>


#define print(x) std::cout << x << std::endl;

class Person{
public:
	std::string name;
	std::vector<int> sequence_count;
	
	Person(std::string string){
		name = string;
	}
};

class Dna_sequence{
public:
	std::string name;
	int count;
	
	Dna_sequence(std::string string){
		name = string;
		count = 0;
	}
};

// Docs incoming
std::vector<Dna_sequence> Dna_table;
std::vector<Person> People;

// Utils
std::vector<std::string> load(const char* filename);
std::vector<std::string> split(std::string& string, std::string del = " ");
int atoi(std::string& string);
int longest_subsequence(std::string& strand, std::string& whole_string);
bool find_match(){
	for (int i = 0; i < People.size(); i++){
		std::vector<int> row = People[i].sequence_count;
		int check = 0;
		
		for (int j = 0; j < row.size(); j++){
			if (row[j] == Dna_table[j].count){
				check++;
			}
		}
		
		if (check == row.size()){
			print(People[i].name)
			return true;
		}
	}
	
	return false;
}

int main(int argc, const char* argv[]){
	if (argc != 3){
		print("Usage: ./DNA.cpp data.csv sequence.txt")
		return 1;
	}
	
	const char* csv_file = argv[1];
	const char* sequences = argv[2];
	
	try{
		// Loads the CSV header into the DNA table
		std::vector<std::string> csv_contents  = load(csv_file);
		std::vector<std::string> table_header = split(csv_contents[0], ",");
		
		for (int i = 1; i < table_header.size();i++){
			Dna_sequence temp(table_header[i]);
			Dna_table.push_back(temp);
		}
		
		
		// Loads the contents into the people table
		for (int j = 1; j < csv_contents.size(); j++){
			std::vector<std::string> line = split(csv_contents[j], ",");
			
			Person temp(line[0]);
			
			for (int k = 1; k < line.size(); k++){
				temp.sequence_count.push_back(atoi(line[k]));
			}
			
			People.push_back(temp);
		}
		
		
		std::string txt_content = load(sequences)[0];
		
		for (int i = 0; i < Dna_table.size(); i++){
			int count = longest_subsequence(Dna_table[i].name, txt_content);
			Dna_table[i].count = count;
		}
		
		
		if(!find_match()) print("Match Not Found");
		
	}
	
	catch(int e){
		if (e == 2){
			print("File does not exists")
			return 1;
		}
	}
}

std::vector<std::string> load(const char* filename){
	std::ifstream file;
	
	file.open(filename);
	
	if (!file.is_open()){
		throw 2;
	}
	
	std::string line;
	std::vector<std::string> contents;
	
	while (std::getline(file, line)){
		contents.push_back(line);
	}
	
	file.close();
	
	return contents;
}

std::vector<std::string> split(std::string& string, std::string del){
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

int atoi(std::string& string){
	int res = 0;
	
	for (int i = 0; i < string.size(); i++){
		res = res * 10 + (string[i] % 48);
	}
	
	return res;
}

int longest_subsequence(std::string& strand, std::string& whole_string){
	int maxcount = 0;
	int count = 0;
	
	int start = 0;
	int end = whole_string.find(strand, start);
	
	int len_strand = strand.length();
	
	while (end != std::string::npos){
		count++;
		
		start = end + len_strand;
		
		while (start < whole_string.length() && whole_string.substr(start, len_strand) == strand){
			count++;
			start += len_strand;
		}
		
		end = whole_string.find(strand, start);
		maxcount = (count > maxcount) ? count : maxcount;
		count = 0;
	}
	
	
	return maxcount;
}
