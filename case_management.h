#ifndef CASE_MANAGEMENT_H
#define CASE_MANAGEMENT_H

#define MAX_CASES 100
#define MAX_TITLE 50
#define MAX_DESC 200

// Case structure
typedef struct {
    char title[MAX_TITLE];
    char description[MAX_DESC];
    int priority;  // 1 = High, 2 = Medium, 3 = Low
} Case;

// Global array and counter
extern Case case_list[MAX_CASES];
extern int case_count;

// Function declarations
void add_new_case();
void display_cases(); // Optional helper to show all cases

#endif
