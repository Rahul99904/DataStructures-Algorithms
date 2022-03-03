
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int arr[100];
int cc;
int a;
int n;
int y;
string aa;
int d;
string z;
int qq;
int intrarr[100];
int q;
int intarrtd[20][20];
int p = 0;
int we;
int zz;


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
        y = arr[0];
        for (int i = 1;i < n;i++) {
            if (y < arr[i]) {
                y = arr[i];
            }
        }
        cout << y << "max" << "\n";

        aa = to_string(y);
        d = aa.length();
        cout << d << "d value" << "\n";

        for (int i = 0; i < n;i++) {
            z = to_string(arr[i]);
            qq = z.length();
            if (qq < d) {
                int m = d - qq;
                for (int j = 0; j < m;j++) {
                    z = "0" + z;
                }
            }
            intrarr[i] = stoi(z);
            cout << intrarr[i] << "Intarray" << i << "\n";
        }

        //int lk = d - 1;
        string gf = "1";
        for (int i = 0;i < d;i++) {
            if (i > 0) {
            gf = gf + "0";
             we = stoi(gf);
            }
            for (int y = 0;y < n;y++) {
                q = 0;
                if (i == 0) {
                    zz = intrarr[y] % 10;
                }

                if ( i == 1) {
                     zz= (intrarr[y]/we) % 10;
                }
                
                if (i == 2) {
                    zz = (intrarr[y] / we) % 10;
                }

                if(i==3){
                    zz = intrarr[y]/we;
                }
                
                cout << zz << "ZZ" << "\n";
                while (intarrtd[zz][q] != NULL) {
                    q = q + 1;
                }
                intarrtd[zz][q] = intrarr[y];
                cout << intarrtd[zz][q] << "check1" << "\n";

            }
            cout << "PASS" << i + 1 << "\n";

            for (int i = 0;i < 20;i++) {
                for (int j = 0;j < 20;j++) {
                     if (intarrtd[i][j] != NULL) {
                         intrarr[p] = intarrtd[i][j];
                         p = p + 1;
                        cout << intarrtd[i][j]<<i<<j<<"\n";
                    }


                }
            }

            p = 0;

            //lk = lk - 1;
            for (int i = 0;i < 20;i++) {
                for (int j = 0;j < 20;j++) {
                    intarrtd[i][j] = NULL;
                }
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
