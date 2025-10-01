#include <stdio.h>
#include "case_management.h"
#include "evidence_management.h" 
// Menu functions
void show_main_menu() {
    printf("\n--- Cyber Crime Investigation System ---\n");
    printf("1. Add a New Case\n");
    printf("2. Display All Cases\n");
    printf("3. Add Evidence to a Case\n"); 
    printf("4. Display All Evidence\n");  
    printf("9. Exit\n");
    printf("Enter your choice: ");
}
// Main function
int main() {
    int choice;
    while (1) {
        show_main_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_new_case();
                break;
            case 2:
                display_cases();
                break;
            case 3:
                add_evidence(); 
                break;
            case 4:
                display_all_evidence(); 
                break;
   
            case 9:
                printf("Exiting system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}