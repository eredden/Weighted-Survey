// submission.cpp - The combined code from the source and header files that I made for this project.

/*
YOU NEED TO RUN THIS PROGRAM MULTIPLE TIMES TO GET ADJUSTED PREDICTIONS.
BY DEFAULT, ALL PARTIES HAVE A 25% CHANCE OF BEING ALIGNED WITH YOU.
THE DEFAULT WEIGHTS ARE THE SAME FOR ALL PARTIES AND ANSWERS.

This code can be compiled with g++ into an executable that gives a political survey.
Questions, answers, and weights are serialized and written to questions.dat.

If you would like to see the full project and documentation:
https://github.com/eredden/Weighted-Survey
*/

#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>

// survey.hpp - Defines questions, answers, and functions for working with them.

#ifndef SURVEY_H
#define SURVEY_H

// Note that TOTAL_QUESTIONS excludes the last question about political affiliation.
#define TOTAL_QUESTIONS 8
#define TOTAL_ANSWERS 4
#define TOTAL_WEIGHTS 4
#define MAX_STRING_LENGTH 64
#define QUESTION_FILE "question.dat"

class Answer {
    public:
        // Default constructor for Answer class instances.
        Answer();

        // Constructor for Answer class instances.
        Answer(const char* text, unsigned int weights[TOTAL_ANSWERS]);

        // Sets the text attribute for an Answer class instance.
        void setText(const char* text);

        // Gets the text from an Answer class instance.
        const char* getText() const;

        // Sets the value of an individual weight for an Answer class instance.
        void setWeight(unsigned int weight, unsigned int index);

        // Gets the value of an individual weight for an Answer class instance.
        unsigned int getWeight(unsigned int index);

        // Sets the weights for an Answer class instance.
        void setWeights(unsigned int weights[TOTAL_WEIGHTS]);

        // Gets the weights from an Answer class instance.
        unsigned int *getWeights();

        // Serializes the Answer instance to a binary file.
        void serialize(std::ostream &out);

        // Deserializes the Answer instance from a binary file.
        void deserialize(std::istream &in);
        
    private:
        char _text[MAX_STRING_LENGTH];
        unsigned int _weights[4];
};

class Question {
    public:
        // Default constructor for Question class instances.
        Question();

        // Constructor for Question class instances.
        Question(const char* prompt, Answer answers[TOTAL_ANSWERS]);

        // Sets the prompt attribute for a Question class instance.
        void setPrompt(const char* prompt);

        // Gets the text attribute from a Question class instance.
        const char* getPrompt() const;

        // Sets the answers for a Question class instance.
        void setAnswers(Answer answers[TOTAL_ANSWERS]);

        // Gets the answers from a Question class instance.
        Answer *getAnswers();

        // Prompts the end user with the question and returns the answer.
        Answer *ask();

        // Prompts the end user with the question and returns the answers index.
        unsigned int askIndex();

        // Serializes the Question instance to a binary file.
        void serialize(std::ostream &out);

        // Deserializes the Question instance from a binary file.
        void deserialize(std::istream &in);

    private:
        char _prompt[MAX_STRING_LENGTH];
        Answer _answers[TOTAL_ANSWERS];
};

#endif // SURVEY_H

// answer.cpp - Functions for the Answer class.

Answer::Answer() {
    std::memset(_text, 0, MAX_STRING_LENGTH);
};

Answer::Answer(const char* text, unsigned int weights[TOTAL_ANSWERS]) {
    std::strncpy(_text, text, MAX_STRING_LENGTH - 1);
    _text[MAX_STRING_LENGTH - 1] = '\0'; // Ensure null-termination.
    
    for (int i = 0; i < TOTAL_WEIGHTS; ++i) {
        _weights[i] = weights[i];
    }
};

void Answer::setText(const char* newText) {
    std::strncpy(_text, newText, MAX_STRING_LENGTH - 1);
    _text[MAX_STRING_LENGTH - 1] = '\0'; // Ensure null-termination.
};

const char* Answer::getText() const {
    return _text;
};

void Answer::setWeight(unsigned int weight, unsigned int index) {
    if (index >= TOTAL_WEIGHTS || index < 0) {
        throw std::invalid_argument("Index is out of bounds.");
    }

    _weights[index] = weight;
};

