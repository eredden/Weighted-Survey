// question.cpp - Functions for the Question class.

#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include "survey.hpp"

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