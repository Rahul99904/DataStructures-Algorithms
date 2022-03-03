
#include <iostream>
using namespace std;

int arr[100];
int cc;
int a;
int n;
int nn;
int inter;
int countt;

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
        inter = 0;
        countt = 0;
        while (inter!=1)
        {
            if (countt == 0) {
                inter = n / 2;
            }
            else {
                inter = inter / 2;
            }

            nn = (n - 1) / inter;

            for (int i = 0;i < n;i++) {
                int k = i;
                for (int j = 0;j < nn;j++) {
                    if ((k + inter) > (n - 1)) {
                        
                    }
                    else {
                        if (arr[i] > arr[k + inter]) {
                            int cy = arr[i];
                            arr[i] = arr[k + inter];
                            arr[k + inter] = cy;
                        }
                    }

                    k = k + inter;
                }
            }
            cout <<"\n"<< "PASS" <<" "<< countt + 1<<"\n";
            for (int f = 0;f < n;f++) {
                cout << arr[f]<<"\n";
            }
            countt = countt + 1;
        }


    }

};

int main()
{

    test t;
    cout << "Eneter the no of elements u want to enter" << "\n";
    cin >> n;
    if (n == 1) {
        cout << "one element cant be sorted";
    }
    else {
     t.menu();
    }
   

}
