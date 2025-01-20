// survey.hpp - Defines questions, answers, and functions for working with them.

#include <iostream>
#include <string>

#ifndef SURVEY_H
#define SURVEY_H

// Note that TOTAL_QUESTIONS excludes the last question about political affiliation.
#define TOTAL_QUESTIONS  3
#define MAX_ANSWER_COUNT 4
#define MAX_WEIGHT_COUNT 4

enum Party : unsigned int {
    Blues,
    Greens,
    Yellows,
    Reds
};

class Answer {
    public:
        Answer();
        Answer(std::string text, unsigned int weights[MAX_ANSWER_COUNT]);

        void setText(std::string newText);
        std::string getText();

        void setWeights(unsigned int newWeights[MAX_WEIGHT_COUNT]);
        unsigned int *getWeights();
        
    private:
        std::string  _text;
        unsigned int _weights[4];
};

class Question {
    public:
        Question();
        Question(std::string prompt, Answer answers[MAX_ANSWER_COUNT]);

        void setPrompt(std::string newPrompt);
        std::string getPrompt();

        void setAnswers(Answer newAnswers[MAX_ANSWER_COUNT]);
        Answer *getAnswers();

        Answer *ask();
        unsigned int askPosition();

    private:
        std::string _prompt;
        Answer _answers[MAX_ANSWER_COUNT];
};

#endif // SURVEY_H