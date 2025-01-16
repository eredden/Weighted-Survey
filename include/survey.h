// quiz.h - Defines questions, answers, and functions for working with them.

#ifndef SURVEY_H
#define SURVEY_H

enum party 
{
    DEMOCRAT,
    GREEN,
    LIBERTARIAN,
    REPUBLICAN
};

// Data structure used to define answers and their weights.
typedef struct answer 
{
    const char *text;
    int  weights[4]; // Four weights for each of the enum party options.
} answer_t;

// Data structure used to define questions.
typedef struct question 
{
    const char     *text;
    const answer_t answers[4];
} question_t;

// Factory functions are used to generate structs.
answer_t answer_factory(const char *text, int weights[4]);
question_t question_factory(const char *text, answer_t answers[4]);

#endif // SURVEY_H