// question.cpp - Functions for the Question class.

#include <iostream>
#include <limits>
#include <string>
#include "survey.hpp"

Question::Question() {};

Question::Question(std::string prompt, Answer answers[TOTAL_ANSWERS]) {
    _prompt = prompt;
    
    // Unfortunately, C++ does not allow you to overwrite array contents
    // simply by writing _array = array. That would be too easy!
    unsigned int index = 0;
    unsigned int end = sizeof(_answers) / sizeof(_answers[0]);

    for (index; index < end; index++) {
        _answers[index] = answers[index];
    }
};

void Question::setPrompt(std::string prompt){
    _prompt = prompt;
};

std::string Question::getPrompt(){
    return _prompt;
};

void Question::setAnswers(Answer answers[TOTAL_ANSWERS]){
    unsigned int index = 0;
    unsigned int end = sizeof(_answers) / sizeof(_answers[0]);

    for (index; index < end; index++) {
        _answers[index] = answers[index];
    }
};

Answer *Question::getAnswers(){
    return _answers;
};

unsigned int Question::askIndex() {
    // Display the questions and answers.
    std::cout << "QUESTION: " << _prompt << "\n" << std::endl;

    for(unsigned int index = 0; index < TOTAL_ANSWERS; index++) {
        std::cout << index + 1 << ". " << _answers[index].getText() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Enter an answer (1-4): ";

    // Validate that the answer is not blank, and that it is between 1 and 4.
    unsigned int index = -1;

    while(!(std::cin >> index) || index > 4 || 1 > index) {
        std::cout << "Enter an answer (1-4): ";

        // Ignore invalid inputs to prevent catastrophic failure.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };

    std::cout << "You selected answer " << index << ".\n\n";

    return index - 1;
};

Answer* Question::ask() {
    unsigned int index = askIndex();

    return &_answers[index];
}