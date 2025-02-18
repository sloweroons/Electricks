#include <stdio.h>
#include <stdlib.h>
#include "inout.h"

#define MAX_INPUT_SIZE 256

int main()
{
    char* c1 = "AH AH 10D"; char* c2 = "10D"; char* c3 = "110D";
    char* s1 = ":)"; char* s2 = ":()"; char* s3 = ":-)";

    /*

    printf("%s\n", is_card(c1) ? "YES" : "NO");
    printf("%s\n", is_card(c2) ? "YES" : "NO");
    printf("%s\n", is_card(c3) ? "YES" : "NO");

    printf("%s\n", is_smiley(s1) ? "YES" : "NO");
    printf("%s\n", is_smiley(s2) ? "YES" : "NO");
    printf("%s\n", is_smiley(s3) ? "YES" : "NO");

    */

    /*

    printf("%s\n", smarttext_recognize(c1) ? "YES" : "NO");
    printf("%s\n", smarttext_recognize(c2) ? "YES" : "NO");
    printf("%s\n", smarttext_recognize(c3) ? "YES" : "NO");

    printf("%s\n", smarttext_recognize(s1) ? "YES" : "NO");
    printf("%s\n", smarttext_recognize(s2) ? "YES" : "NO");
    printf("%s\n", smarttext_recognize(s3) ? "YES" : "NO");

    */

    /*

    smarttext_recognize(c1);
    smarttext_recognize(c2);
    smarttext_recognize(c3);

    smarttext_recognize(s1);
    smarttext_recognize(s2);
    smarttext_recognize(s3);

    */

    // TODO: IGNORE WS BG

    printf("|**-----------------------------------**|\n");
    printf("|*>PLEASE INPUT YOUR CARD(s) OR SMILEY<*|\n");
    printf("|**-----------------------------------**|\n");
    printf("|**-------(input enter to exit)-------**|\n");
    printf("|********\\---------------------/********|\n\n");

    while (true) {
        char* buffer = (char*)malloc(MAX_INPUT_SIZE*sizeof(char));
        char* input = (char*)malloc(MAX_INPUT_SIZE*sizeof(char));
        printf("> ");
        fgets(buffer, MAX_INPUT_SIZE, stdin);
        if (strcmp(buffer, "\n") == 0) {
            free(buffer); free(input);
            break;
        }
        int start_index = 0;
        while (buffer[start_index] == ' ') ++start_index;
        strncpy(input, buffer+start_index, strlen(buffer-start_index)-1);
        strncpy(input+strlen(buffer)-start_index-1, "\0", 1);
        smarttext_recognize(input);
        printf("\n");
        free(buffer); free(input);
    }
    return 0;
}
