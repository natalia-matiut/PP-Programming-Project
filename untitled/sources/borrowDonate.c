#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define BOOKS_DB_FILE "../data bases/books"

typedef struct {
    char title[MAX_TITLE_LENGTH];
} Book;

Book books[MAX_BOOKS];
int numBooks = 0;

void loadBooks() {
    FILE *file = fopen(BOOKS_DB_FILE, "r");
    if (file == NULL) {
        printf("Error opening books database file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", books[numBooks].title) == 1) {
        numBooks++;
    }

    fclose(file);
}

void saveBooks() {
    FILE *file = fopen(BOOKS_DB_FILE, "a");
    if (file == NULL) {
        printf("Error opening books database file.\n");
        exit(1);
    }

    for (int i = 0; i < numBooks; i++) {
        fprintf(file, "%s\n", books[i].title);
    }

    fclose(file);
}

void donateBook(char *title) {
    if (numBooks >= MAX_BOOKS) {
        printf("Cannot donate more books. Database is full.\n");
        return;
    }

    strcpy(books[numBooks].title, title);
    numBooks++;
    saveBooks();
    printf("Book \"%s\" donated successfully!\n", title);
}

void borrowBook(char *title) {
    int index = -1;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book \"%s\" not found in the database.\n", title);
        return;
    }

    for (int i = index; i < numBooks - 1; i++) {
        strcpy(books[i].title, books[i + 1].title);
    }
    numBooks--;
    saveBooks();
    printf("Book \"%s\" borrowed successfully!\n", title);
}
