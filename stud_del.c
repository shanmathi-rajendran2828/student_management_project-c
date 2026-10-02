#include "student.h"
void delete_by_rollno(struct student **head, int rollno) {
    if (*head == NULL) {
        printf("No records available to delete!\n");
        return;
    }

    struct student *temp = *head;
    struct student *prev = NULL;
    if (temp != NULL && temp->rollno == rollno) {
        *head = temp->next;
        free(temp);
        printf("Record with Roll No %d deleted successfully.\n", rollno);
        return;
    }
    while (temp != NULL && temp->rollno != rollno) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Record with Roll No %d not found.\n", rollno);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Record with Roll No %d deleted successfully.\n", rollno);
}
void delete_student_menu(struct student **head) {
    if (*head == NULL) {
        printf("No student records available.\n");
        return;
    }

    int rno;
    printf("Enter Roll Number to delete: ");
    if (scanf("%d", &rno) == 1) {
        delete_by_rollno(head, rno);
    } else {
        printf("Invalid input!\n");
    }
}
