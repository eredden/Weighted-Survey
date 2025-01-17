// survey.c - Functions for interacting with questions and answers.

#include <stdio.h>
#include "survey.h"

answer_t ask_question(question_t question) {
    int index = -1;
    answer_t answer;

    printf("QUESTION: %s\n\n", question.text);
    printf("1. %s\n", question.answers[0].text);
    printf("2. %s\n", question.answers[1].text);
    printf("3. %s\n", question.answers[2].text);
    printf("4. %s\n\n", question.answers[3].text);

    do {
        printf("Enter an answer (1-4): ");
        scanf("%1d", &index);
    } while(index > 4 || 1 > index);

    return question.answers[index - 1];
}