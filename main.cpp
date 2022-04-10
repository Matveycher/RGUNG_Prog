#include <iostream>
struct queue
{
    int info;
    struct queue* nextEl;
};

using namespace std;
void printcase(int);
void instructions();
int main()
{
    int choise;
    instructions();
    cout<<"? ";
    cin>>choise;
    while (choise != 15)
    {
        switch(choise)
        {
            case 1:
                printcase(choise);
                break;
            case 2:
                printcase(choise);
                break;
            case 3:
                printcase(choise);
                break;
            case 4:
                printcase(choise);
                break;
            case 5:
                printcase(choise);
                break;
            case 6:
                printcase(choise);
                break;
            case 7:
                printcase(choise);
                break;
            case 8:
                printcase(choise);
                break;
            case 9:
                printcase(choise);
                break;
            case 10:
                printcase(choise);
                break;
            case 11:
                printcase(choise);
                break;
            case 12:
                printcase(choise);
                break;
            case 13:
                printcase(choise);
                break;
            case 14:
                printcase(choise);
                break;
            default:
                cout<<"invalid choise"<<endl<<endl;
                instructions();
                break;
        }
        cout<<"? ";
        cin>>choise;
    }
    cout<<"end of run."<<endl;
}

void instructions()
{
    cout<<"Enter your choise:"<<endl;
    cout<<"1 to print the conditions of your queue: head element, tail element, length of queue"<<endl;
    cout<<"2 to make a copy of your queue"<<endl;
    cout<<"3 to add an element in the beginning of your queue (wtf?)"<<endl;
    cout<<"4 to add an element in the end of your queue"<<endl;
    cout<<"5 to change the chosen element"<<endl;
    cout<<"6 to delete the chosen element"<<endl;
    cout<<"7 to remove the element and print it"<<endl;
    cout<<"8 to delete the whole queue"<<endl;
    cout<<"9 to print the length of your queue"<<endl;
    cout<<"10 to sort your queue in increasing order"<<endl;
    cout<<"11 to invert your queue"<<endl;
    cout<<"12 to add two queues together"<<endl;
    cout<<"13 to combine two queues"<<endl;
    cout<<"14 to delete the duplicates"<<endl;
    cout<<"15 to end the run"<<endl;
}

void printcase(int choise)
{
    cout<<"case "<<choise<<" is working"<<endl;
}
