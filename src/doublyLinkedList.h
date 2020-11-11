//data ADT -- data is defined in the .c file
typedef struct data *Data;

Data newData(int val);  //constructor for Data point
void printData(Data d); // debugging method for printing out data

//node ADT -- the struct definition is given in the .c file
typedef struct node *Node;

void prepend(Node *h, Data d); //prepend an item to the head of the doubly-linked list

void append(Node *h, Data d); //append to head of doubly linked list

void insertAfter(Node prev, Data toInsert); //insert item after given item

void delete(Node *h, Node toDel);

Node findData(Node h, Data x); //searches for a Data x in a doubly-linked list with head h

void printList(Node head); // debugging method for printing list