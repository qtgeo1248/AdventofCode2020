#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    char *filename = "Passwords.txt";
    FILE *f = fopen(filename, "r");
    char *line = NULL;
    size_t n = 0;
    size_t valids = 0;
    while (getline(&line, &n, f) != -1) {
        char *str = strchr(line, ':');
        char *pass = calloc(sizeof(char), strlen(str) - 2);
        strcpy(pass, &str[2]);
        int low = strtol(line, &line, 10);
        line++;
        int high = strtol(line, &line, 10);
        char ch = line[1];
        
        size_t count = 0;
        for (int i = 0; i < strlen(pass); i++)
            if (pass[i] == ch) count++;
        if (low <= count && count <= high)
            valids++;
        
        free(pass);
    }

    printf("Answer: %zu\n", valids);
    fclose(f);

    return 0;
}