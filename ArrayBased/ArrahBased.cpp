#include <iostream>

using namespace std;

// stack declaration

const int MAXSTACK = 100000;

struct stack
{
    int element[MAXSTACK];
    int top = 0;
};

// stack functions declaration

void Push(int elementValue, stack *s); // pe -> pointer to element
bool stackFull(stack *s); // to check if the stack is full
bool stackEmpty(stack *s); // to check if the stack is empty
void Pop(int *e, stack *s); // to remove the last element and store the deleted value in a variable
int stackTop(stack *s); // to get the last element in the stack
int stackSize(stack *s); // to get the stack size
void clearStack(stack *s); // to remove all elements in the stack
void displayStack(stack *s); // to print all values in the stack

int main()
{
    stack s;
    if (!stackFull(&s)) Push(7, &s);
    else cout << "Stack is full." << endl;
    int element;
    if (!stackEmpty(&s)) Pop(&element, &s);
    else cout << "Stack is empty." << endl;
    if (!stackEmpty(&s)) element = stackTop(&s);
    else cout << "Stack is empty" << endl;

    cout << stackSize(&s) << endl;

    Push(19, &s);

    displayStack(&s);
    return 0;
}

// stack functions implementation

void Push(int elementValue, stack *s) // to push element to stack
{
    s->element[s->top++] = elementValue;
}

bool stackFull(stack *s) // to check if the stack is full
{
    return s->top == MAXSTACK;
}

bool stackEmpty(stack *s) // to check if the stack is empty
{
    return s->top == 0;
}

void Pop(int *e, stack *s)
{
    *e = s->element[s->top--];
}

int stackTop(stack *s)
{
    return s->element[s->top];
}

int stackSize(stack *s)
{
    return s->top;
}

void clearStack(stack *s)
{
    s->top = 0;
}

void displayStack(stack *s)
{
    for (int i = s->top; i >= 0; i--) cout << s->element[i] << ' ';
}
