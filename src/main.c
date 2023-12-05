// Windows 10 Versão 22H2 (Build 19045.3693)
// Compilado usando gcc 13.2.0 (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders)

#include <stdio.h>
#include<stdlib.h>

#include "../inc/conversion.h"

int main() {
    CLR_SCREEN;

    int retry, value = 0;

    do {

        getOption(&value);

        restart(&retry);

    } while (retry == '1');

    CLR_SCREEN;

    return 0;
}