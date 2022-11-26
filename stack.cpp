#include "Stack.H"
void Stack::push(int n)
{
    if (header->pointer == nullptr) // checks to see if array doesnt exist
    {
        // cout << "push 1" << endl;
        y(arraySize);
        int *p = header->pointer;
        p[topElement] = n;
        topElement++;
    }

    else if (topElement == arraySize) // checks to see if array is full
    {
        // cout << "push 2" << endl;
        topElement = 0;
        int *newArray = new int[arraySize];
        Node *temp = new Node();
        temp->pointer = newArray;
        temp->next = header;
        newArray[topElement] = n;
        header = temp;
        topElement++;
    }
    else // adds n to top of array
    {
        // cout << "push 3" << endl;
        int *p = header->pointer;
        p[topElement] = n;
        topElement++;
    }
}

bool Stack::top(int &i)
{

    if (header->pointer == nullptr || topElement == 0)
    {

        return false;
    }
    else
    {

        int *g = header->pointer;

        i = g[topElement - 1];

        return true;
    }
}

bool Stack::pop()
{

    if (header->pointer == nullptr || topElement == 0) // if there is no linkedlist
    {
        // cout << "pop 1" << endl;
        return false;
    }
    else if (topElement == 1 && header->next != nullptr) // if theres only 1 element and if there is next linked list
    {
        // cout << "pop 2" << endl;
        Node *temp = new Node();
        temp = header->next;
        delete header->pointer;
        delete header;
        header = temp;
        topElement = arraySize;
        return true;
    }
    else if (topElement == 1 && header->next == nullptr) // if there is only 1 element and there is no other linked list
    {
        // cout << "pop 3" << endl;
        header->pointer = nullptr;

        topElement--;
        return false;
    }
    else
    {
        // cout << "pop 4" << endl; // if its a array has more than 1 element
        topElement--;
        return true;
    }
}
void Stack::destroy()
{

    while (header->next != nullptr)
    {
        Node *temp = header->next;
        delete header;
        header = temp;
        topElement = 0;
    }
    return;
}
