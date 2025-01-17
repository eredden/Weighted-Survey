// survey.h - Defines questions, answers, and functions for working with them.

#ifndef SURVEY_H
#define SURVEY_H

#define MAX_TEXT_LENGTH 64
#define MAX_ANSWER_COUNT 4
#define MAX_WEIGHT_COUNT 4

enum party {
    DEMOCRAT,
    GREEN,
    LIBERTARIAN,
    REPUBLICAN
};

// Data structure used to define answers and their weights.
typedef struct answer {
    const char text[MAX_TEXT_LENGTH];
    int        weights[MAX_WEIGHT_COUNT]; // Four weights for each of the enum party options.
} answer_t;

// Data structure used to define questions.
typedef struct question {
    const char     text[MAX_TEXT_LENGTH];
    const answer_t answers[MAX_ANSWER_COUNT];
} question_t;

// Asks the user a question and returns their selected answer.
answer_t ask_question(question_t question);

#endif // SURVEY_H