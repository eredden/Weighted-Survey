// A command-line quiz program.

#include <stdio.h>
#include "quiz.h"

int main(void) 
{
    answer_t answer = {
        "Everest", 
        {
            0,
            0,
            0,
            0
        }
    };

    printf("TEXT: %s\n", answer.text);
    printf("AFFILIATION: %d\n", answer.weights[0]);
}