#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/search.h"


#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define USERS_DB_FILE "../data bases/users"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
} User;

User users[MAX_USERS];
int numUsers = 0;

void loadUsers() {
    FILE *file = fopen(USERS_DB_FILE, "r");
    if (file == NULL) {
        printf("Error opening user database file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", users[numUsers].name, users[numUsers].surname) == 2) {
        numUsers++;
    }

    fclose(file);
}

void saveUser(char *name, char *surname) {
    FILE *file = fopen(USERS_DB_FILE, "a");
    if (file == NULL) {
        printf("Error opening user database file.\n");
        exit(1);
    }

    fprintf(file, "%s %s\n", name, surname);
    fclose(file);
}

bool validateUser(char *name, char *surname) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].name, name) == 0 && strcmp(users[i].surname, surname) == 0) {
            return true;
        }
    }
    return false;
}

int validateName(char *name) {
    if (!isupper(name[0]))
        return 0;

    for (int i = 1; i < strlen(name); i++) {
        if (!islower(name[i]))
            return 0;
    }
    return 1;
}

int validateLogin(char *input) {
    if (strcmp(input, "login") == 0)
        return 1;

    if (strcmp(input, "signup") == 0)
        return 2;

    return 0;
}

void getLoginCommand(char *buffer, short *x, char *name, char *surname) {
    char command[20];
    char input[80];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s %s %s", command, name, surname);

    *x = validateLogin(command);
    if (!*x) {
        printf("Input invalid\n");
        strcpy(buffer, "error");
        return;
    }

    if (!validateName(name) || !validateName(surname)) {
        printf("Input invalid\n");
        strcpy(buffer, "error");
        return;
    }
}

void getCommand(char *buffer) {
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strcmp(buffer, "search") == 0)
        return;

    if (strcmp(buffer, "exit") == 0)
        return;


}

void getInput(char *buffer) {
    fgets(buffer, 100, stdin);
}
