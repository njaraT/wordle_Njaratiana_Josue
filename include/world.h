#ifndef WORDLE_H
#define WORDLE_H

#define WORD_LENGTH 5
#define MAX_ATTEMPTS 6
#define MAX_WORDS 2309 // Matches Wordle's word list size

// Word list functions
int load_words(const char *filename, char words[][WORD_LENGTH+1]);
void free_words(char words[][WORD_LENGTH+1], int count);

// Game logic functions
int is_valid_word(const char *word, char words[][WORD_LENGTH+1], int word_count);
void check_guess(const char *guess, const char *target, char *feedback);
int is_game_won(const char *feedback);

// UI functions
void display_welcome(void);
void display_attempt(int attempt, int max_attempts);
void display_feedback(const char *feedback);
void display_win(int attempts);
void display_loss(const char *target);

#endif
