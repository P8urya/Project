#include <iostream>
using namespace std;


const int MAX = 100;
int Stack[MAX];
int top = -1;

void Push(int item) 
{
    if (top == MAX - 1) {
        cout << "Stack is Full (Overflow)!" << endl;
        return;
    }
    Stack[++top] = item;
}

int Pop() 
{
    if (top == -1) {
        cout << "Stack is Empty (Underflow)!";
        return -1;
    }
    return Stack[top--];
}

int Peek() 
{
    if (top == -1) {
        cout << "Stack is Empty!";
        return -1;
    }
    return Stack[top];
}

bool IsEmpty() 
{
    return top == -1;
}

void Display()
{
    if(top == -1)
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "Stack Elements are: " << endl;
    for(int i=top ; i>=0 ; i--)
    {
        cout << Stack[i] << " ";
    }
    cout << endl;
}


int main() {
    int choice, item;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. Display\n6. Exit\n";
        cout << "Choose Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value you want to Push: ";
                cin >> item;
                Push(item);
                break;
            case 2:
                item = Pop();
                if (item != -1) cout << "Deleted Value Is: " << item << endl;
                break;
            case 3:
                item = Peek();
                if (item != -1) cout << "Stack Top: " << item << endl;
                break;
            case 4:
                if (IsEmpty())
                    cout << "Stack is Empty!" << endl;
                else
                    cout << "Stack isn't Empty!" << endl;
                break;
            case 5:
                Display();
                break;
            case 6:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Wrong Option" << endl;
        }
    } while (choice != 6);

    return 0;
}