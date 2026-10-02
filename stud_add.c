#include "student.h"
int get_smallest_unique_rollno(struct student *head) {
    int target = 1;
    while (1) {
        int found = 0;
        struct student *curr = head;
        while (curr != NULL) {
            if (curr->rollno == target) {
                found = 1;
                break;
            }
            curr = curr->next;
        }
        if (!found) {
            return target;
        }
        target++;
    }
}

void add_student(struct student **head) {
    struct student *new_node = (struct student *)malloc(sizeof(struct student));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->rollno = get_smallest_unique_rollno(*head);
printf("\nAssigned Roll No: %d\n", new_node->rollno);
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", new_node->name);
    printf("Enter Percentage: ");
    scanf("%f", &new_node->percentage);

    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    printf("Student record added successfully!\n");
}
