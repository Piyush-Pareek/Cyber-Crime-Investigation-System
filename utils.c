#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clear screen
void clearScreen() {
    system("cls");   // windows
    // system("clear"); // for linux
}

// wait for enter
void pressEnter() {
    printf("\nPress Enter to continue...");
    getchar(); // waits for enter
}

// print header in center
void printHeader(char header[]) {
    int width = 80;
    int len = strlen(header);
    int spaces = (width - len) / 2;
    int i;
    for(i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("%s\n\n", header);
}

// menu display
void displayMenu() {
    char *menu[] = {"1. Add Record", "2. Delete Record", "3. Display Records", "4. Exit"};
    int i, width = 80;
    for(i = 0; i < 4; i++) {
        int len = strlen(menu[i]);
        int spaces = (width - len) / 2;
        int j;
        for(j = 0; j < spaces; j++) {
            printf(" ");
        }
        printf("%s\n", menu[i]);
    }
}

// dummy functions for options
void addRecord() {
    printf("\n--- Add Record ---\n");
    printf("Functionality not implemented yet.\n");
}

void deleteRecord() {
    printf("\n--- Delete Record ---\n");
    printf("Functionality not implemented yet.\n");
}

void displayRecords() {
    printf("\n--- Display Records ---\n");
    printf("Functionality not implemented yet.\n");
}

int main() {
    int choice;
    while(1) {
        clearScreen();
        printHeader("=== STUDENT MANAGEMENT SYSTEM ===");
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume enter

        switch(choice) {
            case 1:
                addRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        pressEnter(); // wait before showing menu again
    }
    return 0;
}