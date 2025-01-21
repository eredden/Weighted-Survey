// question.cpp - Functions for the Question class.

#include <fstream>
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

void Question::serialize(std::ofstream &out) const {
    size_t prompt_length = MAX_STRING_LENGTH;
    out.write(reinterpret_cast<const char*>(&prompt_length), sizeof(prompt_length));
    out.write(_prompt.c_str(), prompt_length);

    for (int i = 0; i < TOTAL_ANSWERS; ++i) {
        size_t answer_length = MAX_STRING_LENGTH;
        out.write(reinterpret_cast<const char*>(&answer_length), sizeof(answer_length));
        out.write(_answers[i].getText().c_str(), answer_length);
    }
}

void Question::deserialize(std::ifstream &in) {
    size_t prompt_length;
    in.read(reinterpret_cast<char*>(&prompt_length), sizeof(prompt_length));
    _prompt.resize(prompt_length);
    in.read(&_prompt[0], prompt_length);

    for (int i = 0; i < TOTAL_ANSWERS; ++i) {
        size_t answer_length;
        in.read(reinterpret_cast<char*>(&answer_length), sizeof(answer_length));
        std::string answer_text(answer_length, '\0');
        in.read(&answer_text[0], answer_length);
        _answers[i].setText(answer_text);
    }
}

// ...existing code...