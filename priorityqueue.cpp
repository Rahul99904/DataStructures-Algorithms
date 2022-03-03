
#include <iostream>
using namespace std;

int len;
int front;
char quearr[100];
char querarr[100];
int rear;
int h=0;
int cc;
char ele;
int a=0;
int pri;

class test {

public:

    void initialize() {

        cout << "Enter the no of elements " << "\n";
        cin >> len;
        front = 0;
        rear = -1;
    }

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform 1:enque 2:deque 3:priority 4:display 5:exit" << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                priority();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 5);
    }

    void enque() {

        if (rear == len - 1) {

            cout << "Overflow Occured.. :(" << "\n";
        }
        else {

            cout << "Enter the element" << "\n";
            cin >> ele;
            rear = rear + 1;
            quearr[rear] = ele;
            cout << rear + 1 << " " << "Element inserted" << "\n";

        }

    }

    void priority() {
        
        if (h > rear) {
            cout << "Enter new element to set the priority";
        }
        else {
        for (int i = h;i <= rear;i++) {
            cout << "set priority for"<<" "<<quearr[i]<<"\n";
            cin >> pri;
            if ((pri-1) > rear) {
                cout << "priority out of range"<<"\n";
                i = i - 1;
            }
            else {
            
                if (querarr[pri - 1] != NULL) {
                    cout << "priority is occupied" << "\n";
                    i = i - 1;
                }
                else {
                    querarr[pri - 1] = quearr[i];
                    
                }
            }
        }
            h = rear+1;
            a = a + 1;
        }
        
    }

    void deque() {

        if (a == 0 || h<=rear) {
            cout << "priority of all elements not set hence can't be retreived" << "\n";
        }
        else {

            if (front > rear) {
                cout << "underflow occured" << "\n";
            }
            else {

                front = front + 1;
                cout <<querarr[ front-1] << " " << " deleted" << "\n";
            }
        }

    }

    void display() {

        if (a == 0 || h<=rear) {
            cout << "priority of all elements not set hence can't be displayed";
        }
        else {

        if (front > rear) {
            cout << "your queue is empty";
        }
        else {

            cout << "Your Priority Queue is" << "\n" << "\n";

            for (int i = front; i <= rear;i++) {
                cout << querarr[i];
            }
        }
        }
    }


};

int main()
{

    test t;
    t.initialize();
    t.menu();

}
