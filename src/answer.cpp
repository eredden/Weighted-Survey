// answer.cpp - Functions for the Answer class.

#include <iostream>
#include <string>
#include "survey.hpp"

Answer::Answer() {};

Answer::Answer(std::string text, unsigned int weights[TOTAL_ANSWERS]) {
    _text = text;
    
    // Unfortunately, C++ does not allow you to overwrite array contents
    // simply by writing _array = array. That would be too easy!
    unsigned int index = 0;
    unsigned int end = sizeof(_weights) / sizeof(_weights[0]);

    for (index; index < end; index++) {
        _weights[index] = weights[index];
    }
};

void Answer::setText(std::string newText) {
    _text = newText;
};

std::string Answer::getText() const {
    return _text;
};

void Answer::setWeight(unsigned int weight, unsigned int index) {
    if (index >= TOTAL_WEIGHTS || index < 0) {
        throw std::invalid_argument("Index is out of bounds.");
    }

    _weights[index] = weight;
};

void Answer::setWeights(unsigned int newWeights[TOTAL_WEIGHTS]) {
    unsigned int index = 0;
    unsigned int end = sizeof(_weights) / sizeof(_weights[0]);

    for (index; index < end; index++) {
        _weights[index] = newWeights[index];
    }
};

unsigned int Answer::getWeight(unsigned int index) {
    if (index >= TOTAL_WEIGHTS || index < 0) {
        throw std::invalid_argument("Index is out of bounds.");
    }
    
    return _weights[index];
};

unsigned int *Answer::getWeights(){
    return _weights;
};