#ifndef SDNF_SKNF_H
#define SDNF_SKNF_H

// Проверка, что длина вектора - степень двойки
int is_correct_len(int n);

// Основная функция для построения СДНФ и СКНФ
int SDNF_SKNF(const char *vector);

// Функция для запуска тестов
void run_tests(void);

#endif