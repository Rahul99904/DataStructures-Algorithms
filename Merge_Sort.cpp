
#include <iostream>
using namespace std;

int arr[100];
int cc;
int a;
int n;
int y;
int arry[100];



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
            cout << "Eneter the element " << " " << i + 1 << "\n";
            cin >> a;
            arr[i] = a;
        }

    }

    void SORT(int arrr[], int lo, int uo) {

        if (lo < uo) {
            int mid = (lo + uo) / 2;
            SORT(arrr, lo, mid);
            SORT(arrr, mid + 1, uo);
            MER(arrr, lo, mid, uo);
        }

        
    }

    void MER(int arrr[], int lo, int mid, int uo) {
            
        int i = lo;
        int j = mid + 1;
        int h = lo;

        while (i <= mid && j <= uo) {
            if (arrr[i] <= arrr[j]) {
                arry[h] = arrr[i];
                i++;
            }
            else {
                arry[h] = arrr[j];
                j++;
            }
            h++;
        }

        if (i > mid) {
            while (j<=uo) {
                arry[h] = arrr[j];
                j++;
                h++;
            }
        
        }
        else {
            while (i <= mid) {
                arry[h] = arrr[i];
                i++;
                h++;
            }
        }

        for (int i = lo;i <= uo;i++) {
            arr[i] = arry[i];
        }
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
    cout << "Eneter the no of elements u want to enter" << "\n";
    cin >> n;
    t.menu();

}
