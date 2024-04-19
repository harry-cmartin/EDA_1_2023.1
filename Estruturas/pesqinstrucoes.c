#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    char value[30];
} Instruction;

#define Instruction Instruction
#define IS_LESS_THAN(a, b) a.key < b.key
#define SWAP(a, b) \
    Instruction temp = a; \
    a = b; \
    b = temp;

void sort(Instruction *instructions, int size) {
    for (int i = size - 1; i > 0; i--) {
        if (IS_LESS_THAN(instructions[i], instructions[0])) {
            SWAP(instructions[0], instructions[i]);
        }
    }
    for (int i = 2, j; i < size; i++) {
        Instruction temp = instructions[i];
        for (j = i; IS_LESS_THAN(temp, instructions[j - 1]); j--) {
            instructions[j] = instructions[j - 1];
        }
        instructions[j] = temp;
    }
}

char *find(Instruction *instructions, int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (instructions[middle].key == key) {
            return instructions[middle].value;
        }
        if (instructions[middle].key > key) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return "undefined";
}

int main() {
    int num_instructions;
    scanf(" %d", &num_instructions);
    Instruction *instructions = (Instruction *)malloc(num_instructions * sizeof(Instruction));

    for (int i = 0; i < num_instructions; i++) {
        scanf("%d %s", &instructions[i].key, instructions[i].value);
    }

    sort(instructions, num_instructions);

    for (int code; scanf(" %d", &code) == 1;) {
        printf("%s\n", find(instructions, num_instructions, code));
    }

    free(instructions);

    return 0;
}
