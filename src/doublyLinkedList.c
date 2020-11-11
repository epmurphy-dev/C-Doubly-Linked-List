#include "doublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

//concrete implementations of ADTs
//Data and Node point to instances of these structs
struct data {
    int val;
};

struct node {
    Data dat;
    struct node *prev;
    struct node *next;
};

Data newData(int val) {
    //allocate space for Data and fill in value
    Data new = (Data)malloc(sizeof(struct data));
    new->val = val;
    return new;
}

void prepend(Node *h, Data d) {
    //allocate space for new node
    Node new = (Node)malloc(sizeof(struct node));
    //fill in data
    new->dat = d;
    new->next = *h;
    new->prev = NULL;

    //if the head is not empty, set the current head's previous item to the prepended data
    if (*h != NULL)
        (*h)->prev = new;

    //reset head of linked list
    *h = new;
    return;
}

void append(Node *h, Data d) {
    //allocate space for new node and fill in data
    Node new = (Node)malloc(sizeof(struct node));
    new->dat = d;
    new->next = NULL;
    Node curr = *h;

    //if current list is empty, set head to new item and return
    if (*h == NULL) {
        new->prev = NULL;
        *h = new;
        return;
    }

    //move curr to the last item
    while (curr->next != NULL)
        curr = curr->next;

    //set the last item's next to the current item
    curr->next = new;
    //set the current item's previous node to formerly last node
    new->prev = curr;
    return;
}

void insertAfter(Node prev, Data toInsert) {
    //allocate space for new data and fill in values
    Node new = (Node)malloc(sizeof(struct node));
    new->dat = toInsert;
    new->next = prev->next;
    new->prev = prev;
    prev->next = new;
    if (new->next != NULL)
        //paranthesis are not neccesary here, but were included for clarity
        (new->next)->prev = new;
    return;
}

void delete (Node *h, Node toDel) {
    if (*h == NULL || toDel == NULL)
        return;

    if (toDel->next)
        (toDel->next)->prev = toDel->prev;

    if (toDel->prev)
        (toDel->prev)->next = toDel->next;

    if (toDel == *h)
        *h = toDel->next;

    free(toDel);
    return;
}

Node findData(Node h, Data x) {
    Node curr = h;
    while (curr != NULL && curr->dat != x)
        curr = curr->next;
    return curr;
}

void printData(Data d) {
    printf("%d", d->val);
    return;
}

void printList(Node head) {
    Node curr = head;
    while (curr) {
        printData(curr->dat);
        if (curr->next != NULL)
            printf("-->");
        curr = curr->next;
    }
    printf("\n");
    return;
}