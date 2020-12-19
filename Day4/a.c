#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char *filename = "Passports.txt";
    FILE *f = fopen(filename, "r");
    size_t count = 0;

    char cur;
    bool *info = calloc(sizeof(bool), 8);
    char *curinfo = xcalloc(sizeof(char), 4);

    for (cur = fgetc(f); cur != EOF; cur = fgetc(f)) {
        
    }

    printf("Answer: %zu\n", count);
    return 0;
}