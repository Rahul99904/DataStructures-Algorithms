
#include <iostream>
using namespace std;

int arr[100];
int cc;
int a;
int n;
int y;

class test {

public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform" << "\n" << " 1:Enter data" << "\n" << " 2:SORT" << "\n" << " 3:EXIT " << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                Enter_Element();
                break;
            case 2:
                SORT();
                break;


            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 3);
    }

    void Enter_Element() {

        for (int i = 0;i < n;i++) {
            cout << "Eneter the element " << " " << i + 1 << "\n";
            cin >> a;
            arr[i] = a;
        }

    }

    void SORT() {
        for (int i = 0;i < n - 1;i++) {
            for (int j = i+1;j < n ;j++) {
                if (arr[i] > arr[j]) {
                    y = arr[j];
                    arr[j] = arr[i];
                    arr[i] = y;
                }

            }
            cout << "\n" << "PASS" << " " << i + 1 << "\n" << "\n";
            for (int o = 0;o < n;o++) {
                cout << " " << arr[o];
            }
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
