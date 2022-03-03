
#include <iostream>
using namespace std;
int cc, n, g , c , a=0 ,k,p,m;
int arr[50];

class test {

 public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform" << "\n" << " 1:Heap_Sort" << "\n" << " 2:exit" << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                Heap_Sort();
                break;
            case 2:
                break;
            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 2);
    }

    void arrs() {
        for (int i = 0;i < n;i++) {
            cout << "Enter the value-->";
            cin >> g;
            arr[i] = g;
        }
    }

    void Heap_Sort() {
        cout << "\n"<<"\n";
        while (n != 1) {
            c = 1;
            for (int i = 0;i < n;i++) {
                for (int j = i + c;j <= i + c + 1;j++) {
                    if (arr[j] > arr[i]) {
                        k = arr[j];
                        arr[j] = arr[i];
                        arr[i] = k;
                    }
                    int q = i;
                    while (q != 0) {
                        int y = 1;
                        int b = 0;
                        int set = 1;

                        while (true) {
                            for (int v = y;v <= y + 1;v++) {
                                if (v == q) {
                                    b = 1;
                                    break;
                                }
                            }
                            if (b == 1) {
                                break;
                            }
                            y = y + 2;
                            set = set + 1;
                        }

                        if (q % 2 == 0) {
                             m = q - set - 1;
                        }
                        else {
                            m = q - set;
                        }
                        
                        if (arr[q] > arr[m]) {
                            int xx = arr[q];
                            arr[q] = arr[m];
                            arr[m] = xx;
                        }
                        q = m;
                    }
                    if (j == n - 1) {
                        a = 1;
                        break;
                    }
                }
                if (a == 1) {
                    break;
                }
                c = c + 1;
                
            }
            a = 0;

            SORTT();
        }
        cout << arr[0] << "\n";

    }

    void SORTT() {

        p = arr[n - 1];
        arr[n - 1] = arr[0];
        arr[0] = p;

        cout << arr[n - 1] << "\n";
        n = n - 1;
    }


};

int main()
{
    cout << "Enterr the no of values u want to insert" << "\n";
    cin >> n;
    test t;
    t.arrs();
    t.menu();

}
