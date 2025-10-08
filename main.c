updated main.c 
#include <stdio.h>

// Include ALL module headers so main() knows about their functions.
// This is the correct way to structure a multi-file C project.
#include "utils.h"
#include "case_management.h"
#include "evidence_management.h"
#include "suspect_network.h"

// --- Sub-Menu Functions ---
// These functions create a clean, organized user experience by separating
// the concerns of each module.

/**
 * @brief Displays and handles the menu for the Case Management module.
 */
void show_case_menu() {
    int choice = 0;
    while (choice != 9) {
        clear_screen();
        print_header("Case Management");
        printf("1. Add New Case\n");
        printf("2. Process Highest Priority Case\n");
        printf("3. Display All Active Cases\n");
        printf("9. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_new_case(); press_enter_to_continue(); break;
            case 2: process_highest_priority_case(); press_enter_to_continue(); break;
            case 3: display_cases(); press_enter_to_continue(); break;
            case 9: break; // This will exit the while loop and return to the main menu.
            default: printf("Invalid choice.\n"); press_enter_to_continue();
        }
    }
}

/**
 * @brief Displays and handles the menu for the Evidence Management module.
 */
void show_evidence_menu() {
    int choice = 0;
    while (choice != 9) {
        clear_screen();
        print_header("Evidence Management");
        printf("1. Add Evidence\n");
        printf("2. Find Evidence by ID\n");
        printf("3. Display All Evidence\n");
        printf("9. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_evidence(); press_enter_to_continue(); break;
            case 2: find_evidence_by_id(); press_enter_to_continue(); break;
            case 3: display_all_evidence(); press_enter_to_continue(); break;
            case 9: break;
            default: printf("Invalid choice.\n"); press_enter_to_continue();
        }
    }
}

/**
 * @brief Displays and handles the menu for the Suspect Network module.
 */
void show_suspect_menu() {
    int choice = 0;
    while (choice != 9) {
        clear_screen();
        print_header("Suspect Network Management");
        printf("1. Add New Suspect\n");
        printf("2. Add Connection Between Suspects\n");
        printf("3. Display Suspect Network\n");
        printf("9. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_suspect(); press_enter_to_continue(); break;
            case 2: add_connection(); press_enter_to_continue(); break;
            case 3: display_suspect_network(); press_enter_to_continue(); break;
            case 9: break;
            default: printf("Invalid choice.\n"); press_enter_to_continue();
        }
    }
}

// --- Main Program Loop ---
// The main function is now very simple. Its only job is to act as a
// high-level controller, directing traffic to the correct sub-menu.

int main() {
    int choice = 0;
    while (choice != 9) {
        clear_screen();
        print_header("Cyber Crime Investigation System");
        printf("1. Case Management\n");
        printf("2. Evidence Management\n");
        printf("3. Suspect Management\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: show_case_menu(); break;
            case 2: show_evidence_menu(); break;
            case 3: show_suspect_menu(); break;
            case 9: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); press_enter_to_continue();
        }
    }
    return 0;
}