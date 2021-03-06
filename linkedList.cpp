#include <bits/stdc++.h>
using namespace std;
#define pi(x)	printf("%d\n",x)
#define ps(s)	printf("%s\n",s)
#define newLine() cout << "\n";
class Node {
    public:
    int data;
    Node *next;
};

// Inserting at the first of the linked list
void push(Node** head_ref, int data) 
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Inserting at a given node of the linkedlist
void insertAfter(Node* prev_node, int data) 
{
    if(prev_node == NULL) 
    {
        ps("Sorry no node available right now");
    }

    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Inserting at the end of the linked list
void append(Node** head_ref, int data)
{
    Node* last = *head_ref;
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    if((*head_ref) == NULL)
    {
        *head_ref = new_node;
        return;
    } 
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// Printing the linked list
void printList(Node *node)
{
    while(node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

// Deleting node at the given key
void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = temp;
    if(temp !=  NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
} 

// Delete node at a position
void deleteNodeAtPosition(Node **head, int position) 
{
    if(*head == NULL)
        return;
    
    Node* temp = *head;
    if(position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for(int i = 0; temp != NULL && i < position; i++)
        temp = temp->next;
    
    if(temp == NULL || temp->next == NULL)
        return;
    
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main()
{
    Node* head = NULL;
    // head->5
    append(&head, 5);
    // head->7->5
    push(&head, 7);
    // head->1->7->5
    push(&head, 1),
    // head->1->7->5->5
    append(&head, 5);
    // head->1->7->8->5->5
    insertAfter(head->next, 8);
    /**
     * Nodes will be
     * 
     * head->1->7->8->5->5
     * 
     */
    printList(head);

    // 1->7->5->5
    deleteNode(&head, 8);
    newLine()
    printList(head);
    insertAfter(head->next, 8);
    deleteNodeAtPosition(&head, 3);
    newLine()
    printList(head);

    return 0;
}