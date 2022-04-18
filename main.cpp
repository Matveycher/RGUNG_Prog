#include <iostream>
#include "queue.h"

using namespace std;

void instructions();
void printcase(int);

int main()
{
    Queue Q1, Q2;
    Q1.queueFill();
    cout >> "Do you need the second queue? (y/n)";
    char answer;
    cin >> answer;
    if (answer == 'y')
    {
        Q2.queueFill();
    }
    int choice;
    int value1, value2;
    instructions();
    cout << "? ";
    cin >> choice;
    while (choice != 15)
    {
        switch (choice)
        {
        case 1:
            printcase(choice);
            Q1.condition();
            break;
        case 2:
            printcase(choice);
            copyQueue(Q1, Q2);
            break;
        case 3:
            printcase(choice);
            cout << "Enter integer to add: ";
            cin >> value1;
            Q1.enqueueFront(value1);
            Q1.print();
            break;
        case 4:
            printcase(choice);
            cout << "Enter integer to add: ";
            cin >> value1;
            Q1.enqueue(value1);
            Q1.print();
            break;
        case 5:
            printcase(choice);
            cout << "Enter 2 integers (FROM|INTO): ";
            cin >> value1 >> value2;
            Q1.edit(value1, value2);
            Q1.print();
            break;
        case 6:
            printcase(choice);
            break;
        case 7:
            printcase(choice);
            value1 = Q1.dequeue();
            cout << "Element with value " << value1 << " is deleted" << endl;
            Q1.print();
            break;
        case 8:
            printcase(choice);
            Q1.deleteAll();
            Q1.print();
            break;
        case 9:
            printcase(choice);
            cout << "Length of queue is: " << Q1.length() << endl;
            break;
        case 10:
            printcase(choice);
            Q1.sortQueue();
            Q1.print();
            break;
        case 11:
            printcase(choice);
            Q1.reverseQueue();
            Q1.print();
            break;
        case 12:
            printcase(choice);
            cout << "Queue 1:" << endl;
            Q1.print();
            cout << "Queue 2:" << endl;
            Q2.print();
            Q1.stackQueue(Q2);
            cout << "Resultinig Queue 1:" << endl;
            Q1.print();
            break;
        case 13:
            printcase(choice);
            cout << "Queue 1:" << endl;
            Q1.print();
            cout << "Queue 2:" << endl;
            Q2.print();
            Q1.mergeQueue(Q2);
            cout << "Resultinig Queue 1:" << endl;
            Q1.print();
            break;
        case 14:
            printcase(choice);
            Q1.deleteDups();
            Q1.print();
            break;
        default:
            cout << "invalid choice" << endl
                 << endl;
            instructions();
            break;
        }
        cout << "? ";
        cin >> choice;
    }
    cout << "End of run" << endl;
    return 0;
}

void instructions()
{
    cout << "Enter your choice:" << endl
         << "1 to print the condition of your queue: head element, tail element, length of queue" << endl
         << "2 to make a copy of your queue" << endl
         << "3 to add an element in the beginning of your queue" << endl
         << "4 to add an element in the end of your queue" << endl
         << "5 to change the chosen element" << endl
         << "6 to delete the chosen element" << endl
         << "7 to remove the element and print it" << endl
         << "8 to delete the whole queue" << endl
         << "9 to print the length of your queue" << endl
         << "10 to sort your queue in increasing order" << endl
         << "11 to invert your queue" << endl
         << "12 to add two queues together" << endl
         << "13 to combine two queues" << endl
         << "14 to delete the duplicates" << endl
         << "15 to end the run" << endl;
}

void printcase(int choice)
{
    cout << "Case " << choice << " is working" << endl;
}

void queueFill(Queue &)
{
    Queue Q;
    cout >> "Do you want to fill your queue randomly? (y/n)";
    char answer;
    cin >> answer;
    if (answer == 'y')
    {
        Q.fillRandom();
    }
    else
    {
        cout << "Enter the number of elements you want to add: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter the value of element " << i + 1 << ": ";
            cin >> value;
            Q.enqueue(value);
        }
    }
}

void Queue::fillRandom()
{
    srand(time(NULL));
    int n = rand() % 10 + 1;
    for (int i = 0; i < n; i++)
    {
        int value = rand() % 100 + 1;
        enqueue(value);
    }
}