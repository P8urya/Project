#include <iostream>
using namespace std;


const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int current_size = 0;


void Insert(int index, int value)
{
    if (index < 0 || current_size >= MAX_SIZE) 
    {
        cout << "Invalid index!" << endl;
        return;
    }
        for (int i = current_size ; i > index ; i--) 
    {
        arr[i] = arr[i - 1];
    }   
    arr[index] = value;
    current_size++;
}

void Delete_By_Value(int value)
{
    for(int i=0 ; i < current_size ; i++)
    {
        if(arr[i] == value)
        {
            for(int j=i ; j < current_size -1 ; j++)
            {
                arr[j] = arr[j+1];
            }
            current_size--;
            cout << i << endl;
        }
    }
    cout << "Deleted Successfully!" << endl;
}

void Delete_By_Index(int input)
{
    for(int i=0 ; i < current_size ; i++)
    {
        if(i == input)
        {
            for(int j=i ; j < current_size ; j++)
            {
                arr[j] = arr[j +1];
            }
            current_size--;
        }
    }
}

void Display()
{
    for(int i=0 ; i < current_size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Append (int value)
{
    if(current_size >= MAX_SIZE)
    {
        cout << "Array Is Full!" << endl;
    }
    arr[current_size] = value;
    current_size++;
}

void Reverse(int arr[])
{
        for (int i = 0; i < current_size / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[current_size - 1 - i];
            arr[current_size - 1 - i] = temp;
        }
        cout << "Reversed array is: ";
        Display();
}

int Search_By_Value(int value)
{
    for(int i=0 ; i < current_size ; i++)
    {
        if(arr[i] == value)
        {
            cout << "Value was Available in index: " << i << endl;
        }
    }
    cout << "Value not found!" << endl;
    return -1;
}

int main()
{

    int Index , Value , num;
    while(true)
    {
    cout << "Enter Action You Want To Do: " << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete by Value" << endl;
    cout << "3. Delete by Index" << endl;
    cout << "4. Display Array" << endl;
    cout << "5. Append" << endl;
    cout << "6. Reverse" << endl;
    cout << "7. Search" << endl;

    cin >> num;
        if(num==1)
        {
            cout << "Enter Value and Index you want to Add: " << endl;
            cin >> Value >> Index;
            Insert(Index , Value);
        }

        else if(num==2)
        {
            cout << "Enter Value You want to Delete it: " << endl;
            cin >> Value;
            Delete_By_Value(Value);
        }

        else if(num==3)
        {
            cout << "Enter Index You want to Delete it: " << endl;
            cin >> Index;
            Delete_By_Index(Index);
        }

        else if(num==4)
        {
            cout << "Array is: " << endl;
            Display();
        }

        else if(num==5)
        {
            cout << "Enter Value You want to place End of Array: " << endl;
            cin >> Value;
            Append(Value);
        }

        else if(num==6)
        {
            cout << "Array Will Reverse as Soon: " << endl;
            Reverse(arr);
        }

        else if(num==7)
        {
            cin >> Value;
            cout << "Searching Array..." << endl;
            Search_By_Value(Value);
        }
    }
    return 0;

}