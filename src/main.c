#include <stdio.h>
#include "doublyLinkedList.h"

int main(){
    Node h;
    h = NULL;
    Data x = newData(1);
    Data y = newData(2);
    Data z = newData(3);
    Data k = newData(4);
    printf("Prepending 1 to the list\n");
    prepend(&h, x);
    printf("Prepending 2 to the list\n");
    prepend(&h, y);
    printf("Appending 3 to the list\n");
    append(&h, z);
    printf("Inserting 4 after 1\n");
    insertAfter(findData(h, x), k);
    printf("List is: ");
    printList(h);
    printf("Deleting 3 from list\n");
    delete(&h, findData(h, z));
    printf("List is: ");
    printList(h);
    return 0;
}