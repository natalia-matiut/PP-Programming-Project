#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/borrowDonate.h"
#include "headers/login.h"
#include "headers/search.h"
#include "headers/interface.h"

int main() {
    char buffer[100];
    char name[100];
    char surname[100];
    short x = 0;
    interface();

    //user database
    loadUsers();

    //login command
    getLoginCommand(buffer, &x, name, surname);

    if (!strcmp(buffer, "error")) {
        printf("Failed\n");
        return 1;
    }

    if (x == 1) {
        // Check if user before login
        if (!validateUser(name, surname)) {
            printf("User not found. Please sign up first.\n");
            return 1;
        }

        printf("You logged in successfully! Any other commands?\n");
    }
    else if (x == 2) {
        // Sign up
        saveUser(name, surname);
        printf("You signed up successfully! Any other commands?\n");
    }

    while (1) {
        getCommand(buffer);

        if (strcmp(buffer, "search") == 0) {
            printf("What book are you looking for? ...");
            getInput(buffer);
            searching("../data bases/books", buffer);
        }
        else if (strncmp(buffer, "donate", 6) == 0) {
            char title[100];
            sscanf(buffer + 7, "%[^\n]", title);
            donateBook(title);
        }
        else if (strncmp(buffer, "borrow", 6) == 0) {
            char title[100];
            sscanf(buffer + 7, "%[^\n]", title);
            borrowBook(title);
        }
        else if (strcmp(buffer, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
