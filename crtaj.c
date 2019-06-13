#include <stdio.h>
#include "crtaj.h"

void crtaj(int hangman) {
    switch(hangman) {
        case 0:
                printf("|------|\n");
                printf("|      \n");
                printf("|     \n");
                printf("|      \n");
                printf("|     \n");
                printf("|\n");
                printf("|__");
                break;

        case 1:
                printf("|------|\n");
                printf("|      O\n");
                printf("|     \n");
                printf("|      \n");
                printf("|     \n");
                printf("|\n");
                printf("|__");
                break;

        case 2:
                printf("|------|\n");
                printf("|      O\n");
                printf("|      |\n");
                printf("|      |\n");
                printf("|     \n");
                printf("|\n");
                printf("|__");
                break;

        case 3:
                printf("|------|\n");
                printf("|      O\n");
                printf("|     /|\n");
                printf("|      |\n");
                printf("|     \n");
                printf("|\n");
                printf("|__");
                break;

        case 4:
                printf("|------|\n");
                printf("|      O\n");
                printf("|     /|\\\n");
                printf("|      |\n");
                printf("|     \n");
                printf("|\n");
                printf("|__");
                break;

        case 5:
                printf("|------|\n");
                printf("|      O\n");
                printf("|     /|\\\n");
                printf("|      |\n");
                printf("|     / \n");
                printf("|\n");
                printf("|__");
                break;

    }

}


