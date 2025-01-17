// main.c - The entry point for the survey program.

#include <stdio.h>
#include "survey.h"

int main(void) {
    // TODO: Create data file that stores questions and answers
    // and import the data into this program when loaded.
    question_t question = {
        "What should the government do to help the poor?",
        {
            (answer_t) {
                "Make it easier to apply for assistance.", 
                {0, 0, 0, 0}
            },
            (answer_t) {
                "Allow parents to use education funds for charter schools.", 
                {0, 0, 0, 0}
            },
            (answer_t) {
                "Create welfare to work programs.", 
                {0, 0, 0, 0}
            },
            (answer_t) {
                "Nothing.", 
                {0, 0, 0, 0}
            }
        }
    };

    ask_question(question);
}