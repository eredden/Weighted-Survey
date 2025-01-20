// main.cpp - The entry point for the survey program.

#include <fstream>
#include <iostream>
#include <string>
#include "survey.hpp"

int main(void) {
    // All default questions asked to the user apart from the political party affiliation question.
    Question questions[TOTAL_QUESTIONS] = {
        Question("What should the government do to help the poor?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Make it easier to apply for assistance.", (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("Allow parents to have school choice.",    (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("Create welfare for work programs.",       (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("The government should not interfere.",    (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
            }
        ),
        Question("What should the government do to combat terrorism?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Perform community outreach for marginalized groups.",   (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("Allow private citizens to perform citizens arrests.",   (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("Conduct espionage campaigns to identify them earlier.", (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("The government should not interfere.",                  (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
            }
        ),
        Question("What should the government do to reduce obesity?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Provide healthy eating resources and food aid.",  (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("Enforce a maximum calorie limit for all people.", (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("Encourage citizens to exercise and eat healthy.", (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
                Answer("The government should not interfere.",            (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
            }
        )
    };

    // This question is used to determine how the weights are changed for the previous questions.
    Question affiliation_question = Question(
        "What political party do you affiliate with?",
        (Answer[TOTAL_ANSWERS]) {
            Answer("The Blue Party.",   (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
            Answer("The Green Party.",  (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
            Answer("The Yellow Party.", (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
            Answer("The Red Party.",    (unsigned int[TOTAL_WEIGHTS]) {0, 0, 0, 0}),
        }
    );

    // Ask the user each question and store the selected answers.
    Answer *selected_answers[TOTAL_QUESTIONS];

    for (unsigned int index = 0; index < TOTAL_QUESTIONS; index++) {
        Answer *answer = questions[index].ask();

        selected_answers[index] = answer;
    };

    // TODO: Create a function that predicts what political party the user is in.
    // Prompt the user for their political affiliation and update weights accordingly.
    unsigned int affiliation = affiliation_question.askIndex();

    for (unsigned int index = 0; index < TOTAL_QUESTIONS; index++) {
        selected_answers[index] -> setWeight(
            selected_answers[index] -> getWeight(affiliation) + 1, 
            affiliation
        );
    }

    // TODO: Export the results to a file.
}