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
    unsigned int end = sizeof(_weights) / sizeof(_weights[0]);

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

// Sets the value of an individual weight for an Answer class instance.
void Answer::setWeight(unsigned int weight, unsigned int index) {
    if (index >= MAX_WEIGHT_COUNT || index < 0) {
        throw std::invalid_argument("Index is out of bounds.");
    }

    _weights[index] = weight;
};

// Sets the weights for an Answer class instance.
void Answer::setWeights(unsigned int newWeights[MAX_WEIGHT_COUNT]) {
    unsigned int index = 0;
    unsigned int end = sizeof(_weights) / sizeof(_weights[0]);

    for (index; index < end; index++) {
        _weights[index] = newWeights[index];
    }
};

// Gets the value of an individual weight for an Answer class instance.
unsigned int Answer::getWeight(unsigned int index) {
    if (index >= MAX_WEIGHT_COUNT || index < 0) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    
    return _weights[index];
};

// Gets the weights from an Answer class instance.
unsigned int *Answer::getWeights(){
    return _weights;
};