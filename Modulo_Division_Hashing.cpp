
#include <iostream>
#include <malloc.h>
using namespace std;

int arr[100];
int cc;
int a;
int n;
int countt = 1;

class test {

public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform" << "\n" << " 1:Enter element" << "\n" << " 2:Display" << "\n" << " 3:EXIT " << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                Enter_Element();
                break;
            case 2:
                Display();
                break;


            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 3);
    }

    void Enter_Element() {

        if (countt <= n) {

            cout << "Eneter the Elememt" << "\n";
            cin >> a;

            int b = a % n;

            while (arr[b] != NULL) {
                if (b == n - 1) {
                    b = -1;
                }

                b = b + 1;
            }

            arr[b] = a;

            countt = countt + 1;

        }

        else {
            cout << "You have entered all elements" << "\n";
        }

    }

    void Display() {
        for (int i = 0;i < n;i++) {
            cout << i << "\t" << arr[i] << "\n";
        }
    }

};

int main()
{

    test t;
    cout << "Eneter the no of elements u want to enter" << "\n";
    cin >> n;
    t.menu();

}
