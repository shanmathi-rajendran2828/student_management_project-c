#include "student.h"
void save_records(struct student *head) {
    FILE *fp = fopen("student.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }

    struct student *curr = head;
    int count = 0;
    while (curr != NULL) {
        fwrite(curr, sizeof(struct student) - sizeof(struct student*), 1, fp);
        curr = curr->next;
        count++;
    }

    fclose(fp);
    printf("Successfully saved %d record(s) to student.dat.\n", count);
}
void load_records(struct student **head) {
    FILE *fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        return;
    }

    struct student temp;
    struct student *tail = NULL;
    while (fread(&temp, sizeof(struct student) - sizeof(struct student*), 1, fp) == 1) {
        struct student *new_node = (struct student *)malloc(sizeof(struct student));
        if (new_node == NULL) {
            fclose(fp);
            return;
        }
        new_node->rollno = temp.rollno;
        strcpy(new_node->name, temp.name);
        new_node->percentage = temp.percentage;
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    fclose(fp);
}
void delete_all_records(struct student **head) {
    struct student *curr = *head;
    struct student *next_node;

    while (curr != NULL) {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }

    *head = NULL;
    printf("All records cleared from memory.\n");
}
void reverse_list(struct student **head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List reversed successfully.\n");
        return;
    }

    struct student *prev = NULL;
    struct student *curr = *head;
    struct student *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
  *head = prev;
    printf("List reversed successfully!\n");
}
void sort_by_name(struct student **head) {
    if (*head == NULL || (*head)->next == NULL) return;

    int swapped;
    struct student *ptr1;
    struct student *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->name, ptr1->next->name) > 0) {
                int temp_roll = ptr1->rollno;
                char temp_name[50];
                float temp_perc = ptr1->percentage;

                strcpy(temp_name, ptr1->name);
                ptr1->rollno = ptr1->next->rollno;
                strcpy(ptr1->name, ptr1->next->name);
                ptr1->percentage = ptr1->next->percentage;

                ptr1->next->rollno = temp_roll;
                strcpy(ptr1->next->name, temp_name);
                ptr1->next->percentage = temp_perc;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("List sorted alphabetically by name.\n");
}
void sort_by_percentage(struct student **head) {
    if (*head == NULL || (*head)->next == NULL) return;

    int swapped;
    struct student *ptr1;
    struct student *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->percentage < ptr1->next->percentage) {
                int temp_roll = ptr1->rollno;
                char temp_name[50];
                float temp_perc = ptr1->percentage;

                strcpy(temp_name, ptr1->name);

                ptr1->rollno = ptr1->next->rollno;
                strcpy(ptr1->name, ptr1->next->name);
                ptr1->percentage = ptr1->next->percentage;

                ptr1->next->rollno = temp_roll;
                strcpy(ptr1->next->name, temp_name);
                ptr1->next->percentage = temp_perc;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("List sorted by percentage in descending order.\n");
}
void sort_students_menu(struct student **head) {
    if (*head == NULL) {
        printf("No records available to sort.\n");
        return;
    }

    char choice;
    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);

    if (choice == 'n' || choice == 'N') {
        sort_by_name(head);
    } else if (choice == 'p' || choice == 'P') {
        sort_by_percentage(head);
    } else {
        printf("Invalid option.\n");
    }
}
