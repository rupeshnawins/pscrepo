#include<stdio.h>
#include <string.h>

#define maxbooks 100



typedef struct {
    char name[100];
    char author[100];
    int pages;
    float price;
} Book;

Book library[maxbooks];
int bookcount = 0;

// function to add a book
void addbook() 
{
    if (bookcount >= maxbooks)
    {
        printf("Library is full cannot add books\n");
        return;
    }

    printf("Enter Book Name: ");
    scanf(" %[^\n]s", library[bookcount].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]s", library[bookcount].author);

    printf("Enter Pages: ");
    scanf("%d", &library[bookcount].pages);

    printf("Enter Price: ");
    scanf("%f", &library[bookcount].price);

    bookcount++;
    printf("Book added successfully!\n");
}

// function to display all books
void displaybooks() 
{
    if (bookcount == 0)
    {
        printf("No books in the library.\n");
        return;
    }

    printf("\nBooks in the library:\n");
    for (int i = 0; i < bookcount; i++) 
    {
        printf("Book %d:\n", i + 1);
        printf("  Name: %s\n", library[i].name);
        printf("  Author: %s\n", library[i].author);
        printf("  Pages: %d\n", library[i].pages);
        printf("  Price: %.2f\n\n", library[i].price);
    }
}

// function to list books by a given author
void listbooksbyauthor()
{
    char authorname[100];
    int found = 0;

    printf("Enter Author Name: ");
    scanf(" %[^\n]s", authorname);

    printf("\nBooks by %s:\n", authorname);
    for (int i = 0; i < bookcount; i++) 
    {
        if (strcmp(library[i].author, authorname) == 0) 
        {
            printf("  Name: %s\n", library[i].name);
            printf("  Pages: %d\n", library[i].pages);
            printf("  Price: %.2f\n\n", library[i].price);
            found = 1;
        }
    }

    if (found==0)
    {
        printf("No books found by %s.\n", authorname);
    }
}

// function to count all books in the library
void countbooks() 
{
    printf("Total  books in the library: %d\n", bookcount);
}

int main()
{
    int choice;

    do{
        printf("E library management system\n");
         printf("1. add book information\n");
         printf("2. display all books\n");
        printf("3. list books by Author\n");
        printf("4. count total books\n");
        printf("5. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addbook();
                break;
             case 2:
                displaybooks();
                break;
           case 3:
                listbooksbyauthor();
                 break;
            case 4:
                  countbooks();
                break;
            case 5:
                printf("exiting the system\n");
                break;
            default:
                printf("invalid choice\n");
        }
    }while(choice!=5&&choice<=5);
    

    return 0;
}
