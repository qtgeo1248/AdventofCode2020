#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_pass(bool* info) {
    for (int i = 0; i < 7; i++)
        if (!info[i]) return false;
    return true;
}

int main() {
    char *filename = "Passports.txt";
    FILE *f = fopen(filename, "r");
    size_t count = 0;

    char cur = '\0';
    bool *info = calloc(sizeof(bool), 7);
    char *curs = calloc(sizeof(char), 3);

    for (cur = fgetc(f); cur != EOF; cur = fgetc(f)) {
        if (cur == ':')
            switch (curs[0] + curs[1] + curs[2]) {
                case 'M': // byr
                    printf("byr");
                    info[0] = true; break;
                case 'T': // iyr
                    printf("iyr");
                    info[1] = true; break;
                case 'P': // eyr
                    printf("eyr");
                    info[2] = true; break;
                case 'C': // hgt
                    printf("hgt");
                    info[3] = true; break;
                case '7': // hcl
                    printf("hcl");
                    info[4] = true; break;
                case '4': // ecl
                    printf("ecl");
                    info[5] = true; break;
                case '=': // pid
                    printf("pid");
                    info[6] = true; break;
            }
        if (cur == '\n' && curs[2] == '\n') {
            if (is_pass(info)) count++;
            free(info);
            info = calloc(sizeof(bool), 7);
        }
        curs[0] = curs[1];
        curs[1] = curs[2];
        curs[2] = cur;
    }

    printf("Answer: %zu\n", count);

    free(info);
    free(curs);
    fclose(f);
    return 0;
}