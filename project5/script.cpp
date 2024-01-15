/*
Driver License Examination System
Name: Joshua O Olaoye
starID: ********
Section Number: 03

Description:
This program simulates a Driver's License Exam

It reads the answers to the exam from an input file and stores it in array
It prompts user for an answer to an exam question. Answer should be between A - D
If the user enters an invalid option, the program displays a friendly error message and prompt the user again
If the user enters a valid option, user's answer is stored in an array 
The program repeats lines 2 through 3 20 times
When the user has answered all 20 questions, the program compares all their answer with the ones from the file
If the user didn't get a question correctly, the number of question missed is incremented and the question number is stored in an array
At the end of the loop, the program checks if user answered at least 15 questions correctly
If the user answered at least 15 questions correctly, the program displays a message telling them they passed
If the user answered less than 15 questions correctly, the program displays a message telling them they faied
The program then displays the question numbers of questions the user answered incorrectly
*/

#include <iostream> // Handles I/O opertaions
#include <fstream> // Handles file handling operations

// Function Prototypes
void read_file(std::ifstream& inFile, char* ans_array);
void get_user_answers(char* user_ans);
int check_differences(char* ans_array, char* user_ans, int* missed_questions);

const int SIZE = 20; // Maximum size for arrays

int main(){

    std::ifstream file("answers.txt"); // Open the file with all the answers
    char answers[SIZE] = {0}; // Store all correct answers
    char user_answers[SIZE] = {0}; // Store user's answers
    int incorrect_answers[SIZE] = {0}; // Track question numbers that user answered incorrectly

    // Read correct answers from file into answers array
    read_file(file, answers);

    // Close the file
    file.close();

    // Display a menu to user
    std::cout << "Please enter the student's answers for each of the questions. Press" << std::endl;
    std::cout << "Enter after typing each answer." << std::endl;
    std::cout << "Please enter only an A, B, C, or D for each question." << std::endl;

    // Get user answers and store in 'user_answers'
    get_user_answers(user_answers);

    // Get question numbers user got wrong, store them in 'incorrect_answers', as well as the number of incorrect answers
    int entered_incorrect = check_differences(answers, user_answers, incorrect_answers);

    std::cout << std::endl;;

    // Check if user passed the exam
    if (SIZE - entered_incorrect >= 15){
        // Display a message telling the user they passed
        std::cout << "Student passed the exam" << std::endl;
    }

    // Check if user failed the exam
    else{
        // Display a message telling the user they passed
        std::cout << "Student failed the exam" << std::endl;
    }

    std::cout << std::endl;

    // Display number of questions user got correctly and incorrectly
    std::cout << "Correct Answers = " << SIZE - entered_incorrect << std::endl;
    std::cout << "Incorrect Answers = " << entered_incorrect << std::endl << std::endl;

    // Display a message to the user
    std::cout << "The list below shows the question numbers of the incorrectly" << std::endl;
    std::cout << "answered questions" << std::endl;

    // Outer loop iterates for all the questions user answered correctly
    for (int i = 0; i < entered_incorrect; i++){
        // Display the question number the user got incorrectly
        std::cout << incorrect_answers[i] << std::endl;
    }
    
}

/** Copies the contents of an input file to an array.
* @Pre: A reference to the input file, as well as the array to store the contents.
* @Post: Updates the array with the contents from input file */
void read_file(std::ifstream& inFile, char* ans_array){
    int ptr = 0;
    char answer;
    while (inFile >> answer){
        ans_array[ptr++] = answer;
    }
}

/** Get and validate user answer to all 20 questions
* @Pre: A pointer to the array that stores all user answers.
* @Post: Updates the array with all user answers*/
void get_user_answers(char* user_ans){
    char answer;

    for (int i = 0; i < SIZE; i++){

        do{
            std::cout << "Question " << i + 1 << ": ";
            std::cin >> answer;

            if (answer < 'A' || answer > 'D')
                std::cout << "Enter options from A - D." << std::endl;

        } while (answer < 'A' || answer > 'D');

        user_ans[i] = answer;
    }
}

/** Updates the number of incorrect answers entered by the user and stores the question numbers in an array
* @Pre: The correct answers array, the user answers array, and an array to store the question numbers of question missed.
* @Post: Returns the number of questions missed and stores the question number of questions missed in 'missed_questions' array */
int check_differences(char* ans_array, char* user_ans, int* missed_questions){
    int num_missed = 0;

    for (int i = 0; i < SIZE; i++){
        if (ans_array[i] != user_ans[i]){
            missed_questions[num_missed++] = i + 1;
        }
    }

    return num_missed;
}