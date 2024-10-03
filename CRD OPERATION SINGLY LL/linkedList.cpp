#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

void insertAtHead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node*& head, int d) {
    node* temp1 = new node(d);
    if (head == NULL) {
        head = temp1; // If the head is NULL, set the head to temp1
        return; // Exit the function
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = temp1;
}

void insertAtPosition(node* &head, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, d);
        return;
    }

    node* temp1 = new node(d);
    node* temp = head;
    int count = 1;
    while (count != pos - 1 && temp != NULL) { // Added condition to ensure temp is not NULL
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        temp1->next = temp->next;
        temp->next = temp1;
    }
    else {
        cout << "Position out of bounds" << endl; // In case the position is beyond the length of the list
    }
}
//remove head of linkedList
void deleteHead(node*& head)
{
    node* temp = head;
     head=head->next;
    free(temp);
}

//remove tail of linkedList
void deleteTail(node*& head)
{
    if (head == NULL )    {
        cout << "List is Empty" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    node* temp = head;
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
// delete kth element of node 
void deletekthelement(node* &head,int pos)
{
    if (pos == 1)
    {
        deleteHead(head);
        return;
    }
    int counter = 1;
    node* prev = NULL;
    node* temp = head;
    while (temp != NULL && counter<pos)
    {
        prev = temp;
        temp = temp->next;
        counter++;
    }
    
    
        prev->next = temp->next;
        free(temp);
        
    }
    
    
   



   

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(int argc, char const* argv[]) {
    node* n = new node(100);

    node* head = n;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
   /* deleteTail(head);*/
    deletekthelement(head, 2);
    /*deleteHead(head);*/
    /*insertAtPosition(head, 6, 300);*/
    // insertAtPosition(head, 2, 1000);

    cout << "Linked List:" << endl;
    display(head);

    return 0;
}
