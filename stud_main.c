include "student.h"

int main(void) {
    struct student *head = NULL;
    char choice;

    load_records(&head);

    while (1) {
        printf("\n--- STUDENT MENU ---\n");
        printf("a: Add  | d: Delete | s: Show | m: Modify\n");
        printf("v: Save | t: Sort   | r: Reverse | e: Exit\n");
        printf("Enter choice: ");

        if (scanf(" %c", &choice) != 1) break;

        switch (choice) {
            case 'a': case 'A':
                add_student(&head);
                break;
            case 'd': case 'D':
                delete_student_menu(&head);
                break;
            case 's': case 'S':
                display_students(head);
                break;
            case 'm': case 'M':
                  modify_student_menu(head);
                break;
            case 'v': case 'V':
                save_records(head);
                break;
            case 't': case 'T':
                sort_students_menu(&head);
                break;
            case 'r': case 'R':
                reverse_list(&head);
                break;
            case 'e': case 'E':
                save_records(head);
                delete_all_records(&head);
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
