// survey.hpp - Defines questions, answers, and functions for working with them.

#include <iostream>

#ifndef SURVEY_H
#define SURVEY_H

// Note that TOTAL_QUESTIONS excludes the last question about political affiliation.
#define TOTAL_QUESTIONS 8
#define TOTAL_ANSWERS 4
#define TOTAL_WEIGHTS 4
#define MAX_STRING_LENGTH 64
#define QUESTION_FILE "question.dat"

class Answer {
    public:
        // Default constructor for Answer class instances.
        Answer();

        // Constructor for Answer class instances.
        Answer(const char* text, unsigned int weights[TOTAL_ANSWERS]);

        // Sets the text attribute for an Answer class instance.
        void setText(const char* text);

        // Gets the text from an Answer class instance.
        const char* getText() const;

        // Sets the value of an individual weight for an Answer class instance.
        void setWeight(unsigned int weight, unsigned int index);

        // Gets the value of an individual weight for an Answer class instance.
        unsigned int getWeight(unsigned int index);

        // Sets the weights for an Answer class instance.
        void setWeights(unsigned int weights[TOTAL_WEIGHTS]);

        // Gets the weights from an Answer class instance.
        unsigned int *getWeights();

        // Serializes the Answer instance to a binary file.
        void serialize(std::ostream &out);

        // Deserializes the Answer instance from a binary file.
        void deserialize(std::istream &in);
        
    private:
        char _text[MAX_STRING_LENGTH];
        unsigned int _weights[4];
};

class Question {
    public:
        // Default constructor for Question class instances.
        Question();

        // Constructor for Question class instances.
        Question(const char* prompt, Answer answers[TOTAL_ANSWERS]);

        // Sets the prompt attribute for a Question class instance.
        void setPrompt(const char* prompt);

        // Gets the text attribute from a Question class instance.
        const char* getPrompt() const;

        // Sets the answers for a Question class instance.
        void setAnswers(Answer answers[TOTAL_ANSWERS]);

        // Gets the answers from a Question class instance.
        Answer *getAnswers();

        // Prompts the end user with the question and returns the answer.
        Answer *ask();

        // Prompts the end user with the question and returns the answers index.
        unsigned int askIndex();

        // Serializes the Question instance to a binary file.
        void serialize(std::ostream &out);

        // Deserializes the Question instance from a binary file.
        void deserialize(std::istream &in);

    private:
        char _prompt[MAX_STRING_LENGTH];
        Answer _answers[TOTAL_ANSWERS];
};

#endif // SURVEY_H