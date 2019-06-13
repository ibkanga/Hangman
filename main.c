#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "crtaj.h"

#define SIZE 30

int main()
{

    int igra;
    int hangman, i;
    hangman = i = 0;

    printf("DOBRODOSLI! \n\n");

    int tezinaIgre;
    do {
        printf("Unesite tezinu igre ('1' / '2' / '3') : ");
        scanf("%d", &tezinaIgre);
        getchar();
    } while (tezinaIgre < 1 || tezinaIgre > 3);

    printf("\n");

    char rijec[SIZE], crte[SIZE];

    FILE *fp;
    fp = fopen("hangman.txt", "r");
    fgets(rijec, SIZE, fp);
    fclose(fp);

    while(rijec[i]) {
        rijec[i] = toupper(rijec[i]);
        if(isalpha(rijec[i]))
            crte[i] = '_';
        else
            crte[i] = ' ';
        i++;
   }

    int duzinaRijeci = strlen (rijec);

    do {
        crtaj(hangman);

        printf("    ");
        for(i = 0; i < duzinaRijeci; i++)
            printf("%c", crte[i]);
        printf("\n\n");

        char korisnikString[SIZE], slovo;
        do {
            printf("Unesite slovo: ");
            fgets(korisnikString, SIZE, stdin);
            slovo = korisnikString[0];
            slovo = toupper(slovo);
            printf("\n");

        } while (!isalpha(slovo) || strlen(korisnikString) > 2);

        int brojacPolja = 0;
        for(i = 0; i < duzinaRijeci; i++) {
            if(rijec[i] == slovo)
                crte[i] = slovo;
            else
                brojacPolja++;
        }

        if (brojacPolja == duzinaRijeci) {
            if(tezinaIgre == 1) {
                hangman++;
            }
            else if (tezinaIgre == 2) {
                hangman = hangman+2;
            }
            else if(tezinaIgre == 3) {
                hangman = hangman + 3;
            }
            printf("Nema slova '%c'\n\n", slovo);
        }

        int brojacCrta = 0;
        for(i = 0; i < duzinaRijeci; i++) {
            if(crte[i] == '_')
                brojacCrta++;
        }

        igra = brojacCrta;

    } while (igra > 0 && hangman < 6);

    if(hangman == 6) {
        printf("|------|\n");
        printf("|      O\n");
        printf("|     /|\\\n");
        printf("|      |\n");
        printf("|     / \\\n");
        printf("|\n");
        printf("|__");

        printf("    IZGUBILI STE!\n");
        printf("\nTRAZENA RIJEC/FRAZA/RECENICA:    %s", rijec);

    }
    else {
        printf("\nCESTITAMO!\n\nPOGODILI STE RIJEC/FRAZU/RECENICU:   %s", rijec);
    }

    return 0;
}

