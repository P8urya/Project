#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int queue[MAX_SIZE];
int front = -1 , rear = -1;


bool isEmpty() 
{
    return front == -1;
}

bool isFull() 
{ 
    return (rear + 1) % MAX_SIZE == front; 
}

void Enqueue(int data)
{
    if(isFull())
    {
        cout << "Queue is Full!" << endl;
        return;
    }
    if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = data;
}

void Dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty!" << endl;
    }

    int data = queue[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
}

void Peek()
{
    if(isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << queue[front] << endl;
}

void ReverseQueue()
{
    int Start , End;
    if(isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Start = front;
    End = rear;
    while(Start != End && (End + 1) % MAX_SIZE != Start)
    {
        int temp = queue[Start];
        queue[Start] = queue[End];
        queue[End] = temp;
        Start = (Start + 1) % MAX_SIZE;
        End = (End -1 + MAX_SIZE) % MAX_SIZE;
    }
}

void displayQueue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    int i = front;
    while (true) 
    {
        cout << queue[i] << " ";
        if(i == rear)
        {
            break;
        }
        i = (i+1) % MAX_SIZE;
    }
    cout << endl;
}




int main()
{
    int num, input;
    while(true)
    {
    cout << "Enter Action Number to do: " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Reverse Queue" << endl;
    cout << "5. Display Queue" << endl;
    cout << "6. Exit" << endl;
    cin >> num;
    if(num == 1)
    {
        cout << "Enter num you want Enqueue: " << endl;
        cin >> input;
        Enqueue(input);
    }
    else if(num == 2)
    {
        cout << "Deleting... " << endl;
        Dequeue();
    }
    else if(num == 3)
    {
        cout << "Front Element is: " << endl;
        Peek();
    }
    else if(num == 4)
    {
        cout << "Reversing Queue... " << endl;
        ReverseQueue();
        displayQueue();
    }
    else if(num == 5)
    {
        displayQueue();
    }
    else if(num == 6)
    {
        break;
    }
    }
}