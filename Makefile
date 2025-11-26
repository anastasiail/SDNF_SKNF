# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
DEBUG_FLAGS = -g
RELEASE_FLAGS = -O2

# Директории
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
BUILD_DIR = build
BIN_DIR = bin

# Исходные файлы
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

# Исключаем main.c из объектных файлов для библиотеки
LIB_SRC_FILES = $(filter-out $(SRC_DIR)/main.c, $(SRC_FILES))

# Объектные файлы
LIB_OBJ = $(LIB_SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
MAIN_OBJ = $(BUILD_DIR)/main.o
TEST_OBJ = $(TEST_FILES:$(TEST_DIR)/%.c=$(BUILD_DIR)/%.o)

# Исполняемые файлы
MAIN_TARGET = $(BIN_DIR)/sdnf_sknf
TEST_TARGET = $(BIN_DIR)/test_sdnf_sknf

# Основная цель по умолчанию
all: release

# Релизная сборка
release: CFLAGS += $(RELEASE_FLAGS)
release: $(MAIN_TARGET)

# Отладочная сборка
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(MAIN_TARGET)

# Сборка основной программы
$(MAIN_TARGET): $(LIB_OBJ) $(MAIN_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Сборка тестов
$(TEST_TARGET): $(LIB_OBJ) $(TEST_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Компиляция объектных файлов из исходников
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Создание директорий
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Запуск тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Пересборка
rebuild: clean all

# Справка
help:
	@echo "Доступные цели:"
	@echo "  all       - сборка релизной версии (по умолчанию)"
	@echo "  release   - сборка релизной версии"
	@echo "  debug     - сборка отладочной версии"
	@echo "  test      - сборка и запуск тестов"
	@echo "  clean     - очистка собранных файлов"
	@echo "  rebuild   - полная пересборка"
	@echo "  help      - показать эту справку"

.PHONY: all release debug test clean rebuild help
