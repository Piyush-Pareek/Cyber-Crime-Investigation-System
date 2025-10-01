#include <stdio.h>
#include <string.h>
#include "evidence_management.h"

// Global array to hold evidence items
Evidence evidence_list[MAX_EVIDENCE]; // Array to store evidence items
static int evidence_count = 0; // Current count of evidence items

void add_evidence() {
    if (evidence_count >= MAX_EVIDENCE) {
        printf("Cannot add more evidence, maximum limit reached.\n");
        return;
    }

    Evidence new_evidence;
    printf("\n--- Add New Evidence ---\n");
    printf("Enter Evidence ID: ");
    scanf("%d", &new_evidence.evidence_id);

    printf("Enter Associated Case ID: ");
    scanf("%d", &new_evidence.associated_case_id);

    printf("Enter Evidence Type: ");
    getchar();
    fgets(new_evidence.type, MAX_EVIDENCE_TYPE, stdin);// take input with spaces till max_evidence_type-1
    new_evidence.type[strcspn(new_evidence.type, "\n")] = '\0'; //STRCSPN - Remove newline after finding the position of the newline character

    printf("Enter Evidence Content/Details: ");
    fgets(new_evidence.content, MAX_EVIDENCE_CONTENT, stdin);
    new_evidence.content[strcspn(new_evidence.content, "\n")] = '\0'; // Remove newline

    // Store in our global list
    evidence_list[evidence_count] = new_evidence;
    evidence_count++;

    printf("Evidence #%d added successfully and linked to Case #%d!\n", new_evidence.evidence_id, new_evidence.associated_case_id);
}
void display_all_evidence() {
    if (evidence_count == 0) {
        printf("\nNo evidence has been recorded yet.\n");
        return;
    }

    printf("\n--- All Recorded Evidence ---\n");
    for (int i = 0; i < evidence_count; i++) {
        printf("Evidence ID: %d | Case ID: %d | Type: %s\n",
               evidence_list[i].evidence_id,
               evidence_list[i].associated_case_id,
               evidence_list[i].type);
        printf("   Content: %s\n\n", evidence_list[i].content);
    }
}