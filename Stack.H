#include <iostream>
#ifndef Stack_H
#define Stack_H
using namespace std;
struct Node
{
    int *pointer = nullptr;
    Node *next;
};
class Stack
{
private:
    Node *header = new Node();

public:
    void push(int s);
    bool pop();
    bool top(int &i);
    void destroy();
    int arraySize = 16;
    int topElement = 0;
    void y(int s)
    {

        int *array = new int[s];
        header->pointer = array;
        header->next = nullptr;
        arraySize = s;
        topElement = 0;
    }
    Stack(int s)
    {

        int *array = new int[s];
        header->pointer = array;
        header->next = nullptr;
        arraySize = s;
        topElement = 0;
    }
};
#endif
