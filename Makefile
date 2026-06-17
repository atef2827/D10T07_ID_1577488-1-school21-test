CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC = src
BUILD = build

.PHONY: all clean door_struct list_test stack_test print_module \
        documentation_module bst_create_test bst_insert_test bst_traverse_test

all: door_struct list_test stack_test print_module documentation_module \
     bst_create_test bst_insert_test bst_traverse_test

$(BUILD):
	mkdir -p $(BUILD)

# Quest 1
door_struct: $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/dmanager_module.c -o $(BUILD)/Quest_1

# Quest 2
list_test: $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/list.c $(SRC)/list_test.c -o $(BUILD)/Quest_2

# Quest 3
stack_test: $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/stack.c $(SRC)/stack_test.c -o $(BUILD)/Quest_3

# Quest 4
print_module: $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/main_module_entry_point.c $(SRC)/print_module.c \
		$(SRC)/documentation_module.c -o $(BUILD)/Quest_4

# Quest 5
documentation_module: $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/main_module_entry_point.c $(SRC)/print_module.c \
		$(SRC)/documentation_module.c -o $(BUILD)/Quest_5

# Bonus Quest 6
bst_create_test: $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/bst.c $(SRC)/bst_create_test.c -o $(BUILD)/Quest_6

# Bonus Quest 7
bst_insert_test: $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/bst.c $(SRC)/bst_insert_test.c -o $(BUILD)/Quest_7

# Bonus Quest 8
bst_traverse_test: $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/bst.c $(SRC)/bst_traverse_test.c -o $(BUILD)/Quest_8

clean:
	rm -rf $(BUILD)
