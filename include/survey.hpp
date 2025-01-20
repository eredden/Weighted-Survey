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
        // Default constructor for Answer class instances.
        Answer();

        // Constructor for Answer class instances.
        Answer(std::string text, unsigned int weights[TOTAL_ANSWERS]);

        // Sets the text attribute for an Answer class instance.
        void setText(std::string newText);

        // Gets the text from an Answer class instance.
        std::string getText();

        // Sets the value of an individual weight for an Answer class instance.
        void setWeight(unsigned int weight, unsigned int index);

        // Gets the value of an individual weight for an Answer class instance.
        unsigned int getWeight(unsigned int index);

        // Sets the weights for an Answer class instance.
        void setWeights(unsigned int newWeights[TOTAL_WEIGHTS]);

        // Gets the weights from an Answer class instance.
        unsigned int *getWeights();
        
    private:
        std::string  _text;
        unsigned int _weights[4];
};

class Question {
    public:
        // Default constructor for Question class instances.
        Question();

        // Constructor for Question class instances.
        Question(std::string prompt, Answer answers[TOTAL_ANSWERS]);

        // Sets the prompt attribute for a Question class instance.
        void setPrompt(std::string newPrompt);

        // Gets the text attribute from a Question class instance.
        std::string getPrompt();

        // Sets the answers for a Question class instance.
        void setAnswers(Answer newAnswers[TOTAL_ANSWERS]);

        // Gets the answers from a Question class instance.
        Answer *getAnswers();

        // Prompts the end user with the question and returns the answer.
        Answer *ask();

        // Prompts the end user with the question and returns the answers index.
        unsigned int askIndex();

    private:
        std::string _prompt;
        Answer _answers[TOTAL_ANSWERS];
};

#endif // SURVEY_H