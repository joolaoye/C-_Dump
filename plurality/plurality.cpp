#include <iostream>

#define print(x) std::cout << x << std::endl;

#define MAX 9

struct candidate{
    std::string name;
    int votes;
};

candidate candidates[MAX];
int candidate_count;

int get_int(std::string="Enter: ");
std::string get_string(std::string="Enter: ");
bool vote(std::string="");
void print_winner();

int main(int argc, const char* argv[]){
    if (argc < 2){
        print("Usage: ./plurality candidate_1...")
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX){
        print("Maximum number of candidates is " << MAX)
    }

    for (int i = 0; i < candidate_count; i++){
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    auto num_voters = get_int("Number of Voters: ");

    for (int i = 0; i < num_voters; i++){
        auto choice = get_string("Vote: ");

        if (!(vote(choice))){
            print("Invalid vote");
        }
    }

    print_winner();


}

int get_int(std::string prompt){
    int input;

    std::cout << prompt;

    while(!(std::cin >> input)){
        std::cin.clear();
        std::cin.ignore(std::streamsize("streamsize"), '\n');
        std::cout << prompt;
    }

    return input;
}


std::string get_string(std::string prompt){
    std::string input;

    std::cout << prompt;
    std::cin >> input;
    return input;
}


bool vote(std::string c_name){
    for (int i = 0; i < candidate_count; i++){
        if (c_name == candidates[i].name){
            candidates[i].votes += 1;
            return true;
        }
    }

    return false;
}

void print_winner(){
    int max_vote = INT_MIN;
    for (int i = 0; i < candidate_count; i++){
        max_vote = (candidates[i].votes > max_vote) ? candidates[i].votes : max_vote;
    }

     for (int i = 0; i < candidate_count; i++){
       if (candidates[i].votes == max_vote){
        print(candidates[i].name)
       }
    }
}