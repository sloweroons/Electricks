#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static const char* card_values[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
static const char* card_colors[] = {"C", "H", "S", "D"};
static const char* smileys[] = {":)", ":-)", ":("};

typedef enum {
    CARD,
    SMILEY
} input_type;

typedef struct input_structure {
    input_type type;
    union {
        // CARD
        struct {
            char *card1;
            char *card2;
            char *card3;
            void (*cards_pointer)(char *card1, char *card2, char *card3);
        };
        // SMILEY
        struct {
            char *smiley;
            void (*smiley_pointer)(char *smiley);
        };
    };
} input_structure;

// if CARD set CARDS_POINTER
bool smarttext_recognize(char *text);
void show_cards(char *card1, char *card2, char *card3);
void show_smiley(char *smiley);
bool is_card(char *text);
bool is_smiley(char *text);
