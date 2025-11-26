#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sdnf_sknf.h"

// Проверка, что длина вектора - степень двойки
int is_correct_len(int n) {
    if (n <= 0) return 0;
    while (n > 1) {
        if (n % 2 != 0) return 0;
        n /= 2;
    }
    return 1;
}

int SDNF_SKNF(const char *vector) {
    if (vector == NULL) return 1;

    int len = strlen(vector);
    
    if (!is_correct_len(len)) {
        return 1;
    }

    // Проверяем, что в векторе только 0 и 1
    for (int i = 0; i < len; i++) {
        if (vector[i] != '0' && vector[i] != '1') {
            return 1;
        }
    }

    // Считаем количество переменных
    int num_vars = 0;
    int temp = len;
    while (temp > 1) {
        temp /= 2;
        num_vars++;
    }

    printf("SDNF: ");
    int printed_any = 0; // Флаг: нужно ли ставить | или &, или это первая скобка
    
    for (int i = 0; i < len; i++) {
        if (vector[i] == '1') { // Ищем 1 в векторе
            if (printed_any) {
                printf(" | ");
            }
            printf("(");
            
            // Делаем из индекса i набор переменных
            for (int v = 0; v < num_vars; v++) {

                int bit = (i >> (num_vars - 1 - v)) & 1; // Достаём v-ый бит
                
                if (v > 0) printf(" & ");
                
                if (bit == 1) {
                    printf("x%d", v + 1);
                } else {
                    printf("!x%d", v + 1);
                }
            }
            printf(")");
            printed_any = 1;
        }
    }
    // Если ни одной 1 не было, функция - константа 0
    if (!printed_any) printf("0");
    printf("\n");

    printf("SKNF: ");
    printed_any = 0;

    for (int i = 0; i < len; i++) {
        if (vector[i] == '0') { // Ищем 0 в векторе
            if (printed_any) {
                printf(" & ");
            }
            printf("(");

            for (int v = 0; v < num_vars; v++) {
                int bit = (i >> (num_vars - 1 - v)) & 1; // Достаём v-ый бит
                
                if (v > 0) printf(" | ");

                if (bit == 0) {
                    printf("x%d", v + 1);
                } else {
                    printf("!x%d", v + 1);
                }
            }
            printf(")");
            printed_any = 1;
        }
    }
    // Если ни одного 0 не было, функция - константа 1
    if (!printed_any) printf("1");
    printf("\n");

    return 0;
}