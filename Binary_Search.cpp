
#include <iostream>
using namespace std;


int arr[100];
int n;
int a;
int key;
int cc;

class searchh {

public:




    void valuess() {

        cout << "Enter the size of array" << "\n";
        cin >> n;
        cout << "Enterr the values in array" << "\n";
        for (int i = 0; i < n;i++) {
            cin >> a;
            arr[i] = a;
        }

    }

    void binary() {

        for (int i = 0; i < n;i++) {
            int j = i + 1;
            while (j != n) {

                if (arr[i] > arr[j]) {
                    cc = arr[j];
                    arr[j] = arr[i];
                    arr[i] = cc;

                }
                j = j + 1;
            }

        }

        int low = 0;
        int hig = n - 1;
        int mid = (low + hig) / 2;
        cout << "Enterr the element to be searched";
        cin >> key;

        while (arr[mid] != key && low <= hig) {


            if (key > arr[mid]) {
                low = mid + 1;
                hig = n - 1;
                mid = (low + hig) / 2;
            }

            if (key < arr[mid]) {
                hig = mid - 1;
                low = 0;
                mid = (low + hig) / 2;
            }
        }

        if (arr[mid] == key) {
            cout << "Element found  ";
        }
        else {
            cout << "No such element found";
        }


    }

    /*void display() {
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " <<";
        }
    }*/
};

int main()
{
    searchh sc;
    sc.valuess();
    sc.binary();
    //sc.display();

}

