// answer.cpp - Functions for the Answer class.

#include <iostream>
#include <cstring>
#include "survey.hpp"

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