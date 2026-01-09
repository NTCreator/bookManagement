#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Maximum limits */
#define MAX_BOOKS           100
#define MAX_USERS           50
#define MAX_BORROWED_BOOKS  5
#define MAX_TITLE_LENGTH    100
#define MAX_AUTHOR_LENGTH   50
#define MAX_NAME_LENGTH     50

/* Book structure */
typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    bool isBorrowed;
} Book;

/* User structure */
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int borrowedBookIds[MAX_BORROWED_BOOKS];
    int borrowedCount;
} User;

/* Book Management Functions */
void addBook(void);
void editBook(void);
void deleteBook(void);
void displayBooks(void);

/* User Management Functions */
void addUser(void);
void editUser(void);
void deleteUser(void);
void displayUsers(void);

/* Borrow/Return Functions */
void borrowBook(void);
void returnBook(void);

/* Utility Functions */
int findBookById(int bookId);
int findUserById(int userId);
void clearInputBuffer(void);

#endif /* LIBRARY_H */
