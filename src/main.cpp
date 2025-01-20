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
                Answer("Make it easier to apply for assistance.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Allow parents to have school choice.",    (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Create welfare for work programs.",       (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",    (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("What should the government do to combat terrorism?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Perform community outreach for marginalized groups.",   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Allow private citizens to perform citizens arrests.",   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Conduct espionage campaigns to identify them earlier.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",                  (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        ),
        Question("What should the government do to reduce obesity?",
            (Answer[TOTAL_ANSWERS]) {
                Answer("Provide healthy eating resources and food aid.",  (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Enforce a maximum calorie limit for all people.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("Encourage citizens to exercise and eat healthy.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
                Answer("The government should not interfere.",            (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            }
        )
    };

    // This question is used to determine how the weights are changed for the previous questions.
    Question affiliation_question = Question(
        "What political party do you affiliate with?",
        (Answer[TOTAL_ANSWERS]) {
            // The weights are unused for this particular question.
            Answer("The Blue Party.",   (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            Answer("The Green Party.",  (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            Answer("The Yellow Party.", (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
            Answer("The Red Party.",    (unsigned int[TOTAL_WEIGHTS]) {1, 1, 1, 1}),
        }
    );

    // Asking the user the above questions and recording results.
    Answer *selected_answers[TOTAL_QUESTIONS];
    unsigned int selected_weights[TOTAL_WEIGHTS] = {0, 0, 0, 0};

    for (unsigned int index = 0; index < TOTAL_QUESTIONS; index++) {
        Answer *answer = questions[index].ask();

        // Add the answers and combined weights to arrays for the prediction.
        selected_answers[index] = answer;

        for (unsigned int affiliation = 0; affiliation < TOTAL_WEIGHTS; affiliation++) {
            selected_weights[affiliation] += answer -> getWeight(affiliation);
        }
    };

    // Predicts the political party of the user.
    // TODO: Find a way to print predictions without hardcoding party values.
    float cumulative_weight = 0;

    for (unsigned int index = 0; index < TOTAL_WEIGHTS; index++) {
        cumulative_weight += selected_weights[index];
    }

    std::cout << "PREDICTION: Here are your chances of being in each political party:" << std::endl;
    std::cout << "Blue Party: "   << (selected_weights[0] / cumulative_weight) * 100 << "%  " << std::endl;
    std::cout << "Green Party: "  << (selected_weights[1] / cumulative_weight) * 100 << "%  " << std::endl;
    std::cout << "Yellow Party: " << (selected_weights[2] / cumulative_weight) * 100 << "%  " << std::endl;
    std::cout << "Red Party: "    << (selected_weights[3] / cumulative_weight) * 100 << "%\n" << std::endl;

    // Prompts the user for their political affiliation and updates weights accordingly.
    unsigned int affiliation = affiliation_question.askIndex();

    for (unsigned int index = 0; index < TOTAL_QUESTIONS; index++) {
        selected_answers[index] -> setWeight(
            selected_answers[index] -> getWeight(affiliation) + 1, 
            affiliation
        );
    }

    // TODO: Export the results to a file.
    std::cout << "Thank you for your cooperation!" << std::endl;
    std::cout << "Feel free to try again, as the results can only improve!" << std::endl;
}