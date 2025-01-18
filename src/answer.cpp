// answer.cpp - Functions for the Answer class.

#include <iostream>
#include <string>
#include "survey.hpp"

// Default constructor for Answer class instances.
Answer::Answer() {};

// Constructor for Answer class instances.
Answer::Answer(std::string text, unsigned int weights[MAX_ANSWER_COUNT]) {
    _text = text;
    
    // Unfortunately, C++ does not allow you to overwrite array contents
    // simply by writing _array = array. That would be too easy!
    unsigned int index = 0;
    unsigned int end = sizeof(_weights)/sizeof(_weights[0]);

    for (index; index < end; index++) {
        _weights[index] = weights[index];
    }
};

// Sets the text attribute for an Answer class instance.
void Answer::setText(std::string newText) {
    _text = newText;
};

// Gets the text from an Answer class instance.
std::string Answer::getText() {
    return _text;
};

// Sets the weights for an Answer class instance.
void Answer::setWeights(unsigned int newWeights[4]) {
    unsigned int index = 0;
    unsigned int end = sizeof(_weights)/sizeof(_weights[0]);

    for (index; index < end; index++) {
        _weights[index] = newWeights[index];
    }
};

// Gets the weights from an Answer class instance.
unsigned int *Answer::getWeights(){
    return _weights;
};