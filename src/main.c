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