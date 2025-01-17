// csv.c - Defines functions for interfacing with the survey CSV file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "survey.h"

void read_csv() {
    // Open the CSV file in read mode.
    FILE *file = fopen(SURVEY_CSV, "r");
    
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", SURVEY_CSV);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];

    // Read each line from the file.
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line by commas.
        char *token = strtok(line, ",");
        
        while (token != NULL) {
            // Print each token (separated by commas).
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }
        
        // Print a new line after processing each row.
        printf("\n");
    }

    fclose(file);
}
