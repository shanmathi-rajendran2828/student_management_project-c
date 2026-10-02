#include "student.h"
void modify_by_rollno(struct student *head, int rollno) {
    if (head == NULL) {
        printf("No records available to modify!\n");
        return;
    }

    struct student *curr = head;
    while (curr != NULL) {
        if (curr->rollno == rollno) {
            printf("\nFound Record for Roll No %d:\n", rollno);
            printf("Current Name: %s\n", curr->name);
            printf("Current Percentage: %.2f\n", curr->percentage);

            printf("\nEnter New Name: ");
            scanf(" %[^\n]s", curr->name);

            printf("Enter New Percentage: ");
            scanf("%f", &curr->percentage);

            printf("Record updated successfully!\n");
            return;
        }
        curr = curr->next;
    }
    printf("Record with Roll No %d not found.\n", rollno);
}
void modify_student_menu(struct student *head) {
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }

    int rno;
    printf("Enter Roll Number to modify: ");
    if (scanf("%d", &rno) == 1) {
        modify_by_rollno(head, rno);
    } else {
        printf("Invalid input!\n");
    }
}

    printf("Record with Roll No %d not found.\n", rollno);
