#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

void display_menu(void);
void clear_input_buffer(void);
void trim_newline(char *str);

void add_student(struct student **head);
int get_smallest_unique_rollno(struct student *head);

void delete_student_menu(struct student **head);
void delete_by_rollno(struct student **head, int rollno);
void delete_by_name(struct student **head, const char *name);
void display_students(struct student *head);

void modify_student_menu(struct student *head);
void modify_by_rollno(struct student *head, int rollno);
void modify_by_name(struct student *head, const char *name);
void modify_by_percentage(struct student *head, float percentage);

void save_records(struct student *head);
void load_records(struct student **head);

void sort_students_menu(struct student **head);
void sort_by_name(struct student **head);
void sort_by_percentage(struct student **head);
void delete_all_records(struct student **head);
void reverse_list(struct student **head);

#endif
