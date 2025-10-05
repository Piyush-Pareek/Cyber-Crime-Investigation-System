#ifndef evidence_management_h
#define evidence_management_h

#include "case_management.h" // for case structure definition
#define HASH_TABLE_SIZE 100 // Size of the hash table for cases
#define MAX_EVIDENCE_CONTENT 1000 // Maximum length of evidence description
#define MAX_EVIDENCE_TYPE 50 // Maximum length of evidence type
// structure to hold evidence information
typedef struct{
    int evidence_id; // Unique identifier for the evidence
    int associated_case_id; // ID of the case this evidence belongs to
    char content[MAX_EVIDENCE_CONTENT]; // Description of the evidence
    char type[MAX_EVIDENCE_TYPE]; // Type of the evidence (e.g., document, physical item)

}Evidence;
// functions 
void add_evidence();
void find_evidence_by_id(); //to find evidence by case ID
void display_all_evidence(); //to display all evidence items

#endif