#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "wordle.h"

int main() {
    char words[MAX_WORDS][WORD_LENGTH+1];
    int word_count = load_words("../resources/words.txt", words);
    
    if (word_count == 0) {
        fprintf(stderr, "Error: Could not load words.\n");
        return EXIT_FAILURE;
    }
    
    srand(time(NULL));
    const char *target = words[rand() % word_count];
    
    display_welcome();
    
    int attempts = 0;
    char guess[WORD_LENGTH+1];
    char feedback[WORD_LENGTH+1];
    
    while (attempts < MAX_ATTEMPTS) {
        display_attempt(attempts, MAX_ATTEMPTS);
        
        if (scanf("%5s", guess) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            printf("Invalid input. Please try again.\n");
            continue;
        }
        
        // Convert to lowercase
        for (int i = 0; i < WORD_LENGTH; i++) {
            guess[i] = tolower(guess[i]);
        }
        
        if (strlen(guess) != WORD_LENGTH) {
            printf("Please enter exactly %d letters.\n", WORD_LENGTH);
            continue;
        }
        
        if (!is_valid_word(guess, words, word_count)) {
            printf("Not a valid word. Try again.\n");
            continue;
        }
        
        check_guess(guess, target, feedback);
        display_feedback(feedback);
        
        if (is_game_won(feedback)) {
            display_win(attempts + 1);
            return EXIT_SUCCESS;
        }
        
        attempts++;
    }
    
    display_loss(target);
    return EXIT_SUCCESS;
}
