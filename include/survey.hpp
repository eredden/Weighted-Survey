// survey.hpp - Defines questions, answers, and functions for working with them.

#include <iostream>
#include <string>

#ifndef SURVEY_H
#define SURVEY_H

// Note that TOTAL_QUESTIONS excludes the last question about political affiliation.
#define TOTAL_QUESTIONS 3
#define TOTAL_ANSWERS   4
#define TOTAL_WEIGHTS   4

class Answer {
    public:
        Answer();
        Answer(std::string text, unsigned int weights[TOTAL_ANSWERS]);

        void setText(std::string newText);
        std::string getText();

        void setWeight(unsigned int weight, unsigned int index);
        unsigned int getWeight(unsigned int index);

        void setWeights(unsigned int newWeights[TOTAL_WEIGHTS]);
        unsigned int *getWeights();
        
    private:
        std::string  _text;
        unsigned int _weights[4];
};

class Question {
    public:
        Question();
        Question(std::string prompt, Answer answers[TOTAL_ANSWERS]);

        void setPrompt(std::string newPrompt);
        std::string getPrompt();

        void setAnswers(Answer newAnswers[TOTAL_ANSWERS]);
        Answer *getAnswers();

        Answer *ask();
        unsigned int askIndex();

    private:
        std::string _prompt;
        Answer _answers[TOTAL_ANSWERS];
};

#endif // SURVEY_H