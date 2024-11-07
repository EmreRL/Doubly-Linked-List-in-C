#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct double_linkedlist {
    int age;
    char name[50];
    char surname[50];
    struct double_linkedlist* back;
    struct double_linkedlist* next;
};

struct double_linkedlist* head = NULL;

void getValue(struct double_linkedlist* temp) {
    printf("Please enter the age: ");
    scanf(" %d", &temp->age);
    printf("Please enter the name: ");
    scanf(" %s", temp->name);
    printf("Please enter the surname: ");
    scanf(" %s", temp->surname);
}

void insertEnd(struct double_linkedlist* temp) {
    struct double_linkedlist* ktemp;
    ktemp = head;
    temp = (struct double_linkedlist*)malloc(sizeof(struct double_linkedlist));
    if (head) {
        while (ktemp->next) {
            ktemp = ktemp->next;
        }
        ktemp->next = temp;
        temp->back = ktemp;
        temp->next = NULL;
    } else {
        temp->next = NULL;
        temp->back = NULL;
        head = temp;
    }
    getValue(temp);
}

void removeHead(struct double_linkedlist* temp) {
    temp = head;
    head = temp->next;
    if (head != NULL) {
        head->back = NULL;
    }
    temp->next = NULL;
    free(temp);
}

void listValues(int* val, struct double_linkedlist* temp) {
    temp = head;
    int count = 1;
    char direction;
    while (1) {
        system("cls");
        printf("\n(%d) Age: %d", count, temp->age);
        printf("\n(%d) Name: %s", count, temp->name);
        printf("\n(%d) Surname: %s", count, temp->surname);
        printf("\n******************\n");
        if (count != 1 && *val != 1 && count != *val) {
            printf("(D) to move forward\n(A) to move back\n(C) Exit\n");
            scanf(" %c", &direction);
            if (direction == 'D' || direction == 'd') {
                temp = temp->next;
                count++;
            } else if (direction == 'A' || direction == 'a') {
                temp = temp->back;
                count--;
            } else {
                break;
            }
        } else if (count == 1 && *val != 1) {
            printf("(D) to move forward\n(C) Exit\n");
            scanf(" %c", &direction);
            if (direction == 'D' || direction == 'd') {
                temp = temp->next;
                count++;
            } else {
                break;
            }
        } else if (count != 1 && count == *val) {
            printf("(A) to move back\n(C) Exit\n");
            scanf(" %c", &direction);
            if (direction == 'A' || direction == 'a') {
                temp = temp->back;
                count--;
            } else {
                break;
            }
        } else {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    int count = 0, option = 0;
    struct double_linkedlist* start;
    while (1) {
        printf("(1) Add Value\n(2) List Values\n(3) Remove Head\n(4) Exit\n");
        scanf("%d", &option);
        if (option == 1) {
            count++;
            system("cls");
            insertEnd(start);
            system("cls");
            printf("***Added to the Double Linked List !***\n");
        }
        if (option == 2) {
            if (count == 0) {
                system("cls");
                printf("***No values added yet.***\n");
            }
            if (count != 0) {
                listValues(&count, start);
                printf("\n***Listed the Values !***\n\n");
            }
        }
        if (option == 3) {
            if (count == 0) {
                system("cls");
                printf("***No values added yet.***\n");
            }
            if (count != 0) {
                removeHead(start);
                count--;
                system("cls");
                printf("***Removed Successfully !***\n");
            }
        }
        if (option == 4) {
            break;
        }
    }
}

