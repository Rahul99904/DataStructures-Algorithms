
#include <iostream>
using namespace std;

int arr[50][50];
int aa;
int cc;
int n;
int k = 1;



class test {

public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform" << "\n" << " 1:Adjacent_Matrix" << "\n" << " 2:WAR" << "\n" << " 4:EXIT " << "\n" << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                Adjacent_Matrix();
                break;
            case 2:
                WAR();
                break;

            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 4);
    }

    void Adjacent_Matrix() {

        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                cout << "Edge count  between--->" << i << j << "\n";
                cin >> aa;
                arr[i][j] = aa;
            }
        }
    }

    void WAR() {
        while (k != n + 1) {
            for (int i = 1;i <= n;i++) {
                for (int j = 1;j <= n;j++) {
                    int a = arr[i][k] + arr[k][j];
                    if (a < arr[i][j]) {
                        arr[i][j] = a;
                    }
                }
            }
            k = k + 1;
        }

        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                cout << i  << j << "--->" << arr[i][j]<<"\n";
            }
            cout << "\n";
        }
    }






};

int main()
{

    test t;
    cout << "Eneter the no of node u want to create" << "\n";
    cin >> n;
    t.menu();

}
