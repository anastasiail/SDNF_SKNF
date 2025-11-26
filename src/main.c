#include <stdio.h>
#include "sdnf_sknf.h"

int main() {
    
    printf("XOR функция (0110):\n");
    SDNF_SKNF("0110");
    printf("\n");

    printf("Конъюнкция (0001):\n");
    SDNF_SKNF("0001");
    printf("\n");

    printf("3 переменные: (00001111):\n");
    SDNF_SKNF("00001111");
    printf("\n");

    return 0;
}
