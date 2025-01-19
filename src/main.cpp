// main.cpp - The entry point for the survey program.

#include <iostream>
#include <string>
#include "survey.hpp"

int main(void) {
    // TODO: Create data file that stores questions and answers
    // and import the data into this program when loaded.

    // TODO: Make the size of this array adjust with the amount of questions
    // that are loaded into this program.
    Answer answers[3];

    // TODO: Ask imported questions iteratively.
    Question question = Question(
        "What should the government do to help the poor?",
        (Answer[MAX_ANSWER_COUNT]) {
            Answer(
                "Make it easier to apply for assistance.", 
                (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}
            ),
            Answer(
                "Allow parents to use education funds for charter schools.", 
                (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}
            ),
            Answer(
                "Create welfare for work programs.", 
                (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}
            ),
            Answer(
                "Nothing.", 
                (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}
            ),
        }
    );

    question.ask();
}