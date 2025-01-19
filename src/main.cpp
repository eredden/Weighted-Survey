// main.cpp - The entry point for the survey program.

#include <iostream>
#include <string>
#include "survey.hpp"

int main(void) {
    // TODO: Create data file that stores questions and answers
    // and import the data into this program when loaded.

    // All questions asked to the user apart from the political party affiliation question.
    Question questions[TOTAL_QUESTIONS] = {
        Question("What should the government do to help the poor?",
            (Answer[MAX_ANSWER_COUNT]) {
                Answer("Make it easier to apply for assistance.", (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("Allow parents to have school choice.",    (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("Create welfare for work programs.",       (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("The government should not interfere.",    (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
            }
        ),
        Question("What should the government do to combat terrorism?",
            (Answer[MAX_ANSWER_COUNT]) {
                Answer("Perform community outreach for marginalized groups.",   (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("Allow private citizens to perform citizens arrests.",   (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("Conduct espionage campaigns to identify them earlier.", (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("The government should not interfere.",                  (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
            }
        ),
        Question("What should the government do to reduce obesity?",
            (Answer[MAX_ANSWER_COUNT]) {
                Answer("Provide healthy eating resources and food aid.",  (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("Enforce a maximum calorie limit for all people.", (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("Encourage citizens to exercise and eat healthy.", (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
                Answer("The government should not interfere.",            (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
            }
        )
    };

    // This question is used to determine how the weights are changed for the previous questions.
    Question affiliation_question = Question(
        "What political party do you affiliate with?",
        (Answer[MAX_ANSWER_COUNT]) {
            Answer("The Blue Party.",   (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
            Answer("The Green Party.",  (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
            Answer("The Yellow Party.", (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
            Answer("The Red Party.",    (unsigned int[MAX_WEIGHT_COUNT]) {0, 0, 0, 0}),
        }
    );

    // Ask the user each question and store the selected answers.
    Answer *selected_answers[TOTAL_QUESTIONS];

    for (int index = 0; index < TOTAL_QUESTIONS; index++) {
        Answer *answer = questions[index].ask();

        selected_answers[index] = answer;
    };

    // TODO: Create a function that predicts what political party the user is in.
    // TODO: Prompt the user for their political party and adjust the weights of the questions.
    // TODO: Export the results to a file.
}