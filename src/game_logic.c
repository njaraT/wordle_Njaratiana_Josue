#include <string.h>
#include <ctype.h>
#include "wordle.h"

int is_valid_word(const char *word, char words[][WORD_LENGTH+1], int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, words[i]) == 0) return 1;
    }
    return 0;
}

void check_guess(const char *guess, const char *target, char *feedback) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == target[i]) {
            feedback[i] = 'V'; // Correct position
        } else if (strchr(target, guess[i]) != NULL) {
            feedback[i] = 'D'; // Correct letter wrong position
        } else {
            feedback[i] = 'X'; // Not in word
        }
    }
    feedback[WORD_LENGTH] = '\0';
}

int is_game_won(const char *feedback) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (feedback[i] != 'V') return 0;
    }
    return 1;
}
