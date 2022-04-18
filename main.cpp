#include <iostream>
#include "queue.h"

using namespace std;

void instructions();
void printcase(int);

int main() {
	Queue Q1, Q2;
	Q2.enqueue(1);
	Q2.enqueue(2);
	Q2.enqueue(3);
    int choice;
    int value1, value2;
    instructions();
    cout << "? ";
    cin >> choice;
    while (choice != 15) {
        switch(choice) {
            case 1:
                printcase(choice);
                Q1.condition();
                break;
            case 2:
                printcase(choice);
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
                /*
                //вставь в case: определение длины для каждой очереди, запуск фунции("голова и хвост от большей очереди","голова и хвост от меньшей очереди");
                int length_one, length_two;
                length_one = length(phead,1);
                length_two = length(phead2,1);
                if (length_one>=length_two)
                    phead=stack_queues(&phead, &phead2);
                else
                    phead=stack_queues(&phead2, &phead);
                printqueue(phead);
                */
                break;
            case 13:
                printcase(choice);
                /*
                mergeq(&phead, &ptail, &phead2, &ptail2);
                printqueue(phead);
                */
                break;
            case 14:
                printcase(choice);
                Q1.deleteDups();
                Q1.print();
                break;
            default:
                cout<<"invalid choice"<<endl<<endl;
                instructions();
                break;
        }
        cout<<"? ";
        cin >> choice;
    }
    cout << "End of run" << endl;
	return 0;
}

void instructions() {
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

void printcase(int choice) {
	cout << "Case " << choice << " is working" << endl;
}