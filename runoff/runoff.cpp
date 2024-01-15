#include <iostream>
#include <string>

#define print(x) std::cout << x << std::endl;

#define MAX_CANDIDATES 9 
#define MAX_VOTERS 100

int preferences[MAX_VOTERS][MAX_CANDIDATES];

struct candidate{
    std::string name;
    int votes;
    bool eliminated;
};

candidate candidates[MAX_CANDIDATES];

int candidate_count;
int voter_count;

int get_int(std::string prompt);
std::string get_string(std::string prompt);
bool vote(int voter, int rank, std::string name);
void tabulate();
bool print_winner();
int find_min();
bool is_tie(int min);
void eliminate(int min);


int main(int argc, const char* argv[]){
    if (argc < 2){
        print("Usage: ./runoff candidate_1 ...")
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX_CANDIDATES){
        print("Maximum number of candidates is " << MAX_CANDIDATES)
        return 2;
    }

    voter_count = get_int("Number of Voters: ");

    if (voter_count > MAX_VOTERS){
        print("Maximum number of voters is " << MAX_VOTERS)
        return 2;
    }

    for (int i = 0; i < candidate_count; i++){
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;

    }

    for (int i = 0; i < voter_count; i++){
        for (int j = 0; j < candidate_count; j++){
           auto choice =  get_string("Rank " + std::to_string(j + 1) + ": ");

           if(!(vote(i, j, choice))){
            print("Invalid vote")
           }
    
        }

        print(" ")
    }

    while (true){
        tabulate();

        if (print_winner()){
            break;
        }

        auto min = find_min();

        if (is_tie(min)){
            for (int i = 0; i < candidate_count; i++){
                if (!candidates[i].eliminated){
                    print(candidates[i].name)
                }
            }
            break;
        }

        eliminate(min);

        for (int i = 0; i < candidate_count; i++){
            candidates[i].votes  = 0;
        }
    }

    return 0;
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

bool vote(int voter, int rank, std::string name){
    for (int i = 0; i < candidate_count; i++){
        if (candidates[i].name == name){
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}

void tabulate(){
    for (int i = 0; i < voter_count; i++){
        for (int j = 0; j < candidate_count; j++){
            if (!candidates[preferences[i][j]].eliminated){
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }

}

bool print_winner(){
    for (int i = 0; i < candidate_count; i++){
        if (candidates[i].votes > (voter_count / 2)){
            print(candidates[i].name)
            return true;
        }
    }

    return false;
}

int find_min(){
    int min_vote = INT_MAX;

    for (int i = 0; i < candidate_count; i++){
        if (!candidates[i].eliminated){

        min_vote = (candidates[i].votes < min_vote) ? candidates[i].votes : min_vote;
        }
    }

    return min_vote;
}

bool is_tie(int min){
    int tied = 0;
    int cur_cands = 0;

    for (int i = 0; i < candidate_count; i++){
        if (!candidates[i].eliminated){
            cur_cands++;

            if (candidates[i].votes == min){
                tied++;
            }
        }
    }

    return tied == cur_cands;
}

void eliminate(int min){
    for (int i = 0; i < candidate_count; i++){
        if (candidates[i].votes == min){
            candidates[i].eliminated = true;
        }
    }
}