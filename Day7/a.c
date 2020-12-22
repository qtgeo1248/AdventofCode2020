#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct node_header node;
struct node_header {
    char *color;
    node *prev;
    node *next;
};

int main() {
    char *filename = "Rules.txt";
    FILE *f = fopen(filename, "r");
    char *line = NULL; size_t len = 0;
    size_t count = 0;

    while (getline(&line, &len, f) != -1) {
        
    }
    printf("%zu\n", count);
    free(line);
    fclose(f);
    return 0;
}