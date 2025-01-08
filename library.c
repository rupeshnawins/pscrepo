#include<stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to store book information
typedef struct {
    char name[100];
    char author[100];
    int pages;
    float price;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter Book Name: ");
    scanf(" %[^\n]s", library[bookCount].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]s", library[bookCount].author);

    printf("Enter Pages: ");
    scanf("%d", &library[bookCount].pages);

    printf("Enter Price: ");
    scanf("%f", &library[bookCount].price);

    bookCount++;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nBooks in the library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Name: %s\n", library[i].name);
        printf("  Author: %s\n", library[i].author);
        printf("  Pages: %d\n", library[i].pages);
        printf("  Price: %.2f\n\n", library[i].price);
    }
}

// Function to list books by a given author
void listBooksByAuthor() {
    char authorName[100];
    int found = 0;

    printf("Enter Author Name: ");
    scanf(" %[^\n]s", authorName);

    printf("\nBooks by %s:\n", authorName);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].author, authorName) == 0) {
            printf("  Name: %s\n", library[i].name);
            printf("  Pages: %d\n", library[i].pages);
            printf("  Price: %.2f\n\n", library[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found by %s.\n", authorName);
    }
}

// Function to count all books in the library
void countBooks() {
    printf("Total number of books in the library: %d\n", bookCount);
}

int main() {
    int choice;

    do{
        printf("\nE-Library Management System\n");
        printf("1. Add Book Information\n");
        printf("2. Display All Books\n");
        printf("3. List Books by Author\n");
        printf("4. Count Total Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                listBooksByAuthor();
                break;
            case 4:
                countBooks();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice!=5&&choice<=5);
    

    return 0;
}
