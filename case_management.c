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
    scanf(" %[^\n]", new_case.title);
    printf("Enter case description: ");
    scanf(" %[^\n]", new_case.description);
    printf("Enter priority (higher number -> higher priority): ");
    scanf("%d", &new_case.priority);
    getchar();
    new_case.case_id = case_count+1;
    // printf("Case id: %d", new_case.case_id);

    case_list[case_count] = new_case;
    case_count++;

    //calling heapify_up
    heapify_up(case_count - 1);

    printf("Case added successfully with priority %d!\n", new_case.priority);
    // printf("\nNew case added successfully!\n");
    printf("Title : %s", new_case.title);
    printf("\nCase id: %d\n", new_case.case_id);
    // printf("Description: %s", new_case.description);
}

/*
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
        printf("Case ID: %d\n", case_list[i].case_id);
    }
}
*/


void swap(Case *a, Case *b) {
    Case temp = *a;
    *a = *b;
    *b = temp;
}


void heapify_up(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2; //for Binary tree
    //time complexity : O(log n)
    if (case_list[index].priority > case_list[parent].priority) {
        swap(&case_list[index], &case_list[parent]);
        heapify_up(parent);
    }
}


void heapify_down(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < case_count && case_list[left].priority > case_list[largest].priority) {
        largest = left;
    }
    if (right < case_count && case_list[right].priority > case_list[largest].priority) {
        largest = right;
    }

    if (largest != index) {
        swap(&case_list[index], &case_list[largest]);
        heapify_down(largest);
    }
}


void process_highest_priority_case() {
    if (case_count == 0) {
        printf("No cases available to process.\n");
        return;
    }

    // highest priority is at root
    Case top_case = case_list[0];
    printf("Processing highest priority case:\n");
    printf("Title: %s\n", top_case.title);
    printf("Description: %s\n", top_case.description);
    printf("Priority: %d\n", top_case.priority);

    // move last element to root
    case_list[0] = case_list[case_count - 1];
    case_count--;

    // fix heap
    heapify_down(0);
}
