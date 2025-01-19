// question.cpp - Functions for the Question class.

#include <iostream>
#include <limits>
#include <string>
#include "survey.hpp"

// Default constructor for Question class instances.
Question::Question() {};

// Constructor for Question class instances.
Question::Question(std::string prompt, Answer answers[MAX_ANSWER_COUNT]) {
    _prompt = prompt;
    
    // Unfortunately, C++ does not allow you to overwrite array contents
    // simply by writing _array = array. That would be too easy!
    unsigned int index = 0;
    unsigned int end = sizeof(_answers)/sizeof(_answers[0]);

    for (index; index < end; index++) {
        _answers[index] = answers[index];
    }
};

// Sets the prompt attribute for a Question class instance.
void Question::setPrompt(std::string newPrompt){
    _prompt = newPrompt;
};

// Gets the text attribute from a Question class instance.
std::string Question::getPrompt(){
    return _prompt;
};

// Sets the answers for a Question class instance.
void Question::setAnswers(Answer newAnswers[4]){
    unsigned int index = 0;
    unsigned int end = sizeof(_answers)/sizeof(_answers[0]);

    for (index; index < end; index++) {
        _answers[index] = newAnswers[index];
    }
};

// Gets the answers from a Question class instance.
Answer *Question::getAnswers(){
    return _answers;
};

// Prompts the end user with the question.
Answer *Question::ask(){
    unsigned int index = -1;

    std::cout << "QUESTION: " << _prompt << "\n\n";
    std::cout << "1. " << _answers[0].getText() << "\n";
    std::cout << "2. " << _answers[1].getText() << "\n";
    std::cout << "3. " << _answers[2].getText() << "\n";
    std::cout << "4. " << _answers[3].getText() << "\n\n";

    std::cout << "Enter an answer (1-4): ";

    // Validate that the answer is not blank, and that it is between 1 and 4.
    while(!(std::cin >> index) || index > 4 || 1 > index) {
        std::cout << "Enter an answer (1-4): ";

        // Ignore invalid inputs to prevent catastrophic failure.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };

    std::cout << "You selected answer " << index << ".\n\n";

    // Returning this answer by value would cause weight values to
    // only be modified by the copy of the original Answer instance.
    return &_answers[index - 1];
};