#include <iostream>
#include <stack>
using namespace std;

stack<int> stack1, stack2;

void Enqueue(int x) {
    stack1.push(x);
}


int Dequeue() 
{
    if (stack1.empty() && stack2.empty()) {
        cout << "Queue is Empty!" << endl;
        return -1;
    }

    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    int top = stack2.top();
    stack2.pop();
    return top;
}


void display() {
    stack<int> temp1 = stack1;
    stack<int> temp2 = stack2; 
    stack<int> reverseTemp;

    while (!temp2.empty()) {
        cout << temp2.top() << " ";
        temp2.pop();
    }

    while (!temp1.empty()) {
        reverseTemp.push(temp1.top());
        temp1.pop();
    }
    while (!reverseTemp.empty()) {
        cout << reverseTemp.top() << " ";
        reverseTemp.pop();
    }

    cout << endl;
}

int main() {
    int n, value, choice;

    cout << "Enter Number of Operations: ";
    cin >> n;

    while(true) 
    {
        cout << "1. Enqueue\n2. Dequeue\n";
        cout << "Choose Option:  ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter which number You want Enqueue: ";
            cin >> value;
            Enqueue(value);
        } else if (choice == 2) {
            int result = Dequeue();
            if (result != -1) {
                cout << "Num Deleted! " << result << endl;
            }
        } else {
            return -1;
        }
    }

    return 0;
}