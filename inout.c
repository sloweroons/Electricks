#include "inout.h"

#define MAX_CARD_NUMBER 3

char** split(char *text) {
    char **cards = (char**)malloc(MAX_CARD_NUMBER*sizeof(char*));
    cards[0] = NULL; cards[1] = NULL; cards[2] = NULL;
    int char_index = 0; int card_index = 0; int card_size = 0; int start_index = 0;

    while (text[char_index] != '\0') {
        if (text[char_index] != ' ') {
            if (card_index >= MAX_CARD_NUMBER) {
                return NULL;
            }
            ++card_size;
            cards[card_index] = (char*)malloc((card_size+1)*sizeof(char));
            strncpy(cards[card_index], text+start_index, card_size);
            cards[card_index][card_size] = '\0';
        }
        else {
            ++card_index;
            start_index += card_size + 1;
            card_size = 0;
        }
        ++char_index;
    }

    return cards;
}

input_structure create_card(char *text) {
    input_structure _card;
    _card.type = CARD;

    char** res = split(text);
    if (res == NULL) {
        printf(" error: PLEASE INPUT A MAXIMUM OF 3 CARDS");
        return;
    }
    char *cards[3] = {res[0], res[1], res[2]};
    free(res);

    _card.card1 = cards[0];
    _card.card2 = cards[1];
    _card.card3 = cards[2];
    _card.cards_pointer = show_cards;
    return _card;
}

input_structure create_smiley(char *text) {
    input_structure _smiley;
    _smiley.type = SMILEY;
    _smiley.smiley = text;
    _smiley.smiley_pointer = show_smiley;
    return _smiley;
}

void show_cards(char *card1, char *card2, char *card3) {
    if (card1 != NULL) {
        printf("%s", card1);
        if (card2 != NULL) {
            printf(" %s", card2);
            if (card3 != NULL) {
                printf(" %s", card3);
            }
        }
    }
    printf("\n");
    free(card1); free(card2); free(card3);
}

void show_smiley(char *smiley) {
    printf("%s\n", smiley);
    //free(smiley);
}

bool show(input_structure input) {
    switch (input.type) {
        case CARD :
            input.cards_pointer(input.card1, input.card2, input.card3);
            return true;
        case SMILEY :
            input.smiley_pointer(input.smiley);
            return true;
        default:
            return false;
    }
}

bool is_card(char *text) {
    char color[2];
    color[0] = text[strlen(text)-1];
    color[1] = '\0';
    char value[strlen(text)];
    for(int p = 0; p < strlen(text)-1; ++p) {
        value[p] = text[p];
    }
    value[strlen(text)-1] = '\0';
    bool is_card = false;
    for (int i = 0; i < sizeof(card_values)/sizeof(card_values[0]); ++i) {
        if (strcmp(value, card_values[i]) == 0) {
            is_card = true;
            break;
        }
    }
    if (!is_card) return false;
    is_card = false;
    for (int j = 0; j < sizeof(card_colors)/sizeof(card_colors[0]); ++j) {
        if (strcmp(color, card_colors[j]) == 0) {
            is_card = true;
            break;
        }
    }
    if (!is_card ) return false;
    return true;
}

bool are_cards(char *text) {
    char** res = split(text);
    if (res == NULL) {
        printf(" error: PLEASE INPUT A MAXIMUM OF 3 CARDS");
        return false;
    }
    char* cards[3] = {res[0], res[1], res[2]};
    for (int i = 0; i < 3; ++i) {
        if (cards[i] != NULL) {
            if (!is_card(cards[i])) {
                return false;
            }
        }
    }
    return true;
}

bool is_smiley(char *text) {
    char smiley[strlen(text)+1];
    for(int p = 0; p < strlen(text); ++p) {
        smiley[p] = text[p];
    }
    smiley[strlen(text)] = '\0';
    bool is_smiley = false;
    for (int i = 0; i < sizeof(smileys)/sizeof(smileys[0]); ++i) {
        if (strcmp(smiley, smileys[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool smarttext_recognize(char *text) {
    input_structure input;
    if (are_cards(text)) {
        input = create_card(text);
        show(input);
        return true;
    } else
    if (is_smiley(text)) {
        input = create_smiley(text);
        show(input);
        return true;
    }
    else return false;
}
