#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordle.h"

int load_words(const char *filename, char words[][WORD_LENGTH+1]) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;
    
    int count = 0;
    while (count < MAX_WORDS && fscanf(file, "%5s", words[count]) == 1) {
        // Convert to lowercase
        for (int i = 0; i < WORD_LENGTH; i++) {
            words[count][i] = tolower(words[count][i]);
        }
        count++;
    }
    
    fclose(file);
    return count;
}

void free_words(char words[][WORD_LENGTH+1], int count) {
    // No dynamic allocation in this simple version
    // Placeholder for future expansion
}