void Answer::setWeights(unsigned int newWeights[TOTAL_WEIGHTS]) {
    for (int i = 0; i < TOTAL_WEIGHTS; ++i) {
        _weights[i] = newWeights[i];
    }
};

unsigned int Answer::getWeight(unsigned int index) {
    if (index >= TOTAL_WEIGHTS || index < 0) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    
    return _weights[index];
};

unsigned int *Answer::getWeights() {
    return _weights;
};

void Answer::serialize(std::ostream &out) {
    out.write(_text, MAX_STRING_LENGTH);
    out.write((char *)_weights, TOTAL_WEIGHTS * sizeof(unsigned int));
};

void Answer::deserialize(std::istream &in) {
    in.read(_text, MAX_STRING_LENGTH);
    in.read((char *)_weights, TOTAL_WEIGHTS * sizeof(unsigned int));
};

// question.cpp - Functions for the Question class.

Question::Question() {
    std::memset(_prompt, 0, MAX_STRING_LENGTH);
};

Question::Question(const char* prompt, Answer answers[TOTAL_ANSWERS]) {
    std::strncpy(_prompt, prompt, MAX_STRING_LENGTH - 1);
    _prompt[MAX_STRING_LENGTH - 1] = '\0'; // Ensure null-termination
    
    for (int i = 0; i < TOTAL_ANSWERS; ++i) {
        _answers[i] = answers[i];
    }
};

void Question::setPrompt(const char* prompt){
    std::strncpy(_prompt, prompt, MAX_STRING_LENGTH - 1);
    _prompt[MAX_STRING_LENGTH - 1] = '\0'; // Ensure null-termination
};

const char* Question::getPrompt() const {
    return _prompt;
};

void Question::setAnswers(Answer answers[TOTAL_ANSWERS]){
    for (int i = 0; i < TOTAL_ANSWERS; ++i) {
        _answers[i] = answers[i];
    }
};

Answer *Question::getAnswers(){
    return _answers;
};

