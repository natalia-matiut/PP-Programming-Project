#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256


void trim(char *str) {
    char *end;


    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {
        return;
    }

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }


    *(end + 1) = '\0';
}

void searching(const char *filename, const char *search_query) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    char search_query_lower[MAX_LINE_LENGTH];
    strcpy(search_query_lower, search_query);
    for (int i = 0; search_query_lower[i]; i++) {
        search_query_lower[i] = tolower(search_query_lower[i]);
    }
    trim(search_query_lower);

    while (fgets(line, sizeof(line), file) != NULL) {
        // Convert line to lowercase
        char line_lower[MAX_LINE_LENGTH];
        strcpy(line_lower, line);
        for (int i = 0; line_lower[i]; i++) {
            line_lower[i] = tolower(line_lower[i]);
        }
        trim(line_lower);


        if (strstr(line_lower, search_query_lower) != NULL) {
            printf("%s\n", line);
            found = 1;
        }
    }

    if (!found) {
        printf("We do not have that book.\n");
    }

    fclose(file);
}
