
#include <iostream>
using namespace std;


int len;
int front;
char quearr[100];
int rear;
int cc;
int a;
int b;
int countt;
int countA;
char ele;

class test
{
public:


    void initialize() {

        cout << "Enter the size of queue" << "\n";
        cin >> len;
        front = -1;
        rear = -1;
        countt = 0;
        countA = 0;
        a = 0;
        b = 0;
    }

    void menu() {

        do {

            cout << "\n" << "Enter the operation u want to perform 1:enque 2:deque 3:display 4:exit" << "\n";
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
                display();
                break;
            case 4:
                break;
            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 4);
    }


    void enque() {

        if (rear == (len - 1)) {

            if (front >= 0) {

                if (a != b) {
                    if (rear == front) {
                        cout << "Overflow occured";
                    }
                }
                else {
                    a = a + 1;
                    rear = rear - len;
                    cout << "Enter the elemrnt to be inserted" << "\n";
                    cin >> ele;
                    rear = rear + 1;
                    quearr[rear] = ele;
                    cout << "Element inserted" << "\n";
                }
            }
            else {
                cout << "Overflow occured" << "\n";
            }

        }
        else {
            if (a != b) {
                if (rear == front) {
                    cout << "Overflow occured" << "\n";
                }
                else {
                    cout << "Enter the elemrnt to be inserted" << "\n";
                    cin >> ele;
                    rear = rear + 1;
                    quearr[rear] = ele;
                    cout << "Element inserted" << "\n";

                    
                }
            }
            else {

                cout << "Enter the elemrnt to be inserted" << "\n";
                cin >> ele;
                rear = rear + 1;
                quearr[rear] = ele;
                cout << "Element inserted" << "\n";

            }



        }

    }

    void deque() {
        if (front == (len - 1)) {

            if (rear >= 0) {

                if (a == b) {

                    if (front == rear) {
                        cout << "underflow occured";
                    }
                }

                else {


                    b = b + 1;
                    front = front - len;
                    front = front + 1;
                    cout << "Element deleted" << "\n";
                }

            }

            else {
                cout << "Underflow Occured" << "\n";
            }



        }
        else {

            if (a == b) {

                

                if (front == rear) {
                    cout << "Underflow" << "\n";
                }
                else {
                    
                    front = front + 1;
                    cout << "Element deleted" << "\n";
                }
            }
            else {
                front = front + 1;
                cout << "Element deleted" << "\n";
            }





            


        }

    }


    void display() {

        if (a != b) {

            for (int i = front + 1;i < len;i++) {
                cout << quearr[i];
            }
            for (int j = 0;j <= rear;j++) {
                cout << quearr[j];
            }
        }
        else {

            if (a == b && front == rear) {
                cout << "Empty queue" << "\n";
            }
            else {
                for (int y = front + 1;y <= rear;y++) {
                    cout << quearr[y];
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
