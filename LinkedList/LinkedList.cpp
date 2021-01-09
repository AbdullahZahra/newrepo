#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void insertNode(int);
void display();
bool isEmpty();
void deleteNode(int);
void insertBeginning(int);
void deleteBeginning();
void deleteEnd();

int main()
{
    insertNode(5);
    insertNode(10);
    insertNode(20);
    insertNode(30);
    display();
    deleteNode(10);
    deleteNode(20);
    display();
    insertBeginning(300);
    display();
    deleteBeginning();
    display();
    insertNode(9);
    insertNode(13);
    display();
    deleteEnd();
    deleteEnd();
    display();
    return 0;
}

void insertNode(int value)
{
    node *newNode, *lastElement;
    newNode = new node;
    newNode->data = value;
    
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else 
    {
        lastElement = head;
        while (lastElement->next != NULL)
        {
            lastElement = lastElement->next;
        }
        lastElement->next = newNode;
        newNode->next = NULL;
    }
}

bool isEmpty()
{
    return head == NULL;
}

void display()
{
    node *currentNode;
    if (isEmpty()) cout << "Linked list is empty" << endl;
    else
    {
        currentNode = head;
        while (currentNode != NULL)
        {
            cout << currentNode->data << '\t';
            currentNode = currentNode->next;
        }
    }
    cout << endl;
}

void deleteNode(int value)
{
    node *currentNode, *prevNode;
    currentNode = head;
    prevNode = head;

    if (currentNode->data == value) 
    {
        head = currentNode->next;
        delete prevNode;
        return;
    }
    
    while (currentNode->data != value)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    prevNode->next = currentNode->next;
    delete currentNode;
    
}

void insertBeginning(int value)
{
    node *newNode;
    newNode = new node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteBeginning()
{
    if (isEmpty()) cout << "Linked list is empty" << endl;
    else
    {
        node *temp;
        temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteEnd()
{
    if (isEmpty()) 
    {
        cout << "Linked list is empty" << endl;
        return;
    }

        node *current, *prevNode;
        current = head;
        prevNode = head;
    
    while (current->next != NULL)
    {
        prevNode = current;
        current = current->next;
    }
    delete current;
    prevNode->next = NULL;
}
