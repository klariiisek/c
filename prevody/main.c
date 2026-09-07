#include <stdio.h>
#include  <string.h>
#include  <math.h>
#define SIZE 10

void nahradEnter(char *vstup) {
    for (int i = 0; i < strlen(vstup); i++) {
        if (vstup[i] == '\n') {
            vstup[i] = '\0';
        }
    }
}

int zkontroluj(char *vstup) {
    for (int i = 0; i < strlen(vstup); i++) {
        if (vstup[i] != '0' && vstup[i] != '1') {
            vstup[i] = '\0';
            return 0;
        }
    }
    return 1;
}

int prevod(char *vstup) {
    int desitkova = 0;
    for (int i = 0; i < strlen(vstup); i++) {
        desitkova += (vstup[i] - '0') * pow(2, strlen(vstup) - i - 1);
    }
    return desitkova;
}

void reverse(char *vystup) {
    char pomocna;
    for (int i = 0; i < strlen(vystup)/2; i++) {
        pomocna = vystup[i];
        vystup[i] = vystup[strlen(vystup) - i-1];
        vystup[strlen(vystup) - i-1] = pomocna;
    }
}

void prevodZpet(char *vystup, unsigned int cislo) {
    int index = 0;
    while (cislo > 0) {
        vystup[index] = cislo % 2 + '0';
        index++;
        cislo /= 2;
    }
    vystup[index] = '\0';
}

int main(void) {
    unsigned int desitkova = 0;
    char vstup[SIZE + 1];
    char vystup[SIZE + 1];
    printf("Zadej cislo ve dvojkove soustave:\n");
    fgets(vstup, SIZE, stdin);
    nahradEnter(vstup);
    if (zkontroluj(vstup)) {
        desitkova = prevod(vstup);
        printf("Cislo po prevodu do desitkove soustavy:%u\n", desitkova);
        prevodZpet(vystup, desitkova);
        reverse(vystup);
        printf("Cislo po prevodu zpet do binarni soustavy:%s\n",vystup);
    } else {
        printf("Nebylo zadano cislo ve dvojkove soustave. Zadej znovu:\n");
    }
    return 0;
}
