#include <stdio.h>
#include "wordle.h"

void display_welcome(void) {
    printf("\n=== WORDLE GAME ===\n");
    printf("Guess the %d-letter word in %d attempts\n", WORD_LENGTH, MAX_ATTEMPTS);
    printf("Feedback legend:\n");
    printf("  V - Correct letter in correct position\n");
    printf("  D - Correct letter in wrong position\n");
    printf("  X - Letter not in word\n\n");
}

void display_attempt(int attempt, int max_attempts) {
    printf("Attempt %d/%d: ", attempt + 1, max_attempts);
}

void display_feedback(const char *feedback) {
    printf("Feedback: ");
    for (int i = 0; i < WORD_LENGTH; i++) {
        printf("%c ", feedback[i]);
    }
    printf("\n\n");
}

void display_win(int attempts) {
    printf("\nCongratulations! You won in %d attempts!\n", attempts);
}

void display_loss(const char *target) {
    printf("\nGame over! The word was: %s\n", target);
}
