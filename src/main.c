// main.c - The entry point for the survey program.

#include <stdio.h>
#include "survey.h"

int main(void) 
{
    // TODO: Create data file that stores questions and answers
    // and import the data into this program when loaded.
    question_t question_1 = {
        "What should the government do to help the poor?",
        {
            (answer_t) 
            {
                "Make it easier to apply for assistance.", 
                {0, 0, 0, 0}
            },
            (answer_t) 
            {
                "Allow parents to use education funds for charter schools.", 
                {0, 0, 0, 0}
            },
            (answer_t) 
            {
                "Create welfare to work programs.", 
                {0, 0, 0, 0}
            },
            (answer_t) 
            {
                "Nothing.", 
                {0, 0, 0, 0}
            }
        }
    };

    printf("QUESTION: %s\n\n", question_1.text);
    printf("ANSWER 1: %s\n", question_1.answers[0].text);
    printf("ANSWER 2: %s\n", question_1.answers[1].text);
    printf("ANSWER 3: %s\n", question_1.answers[2].text);
    printf("ANSWER 4: %s\n", question_1.answers[3].text);
}