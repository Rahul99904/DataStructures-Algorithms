
#include <iostream>
using namespace std;

int arr[100];
int cc;
int a;
int n=100;
int y;



class test {

public:

    void menu() {

        int lw = 0;
        int uw = n - 1;

        do {

            cout << "\n" << "Enter the operation want to perform" << "\n" << " 1:Enter data" << "\n" << " 2:SORT" << "\n" << " 3:display" << "\n" << " 3:EXIT " << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                Enter_Element();
                break;
            case 2:
                SORT(arr, lw, uw);
                break;
            case 3:
                display();
                break;

            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 4);
    }

    void Enter_Element() {

        for (int i = 0;i < n;i++) {
         
            arr[i] = rand()%100;
        }

    }

    void SORT(int arrr[], int lo, int uo) {

        if (lo < uo) {
            int lc = pivott(arrr, lo, uo);
            SORT(arrr, lo, lc - 1);
            SORT(arrr, lc + 1, uo);
        }


        for (int y = 0;y < n;y++) {
            arr[y] = arrr[y];
        }

    }

    int pivott(int arrr[], int lo, int uo) {

        int piv = arrr[lo];
        int i = lo;
        int j = uo;

        while (i < j) {

            while (arrr[i] <= piv) {
                i++;
            }

            while (arrr[j] > piv) {
                j--;
            }

            if (i < j) {
                int cv = arrr[i];
                arrr[i] = arrr[j];
                arrr[j] = cv;
            }
        }

        int cb = arrr[lo];
        arrr[lo] = arrr[j];
        arrr[j] = cb;

        return j;


    }
    void display() {
        cout << "\n" << "\n";
        for (int i = 0;i < n;i++) {
            cout << arr[i] << "<<";
        }
    }


};

int main()
{

    test t;
    t.menu();

}
