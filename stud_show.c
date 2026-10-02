include "student.h"
void display_students(struct student *head) {
    if (head == NULL) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n%-10s %-30s %-10s\n", "Roll No.", "Name", "Percentage");
    printf("--------------------------------------------------\n");

    struct student *curr = head;
    while (curr != NULL) {
        printf("%-10d %-30s %-10.2f\n", curr->rollno, curr->name, curr->percentage);
        curr = curr->next;
    }
    printf("--------------------------------------------------\n");
}
