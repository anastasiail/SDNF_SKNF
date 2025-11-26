#include <stdio.h>
#include "sdnf_sknf.h"

void run_tests() {
    int res;
    
    res = SDNF_SKNF(NULL);
    if (res != 1) printf("Нулевой указатель не вернул ошибку\n");
    else printf("Нулевой указатель вернул ошибку (верно)\n\n");

    res = SDNF_SKNF("");
    if (res != 1) printf("Пустая строка не вернула ошибку\n");
    else printf("Пустая строка вернула ошибку (верно)\n\n");

    res = SDNF_SKNF("001");
    if (res != 1) printf("Неверная длина не вернула ошибку\n");
    else printf("Неверная длина вернула ошибку (верно)\n\n");

    res = SDNF_SKNF("01a1");
    if (res != 1) printf("Недопустимые символы не вернули ошибку\n");
    else printf("Недопустимые символы вернули ошибку (верно)\n\n");

    printf("Нулевой вектор:\n");
    res = SDNF_SKNF("0000");
    if (res != 0) printf("Функция 0 не обработана успешно\n");
    else printf("Функция 0 обработана успешно\n\n");

    printf("Единичный вектор:\n");
    res = SDNF_SKNF("11");
    if (res != 0) printf("Функция 1 не обработана успешно\n");
    else printf("Функция 1 обработана успешно\n\n");
    
    printf("XOR функция (0110):\n");
    SDNF_SKNF("0110");
    printf("\n");

    printf("Конъюнкция (0001):\n");
    SDNF_SKNF("0001");
    printf("\n");

    printf("Импликация (1011):\n");
    SDNF_SKNF("1011");
    printf("\n");

    printf("Штрих Шеффера (1110):\n");
    SDNF_SKNF("1110");
    printf("\n");

    printf("3 переменные: (00001111):\n");
    SDNF_SKNF("00001111");
    printf("\n");

    printf("Большой вектор: (0101010101010101):\n");
    SDNF_SKNF("0101010101010101");
    printf("\n");
}

int main() {
    run_tests();
    return 0;
}