unsigned int Question::askIndex() {
    std::cout << "QUESTION: " << _prompt << "\n" << std::endl;

    for(unsigned int index = 0; index < TOTAL_ANSWERS; index++) {
        std::cout << index + 1 << ". " << _answers[index].getText() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Enter an answer (1-4): ";

    unsigned int index = -1;

    while(!(std::cin >> index) || index > 4 || 1 > index) {
        std::cout << "Enter an answer (1-4): ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };

    std::cout << "You selected answer " << index << ".\n\n";

    return index - 1;
};

Answer* Question::ask() {
    unsigned int index = askIndex();

    return &_answers[index];
};

void Question::serialize(std::ostream &out) {
    out.write(_prompt, MAX_STRING_LENGTH);
    
    for (int i = 0; i < TOTAL_ANSWERS; ++i) {
        _answers[i].serialize(out);
    }
};

void Question::deserialize(std::istream &in) {
    in.read(_prompt, MAX_STRING_LENGTH);
    
    for (int i = 0; i < TOTAL_ANSWERS; ++i) {
        _answers[i].deserialize(in);
    }
};

// main.cpp - The entry point for the survey program.

void read_questions(Question questions[TOTAL_QUESTIONS]) {
    std::ifstream inFile(QUESTION_FILE, std::ios::binary);

    if (inFile.is_open()) {
        for (unsigned int index = 0; index < TOTAL_QUESTIONS; index++) {
            questions[index].deserialize(inFile);
        }

        inFile.close();
    } 
    
    else {
        std::cerr << "Failed to open file for reading." << std::endl;
    }
}

void write_questions(Question questions[TOTAL_QUESTIONS]) {
   std::ofstream outFile(QUESTION_FILE, std::ios::binary);

    if (outFile.is_open()) {
        for (unsigned int index = 0; index < TOTAL_QUESTIONS; index++) {
            questions[index].serialize(outFile);
        }

        outFile.close();
    } 
    
    else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

// Asks all of the questions, then stores the selected answers and their cumulative weights in buffers.
void ask_questions(Question *questions, Answer *selected_answers[TOTAL_ANSWERS], unsigned int *selected_weights) {
    for (unsigned int index = 0; index < TOTAL_QUESTIONS; index++) {
        Answer *answer = questions[index].ask();

        // Add the answers and combined weights to arrays for the prediction.
        selected_answers[index] = answer;

        for (unsigned int affiliation = 0; affiliation < TOTAL_WEIGHTS; affiliation++) {
            selected_weights[affiliation] += answer -> getWeight(affiliation);
        }
    };
}

// Predicts the political party of the user and displays the results.
// TODO: Find a way to print predictions without hardcoding party values.
void display_weights(unsigned int *weights) {
    float cumulative_weight = 0;

    for (unsigned int index = 0; index < TOTAL_WEIGHTS; index++) {
        cumulative_weight += weights[index];
    }

    std::cout << "PREDICTION: Here are your chances of being in each political party:\n"      << std::endl;
    std::cout << "Blue Party: "   << (weights[0] / cumulative_weight) * 100 << "%  " << std::endl;
    std::cout << "Green Party: "  << (weights[1] / cumulative_weight) * 100 << "%  " << std::endl;
    std::cout << "Yellow Party: " << (weights[2] / cumulative_weight) * 100 << "%  " << std::endl;
    std::cout << "Red Party: "    << (weights[3] / cumulative_weight) * 100 << "%\n" << std::endl;
}

// Prompts the user for their political affiliation and updates weights accordingly.
void update_weights(unsigned int affiliation, Answer *answers[TOTAL_ANSWERS]) {
    for (unsigned int index = 0; index < TOTAL_QUESTIONS; index++) {
        answers[index] -> setWeight(
            answers[index] -> getWeight(affiliation) + 1, 
            affiliation
        );
    }
}

int main(void) {
    // All default questions and weights.
    Question questions[TOTAL_QUESTIONS] = {
        Question("What should the government do to help the poor?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Make it easier to apply for assistance.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Allow parents to have school choice.",    (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Create welfare for work programs.",       (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",    (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("What should the government do to combat terrorism?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Perform community outreach for marginalized groups.",   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Allow private citizens to perform citizens arrests.",   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Conduct espionage campaigns to identify them earlier.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",                  (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("What should the government do to reduce obesity?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Provide healthy eating resources and food aid.",  (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Enforce a maximum calorie limit for all people.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Encourage citizens to exercise and eat healthy.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",            (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("What is your stance on government intervention in the economy?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("They should do it far more often.",                      (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Only if it aligns with the goals of my party.",          (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should only intervene with their words.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",                   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("Should healthcare be a universal right?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Yes, absolutely! Think of the children!",            (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("No, because it will make people less risk-adverse.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("No, because some people do not deserve it.",         (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",               (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("What is your opinion on climate change action?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("It is very good! Think of the children again!", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("It's a government psyop to limit our rights.",  (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("I do not particularly care for it.",            (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",          (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("Should taxes be raised for the wealthiest citizens?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Yes, and taxes for those in poverty should be lowered.",   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Sure, along with everyone elses taxes.",                   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not have taxes in the first place.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",                     (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("Do you support stricter gun control laws?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Yes, because it will keep our streets safe.",  (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("No, because we cannot defend ourselves then!", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Only background checks should be added.",      (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",         (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        )
    };

    // Get questions from the questions file if it already exists.
    if (std::filesystem::exists(QUESTION_FILE)) {
        read_questions(questions);
    }

    // This question is used to determine how the weights are changed for the previous questions.
    Question affiliation_question = Question(
        "What political party do you affiliate with?",
        (Answer[TOTAL_ANSWERS]) {
            // The weights are unused for this particular question.
            Answer("The Blue Party.",   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            Answer("The Green Party.",  (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            Answer("The Yellow Party.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            Answer("The Red Party.",    (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
        }
    );

    // Asking questions, storing results, making predictions, and updating weights according to user affiliation.
    Answer *selected_answers[TOTAL_QUESTIONS];
    unsigned int selected_weights[TOTAL_WEIGHTS] = {0, 0, 0, 0};

    ask_questions(questions, selected_answers, selected_weights);
    display_weights(selected_weights);
    update_weights(
        affiliation_question.askIndex(), 
        selected_answers
    );

    // Writing the updated questions to the file.
    write_questions(questions);

    std::cout << "Thank you for your cooperation!" << std::endl;
    std::cout << "Feel free to try again, as the results can only improve!" << std::endl;
}