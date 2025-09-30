#include <stdio.h>
#include <string.h>
#include "case_management.h"

// Global array
Case case_list[MAX_CASES];
int case_count = 0;

// Function to add a new case
void add_new_case() {
    if (case_count >= MAX_CASES) {
        printf("Case list is full!\n");
        return;
    }

    Case new_case;

    printf("Enter case title: ");
    getchar();
    fgets(new_case.title, MAX_TITLE, stdin);
    // remove newline
    new_case.title[strcspn(new_case.title, "\n")] = '\0';

    printf("Enter case description: ");
    fgets(new_case.description, MAX_DESC, stdin);
     // remove newline
    new_case.description[strcspn(new_case.description, "\n")] = '\0';

    printf("Enter priority level (1-High, 2-Medium, 3-Low): ");
    scanf("%d", &new_case.priority);

    // Store in global array
    case_list[case_count++] = new_case;

    printf("New case added successfully!\n");
}

// Optional: display all cases
void display_cases() {
    if (case_count == 0) {
        printf("No cases available.\n");
        return;
    }

    for (int i = 0; i < case_count; i++) {
        printf("\nCase #%d\n", i + 1);
        printf("Title: %s\n", case_list[i].title);
        printf("Description: %s\n", case_list[i].description);
        printf("Priority: %d\n", case_list[i].priority);
    }
}
