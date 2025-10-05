
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "evidence_management.h"


// This is the array    that will act as our hash table for storing evidence.
Evidence hash_table[ HASH_TABLE_SIZE];
//  slot in hash_table avaoilable or not.
bool is_occupied[ HASH_TABLE_SIZE] = {false}; // Initialize all slots to false


// A simple hash function that converts an evidence_id into an array index.
int hash_function(int evidence_id) {
    return evidence_id %  HASH_TABLE_SIZE;
}

void add_evidence() {
    Evidence new_evidence;

    printf("\nEnter Evidence ID: ");
    scanf("%d", &new_evidence.evidence_id);

    // index
    int index = hash_function(new_evidence.evidence_id);
    // Check if that slot is already occupied
    if (is_occupied[index]) {
        printf("Error: Hash collision occurred! Evidence ID %d cannot be added at index %d because it's already occupied.\n",
               new_evidence.evidence_id, index);
        printf("Please choose a different Evidence ID.\n");
        return;
    }
   

    printf("Enter Associated Case ID: ");
    scanf("%d", &new_evidence.associated_case_id);

    printf("Enter Evidence Type : ");
    getchar();
    fgets(new_evidence.type, MAX_EVIDENCE_TYPE, stdin);
    new_evidence.type[strcspn(new_evidence.type, "\n")] = '\0';

    printf("Enter Evidence Content/Details: ");
    fgets(new_evidence.content, MAX_EVIDENCE_CONTENT, stdin);
    new_evidence.content[strcspn(new_evidence.content, "\n")] = '\0';

    // Store the data in the hash table and mark the slot as occupied
    hash_table[index] = new_evidence;
    is_occupied[index] = true;

    printf("\nEvidence #%d added successfully at hash index %d!\n", new_evidence.evidence_id, index);
}

void find_evidence_by_id() {
    int evidence_id_to_find;
    printf("\nEnter the Evidence ID to find: ");
    scanf("%d", &evidence_id_to_find);

    // the index in the hash table
    int index = hash_function(evidence_id_to_find);
    // Check if the slot is occupied and if the evidence ID matches
    if (is_occupied[index] && hash_table[index].evidence_id == evidence_id_to_find) {
        printf("\n--- Evidence Found! ---\n");
        printf("Evidence ID: %d\n", hash_table[index].evidence_id);
        printf("Associated Case ID: %d\n", hash_table[index].associated_case_id);
        printf("Type: %s\n", hash_table[index].type);
        printf("Content: %s\n", hash_table[index].content);
    } else {
        printf("\n--- Evidence with ID #%d not found. ---\n", evidence_id_to_find);
    }
}

void display_all_evidence() {
    printf("\n--- All Recorded Evidence (in Hash Table) ---\n");
    bool found_any = false;
    for (int i = 0; i <  HASH_TABLE_SIZE; i++) {
        if (is_occupied[i]) {
            printf("Index %d: Evidence ID: %d | Case ID: %d | Type: %s\n",
                   i,
                   hash_table[i].evidence_id,
                   hash_table[i].associated_case_id,
                   hash_table[i].type);
            found_any = true;
        }
    }
    if (!found_any) {
        printf("No evidence has been recorded yet.\n");
    }
}