#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../inc/conversion.h"

void getOption(int *n) {
    char menuOption;

    CLR_SCREEN;

    do {
        printf("Selecione uma base para ser convertida\n");
        printf("\n1 - Binario\n2 - Octal\n3 - Decimal\n4 - Hexadecimal\n");
        menuOption = getchar();
        switch (menuOption) {
        case '1':
            while ((menuOption = getchar()) != '\n');
            getBin(n);
            binToDec(*n);
            binToOctal(*n);
            binToHex(*n);
            break;
        case '2':
            while ((menuOption = getchar()) != '\n');
            getOctal(n);
            octalToDec(*n);
            octalToBin(*n);
            octalToHex(*n);
            break;

        case '3':
            while ((menuOption = getchar()) != '\n');
            getDec(n);
            decToBinary(*n);
            decToOctal(*n);
            decToHex(*n);
            break;

        case '4':
            while ((menuOption = getchar()) != '\n');
            getHex(n);
            hexToBin(*n);
            hexToDec(*n);
            hexToOctal(*n);
            break;
            
        default:
            while ((menuOption = getchar()) != '\n');
            printf("\nEntrada invalida! Tente novamente\n");
            break;
        }

     } while (menuOption < '1' && menuOption > '4');
}

int getBin(int *n) {
    CLR_SCREEN;

    UINT_MAX;

    int i, integer_chars, length;
    char input_buffer[BUFFER_SIZE], integer_buffer[BUFFER_SIZE];
    bool loopAgain = false;

    do {
        fflush(stdin);
        integer_chars = 0;
        *n = 0;
        length = 0;
        i = 0;

        printf("Digite o valor a ser convertido\n");

        if (strlen(fgets(input_buffer, BUFFER_SIZE, stdin)) <= BUFFER_SIZE) {
            length = strlen(input_buffer);
        } else {
            printf("Entrada fora do intervalo! Tente novamente\n");
            getchar();
            loopAgain = true;
            fflush(stdin);
            CLR_SCREEN;
            continue;
        }

        while (isspace(input_buffer[i])) i++;

        if (length == i) {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (input_buffer[i] == '-') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (input_buffer[i] > '1' || input_buffer[i + 1] > '1') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        while (i < length && !isspace(input_buffer[i])) {
            if (!isdigit(input_buffer[i])) {
                printf("Entrada invalida! Tente novamente\n");
                getchar();
                CLR_SCREEN;
                loopAgain = true;
                break;
            }

            loopAgain = false;
            integer_buffer[integer_chars] = input_buffer[i];
            integer_chars++;
            i++;
        }

        if (loopAgain) continue;

        integer_buffer[integer_chars] = '\0';

        while(isspace(input_buffer[i])) i++;

        if (input_buffer[i] != '\0') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (atoi(integer_buffer) > UINT_MAX || atoi(integer_buffer) < 1) {
            printf("Entrada fora do intervalo! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        } else {
            *n = atoi(integer_buffer);
            loopAgain = false;
            break;
        }

    } while (loopAgain);

    CLR_SCREEN;

    return *n;
}

int binToDec(int n) {
    char binValue[255];
    int i, valueConversion = 0;

    sprintf(binValue, "%d", n);

    for (i = strlen(binValue) - 1; i >= 0; i--) {
        if (binValue[i] == '1') {
            valueConversion += pow(2, strlen(binValue) - 1 - i);
        }
    }

    printf("DECIMAL\n");
    printf("%d", valueConversion);

    printf("\n\n");

    return 0;
}

int binToOctal(int n) {
    // Bin to Decimal
    char binValue[255];
    int i, valueConversion = 0;

    sprintf(binValue, "%d", n);

    for (i = strlen(binValue) - 1; i >= 0; i--) {
        if (binValue[i] == '1') {
            valueConversion += pow(2, strlen(binValue) - 1 - i);
        }
    }

    // Decimal to Octal
    int octalValue[255], j = 0;
    i = 0;

    do {
        octalValue[i] =  valueConversion % 8;

        valueConversion /= 8;
        j++;
        i++;

        if ((valueConversion / 8) == 0) {
            octalValue[i] = valueConversion % 8;
            j++;
            break;
        }

    } while ((n / 8) != 0);

    printf("OCTAL\n");
    for (i = j - 1; i >= 0; i--) {
        printf("%d", octalValue[i]);
    }

    printf("\n\n");

    return 0;
}

int binToHex(int n) {
    char binValue[255];
    int i, valueConversion = 0;

    sprintf(binValue, "%d", n);

    for (i = strlen(binValue) - 1; i >= 0; i--) {
        if (binValue[i] == '1') {
            valueConversion += pow(2, strlen(binValue) - 1 - i);
        }
    }

    int hexValue[255], j = 0;
    i = 0;

    do {
        hexValue[i] =  valueConversion % 16;

        valueConversion /= 16;
        j++;
        i++;

        if ((valueConversion / 16) == 0) {
            hexValue[i] = valueConversion % 16;
            j++;
            break;
        }

    } while ((valueConversion / 16) != 0);

    printf("HEXADECIMAL\n");
    for (i = j - 1; i >= 0; i--) {
        if (hexValue[i] < 10) {
            printf("%d", hexValue[i]);
        } else {
            printf("%c",'A' + hexValue[i] - 10);
        }
    }

    printf("\n\n");

    return 0;
}

int getOctal(int *n) {
    CLR_SCREEN;

    UINT_MAX;

    int i, integer_chars, length;
    char input_buffer[BUFFER_SIZE], integer_buffer[BUFFER_SIZE];
    bool loopAgain = false;

    do {
        fflush(stdin);
        integer_chars = 0;
        *n = 0;
        length = 0;
        i = 0;

        printf("Digite o valor a ser convertido\n");

        if (strlen(fgets(input_buffer, BUFFER_SIZE, stdin)) <= BUFFER_SIZE) {
            length = strlen(input_buffer);
        } else {
            printf("Entrada fora do intervalo! Tente novamente\n");
            getchar();
            loopAgain = true;
            fflush(stdin);
            CLR_SCREEN;
            continue;
        }

        while (isspace(input_buffer[i])) i++;

        if (length == i) {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (input_buffer[i] > '7' || input_buffer[i + 1] > '7') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (input_buffer[i] == '-') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        while (i < length && !isspace(input_buffer[i])) {
            if (!isdigit(input_buffer[i])) {
                printf("Entrada invalida! Tente novamente\n");
                getchar();
                CLR_SCREEN;
                loopAgain = true;
                break;
            }

            loopAgain = false;
            integer_buffer[integer_chars] = input_buffer[i];
            integer_chars++;
            i++;
        }

        if (loopAgain) continue;

        integer_buffer[integer_chars] = '\0';

        while(isspace(input_buffer[i])) i++;

        if (input_buffer[i] != '\0') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (atoi(integer_buffer) > UINT_MAX || atoi(integer_buffer) < 1) {
            printf("Entrada fora do intervalo! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        } else {
            *n = atoi(integer_buffer);
            loopAgain = false;
            break;
        }

    } while (loopAgain);

    CLR_SCREEN;

    return *n;
}

int octalToDec(int n) {
    char octalValue[255];
    int i, valueConversion = 0, digit = 0;

    sprintf(octalValue, "%d", n);

    for (i = strlen(octalValue); i >= 0; i--) {
        if (octalValue[i] >= '0' && octalValue[i] <= '7') {
            digit = octalValue[i] - '0';
            valueConversion += digit * pow(8, strlen(octalValue) - 1 - i);
        }
    }

    printf("DECIMAL\n");
    printf("%d", valueConversion);

    printf("\n\n");

    return 0;
}

int octalToBin(int n) {
    char octalValue[255];
    int i, valueConversion = 0, digit = 0;

    sprintf(octalValue, "%d", n);

    for (i = strlen(octalValue); i >= 0; i--) {
        if (octalValue[i] >= '0' && octalValue[i] <= '7') {
            digit = octalValue[i] - '0';
            valueConversion += digit * pow(8, strlen(octalValue) - 1 - i);
        }
    }

    int binaryValue[255], j = 0;
    i = 0;

    do {
        binaryValue[i] =  valueConversion % 2;

        valueConversion /= 2;
        j++;
        i++;

        if ((valueConversion / 2) == 0) {
            binaryValue[i] = valueConversion % 2;
            j++;
            break;
        }

    } while ((valueConversion / 2) != 0);

    printf("BINARIO\n");
    for (i = j - 1; i >= 0; i--) {
        printf("%d", binaryValue[i]);
    }

    printf("\n\n");

    return 0;

}

int octalToHex(int n) {
    char octalValue[255];
    int i, valueConversion = 0, digit = 0;

    sprintf(octalValue, "%d", n);

    for (i = strlen(octalValue); i >= 0; i--) {
        if (octalValue[i] >= '0' && octalValue[i] <= '7') {
            digit = octalValue[i] - '0';
            valueConversion += digit * pow(8, strlen(octalValue) - 1 - i);
        }
    }

    int hexValue[255], j = 0;
    i = 0;

    do {
        hexValue[i] =  valueConversion % 16;

        valueConversion /= 16;
        j++;
        i++;

        if ((valueConversion / 16) == 0) {
            hexValue[i] = valueConversion % 16;
            j++;
            break;
        }

    } while ((valueConversion / 16) != 0);

    printf("HEXADECIMAL\n");
    for (i = j - 1; i >= 0; i--) {
        if (hexValue[i] < 10) {
            printf("%d", hexValue[i]);
        } else {
            printf("%c",'A' + hexValue[i] - 10);
        }
    }

    printf("\n\n");

    return 0;

}

int getDec(int *n) {
    CLR_SCREEN;

    UINT_MAX;

    int i, integer_chars, length;
    char input_buffer[BUFFER_SIZE], integer_buffer[BUFFER_SIZE];
    bool loopAgain = false;

    do {
        fflush(stdin);
        integer_chars = 0;
        *n = 0;
        length = 0;
        i = 0;

        printf("Digite o valor a ser convertido\n");

        if (strlen(fgets(input_buffer, BUFFER_SIZE, stdin)) <= BUFFER_SIZE) {
            length = strlen(input_buffer);
        } else {
            printf("Entrada fora do intervalo! Tente novamente\n");
            getchar();
            loopAgain = true;
            fflush(stdin);
            CLR_SCREEN;
            continue;
        }

        while (isspace(input_buffer[i])) i++;

        if (length == i) {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (input_buffer[i] == '-') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        while (i < length && !isspace(input_buffer[i])) {
            if (!isdigit(input_buffer[i])) {
                printf("Entrada invalida! Tente novamente\n");
                getchar();
                CLR_SCREEN;
                loopAgain = true;
                break;
            }

            loopAgain = false;
            integer_buffer[integer_chars] = input_buffer[i];
            integer_chars++;
            i++;
        }

        if (loopAgain) continue;

        integer_buffer[integer_chars] = '\0';

        while(isspace(input_buffer[i])) i++;

        if (input_buffer[i] != '\0') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (atoi(integer_buffer) > UINT_MAX || atoi(integer_buffer) < 1) {
            printf("Entrada fora do intervalo! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        } else {
            *n = atoi(integer_buffer);
            loopAgain = false;
            break;
        }

    } while (loopAgain);

    CLR_SCREEN;

    return *n;
}

int decToBinary(int n) {
    int binaryValue[255], i = 0, j = 0;

    do {
        binaryValue[i] =  n % 2;

        n /= 2;
        j++;
        i++;

        if ((n / 2) == 0) {
            binaryValue[i] = n % 2;
            j++;
            break;
        }

    } while ((n / 2) != 0);

    printf("BINARIO\n");
    for (i = j - 1; i >= 0; i--) {
        printf("%d", binaryValue[i]);
    }

    printf("\n\n");

    return 0;
}

int decToOctal(int n) {
    int octalValue[255], i = 0, j = 0;

    do {
        octalValue[i] =  n % 8;

        n /= 8;
        j++;
        i++;

        if ((n / 8) == 0) {
            octalValue[i] = n % 8;
            j++;
            break;
        }

    } while ((n / 8) != 0);

    printf("OCTAL\n");
    for (i = j - 1; i >= 0; i--) {
        printf("%d", octalValue[i]);
    }

    printf("\n\n");

    return 0;
}

int decToHex(int n) {
    int hexValue[255], i = 0, j = 0;

    do {
        hexValue[i] =  n % 16;

        n /= 16;
        j++;
        i++;

        if ((n / 16) == 0) {
            hexValue[i] = n % 16;
            j++;
            break;
        }

    } while ((n / 16) != 0);

    printf("HEXADECIMAL\n");
    for (i = j - 1; i >= 0; i--) {
        if (hexValue[i] < 10) {
            printf("%d", hexValue[i]);
        } else {
            printf("%c",'A' + hexValue[i] - 10);
        }
    }

    printf("\n\n");

    return 0;
}

int getHex(int *n) {
    CLR_SCREEN;

    UINT_MAX;

    int i, integer_chars, length;
    char input_buffer[BUFFER_SIZE], integer_buffer[BUFFER_SIZE];
    bool loopAgain = false;

    do {
        fflush(stdin);
        integer_chars = 0;
        *n = 0;
        length = 0;
        i = 0;

        printf("Digite o valor a ser convertido\n");

        if (strlen(fgets(input_buffer, BUFFER_SIZE, stdin)) <= BUFFER_SIZE) {
            length = strlen(input_buffer);
        } else {
            printf("1 Entrada fora do intervalo! Tente novamente\n");
            getchar();
            loopAgain = true;
            fflush(stdin);
            CLR_SCREEN;
            continue;
        }

        while (isspace(input_buffer[i])) i++;

        if (length == i) {
            printf("2 Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (input_buffer[i] == '-') {
            printf("3 Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        while (i < length && !isspace(input_buffer[i])) {
            /*if (!isdigit(input_buffer[i])) {
                printf("Entrada invalida! Tente novamente\n");
                getchar();
                CLR_SCREEN;
                loopAgain = true;
                break;
            }*/

            loopAgain = false;
            integer_buffer[integer_chars] = input_buffer[i];
            integer_chars++;
            i++;
        }

        if (loopAgain) continue;

        integer_buffer[integer_chars] = '\0';

        while(isspace(input_buffer[i])) i++;

        if (input_buffer[i] != '\0') {
            printf("4 Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        for (i = 0; i < strlen(integer_buffer); i++) {
            if (isdigit(integer_buffer[i])) {
                *n = *n * 16 + (integer_buffer[i] - '0');
            } else if (integer_buffer[i] <= 'F'){
                char hexChar = tolower(integer_buffer[i]);
                *n = *n * 16 + (hexChar - 'a' + 10);
            } else {
                printf("4 Entrada invalida! Tente novamente\n");
                getchar();
                CLR_SCREEN;
                loopAgain = true;
                continue;
            }
        }

    } while (loopAgain);

    CLR_SCREEN;

    return *n;
}

int hexToDec(int n) {
    int valueConversion = n;

    printf("DECIMAL\n");
    printf("%d", valueConversion);

    printf("\n\n");

    return 0;
}

int hexToBin(int n) {
    int i, valueConversion = n;

    int binaryValue[255], j = 0;
    i = 0;

    do {
        binaryValue[i] =  valueConversion % 2;

        valueConversion /= 2;
        j++;
        i++;

        if ((valueConversion / 2) == 0) {
            binaryValue[i] = valueConversion % 2;
            j++;
            break;
        }

    } while ((valueConversion / 2) != 0);

    printf("BINARIO\n");
    for (i = j - 1; i >= 0; i--) {
        printf("%d", binaryValue[i]);
    }

    printf("\n\n");

    return 0;

}

int hexToOctal(int n) {
    int i, valueConversion = n;

    int octalValue[255], j = 0;
    i = 0;

    do {
        octalValue[i] =  valueConversion % 8;

        valueConversion /= 8;
        j++;
        i++;

        if ((valueConversion / 8) == 0) {
            octalValue[i] = valueConversion % 8;
            j++;
            break;
        }

    } while ((valueConversion / 8) != 0);

    printf("OCTAL\n");
    for (i = j - 1; i >= 0; i--) {
        printf("%d", octalValue[i]);
    }

    printf("\n\n");

    return 0;

}

int* restart(int *retry) {
    int ch;

    bool loopAgain = false;

    do {
        printf("Testar para novos valores (1 - SIM; 0 - NAO)?\n");
        *retry = fgetc(stdin);
        if (*retry != '1' && *retry != '0') {
            printf("Entrada invalida! Tente novamente\n");
            while ((ch = getchar()) != '\n');
            loopAgain = true;
            continue;
        } else {
            break; 
        }
    } while (loopAgain);

    while ((ch = getchar()) != '\n');

    return retry;
}