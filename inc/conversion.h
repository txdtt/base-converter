#ifndef CONVERSION_H
#define CONVERSION_H

#ifdef _WIN32
    #define CLR_SCREEN system("cls");
#else
    #define CLR_SCREEN system("clear");
#endif

#define BUFFER_SIZE            1000
#define RETRY_INPUT_SIZE       2

// Verifica se o programa deve reiniciar
int* restart(int *retry);

void getOption(int *n);

int getBin(int *n);

int binToDec(int n);

int binToOctal(int n);

int binToHex(int n);

int getOctal(int *n);

int octalToDec(int n);

int octalToBin(int n);

int octalToHex(int n);

int getHex(int *n);

int hexToDec(int n);

int hexToBin(int n);

int hexToOctal(int n);

int getDec(int *n);

int decToBin(int n);

int decToOctal(int n);

int decToHex(int n);

#endif