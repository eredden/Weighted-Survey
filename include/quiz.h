#ifndef QUIZ_H
#define QUIZ_H

enum party 
{
    DEMOCRAT,
    GREEN,
    LIBERTARIAN,
    REPUBLICAN
};

typedef struct answer 
{
    const char *text;
    int  weights[4];
} answer_t;

typedef struct question 
{
    const char     *text;
    const answer_t answers[4];
} question_t;

#endif // QUIZ_H