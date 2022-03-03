
#include <iostream>
using namespace std;

int len;
int front;
char quearr[100];
int rear;
int cc;
char ele;

class test {

public:

	void initialize() {

        cout << "Enter the size of queue"<<"\n";
        cin >> len;
		front = 0;
		rear = -1;
	}

    void menu() {

         do {

            cout <<"\n"<< "Enter the operation u want to perform 1:enque 2:deque 3:display 4:exit" << "\n";
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
                cout << "Invalid input"<<"\n";
                break;
            }
        } while (cc != 4);
    }

    void enque() {

        if(rear==len-1){
            
            cout << "Overflow Occured.. :("<<"\n";
        }
        else {

        cout << "Enter the element"<<"\n";
        cin >> ele;
        rear = rear + 1;
        quearr[rear] = ele;
        cout <<rear+1<<" "<< "Element inserted" << "\n";

        }
    
    }

    void deque() {
        if (front > rear) {
            cout << "underflow occured"<<"\n";
        }
        else{

            front = front + 1;
            cout <<front<<" "<< "element deleted" << "\n";
        }
    
    }

    void display() {

        if (front > rear) {
            cout << "your queue is empty";
        }
        else {

            cout << "Your Queue is" << "\n" << "\n";

            for (int i = front; i <= rear;i++) {
                cout << quearr[i];
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
