
#include <iostream>
using namespace std;

int arr[50][50];
int arry[50][2];
int arrchk[50];
int arrres[50];
int arrsrt[50];
int rr = 0;
int ny = 0;
int aa;
int cc;
int n;
int ll = 0;


class test {

public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform" << "\n" << " 1:Adjacent_Matrix" << "\n" << " 2:DJ"  << "\n" << " 4:EXIT " << "\n" << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                Adjacent_Matrix();
                break;
            case 2:
                DJ();
                break;

            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 4);
    }

    void Adjacent_Matrix() {

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                cout << "Edge between--->" << i << j << "\n";
                cin >> aa;
                arr[i][j] = aa;
            }
        }
    }
    
    void DJ() {
        arry[0][0] = 0;
        arry[0][1] = 0;

        for (int i = 1;i < n;i++) {
            arry[i][1] = 1000;
        }
        int i = 0;
        while(i != n-1) {
            for (int j = 0;j < n;j++) {
                if (arr[i][j] > 0) {
                    int z = 0;
                    while (arrchk[z] != j) {
                        z = z + 1;
                        if (arrchk[z] == NULL) {
                            ny = 1;
                            break;
                        }
                    }

                    if (ny==1 ) {
                        int a = arry[i][1] + arr[i][j];
                        cout << "a--" << a << "\n";
                        if (a < arry[j][1]) {
                            arry[j][0] = i;
                            arry[j][1] = a;
                            cout <<j<<"0"<<"--"<< arry[j][0] << "  " <<j<<"1--"<< arry[j][1]<<"\n";
                            
                        }
                    }
                    ny = 0;
                }
            }
            /*int m = arry[1][1];
            int k = 1;
            for (int h = 2;h < n ;h++) {
                if (arry[h][1] < m) {
                    m = arry[h][1];
                    k = h;
                }
            }*/

            int p = 0;
            for (int u = 1;u < n;u++) {
                arrsrt[p] = arry[u][1];
                p = p + 1;
            }

            for (int d = 0;d < n-2;d++) {
                for (int f = d + 1;f < n-1;f++) {
                    if (arrsrt[f] < arrsrt[d]) {
                        int tt = arrsrt[f];
                        arrsrt[f] = arrsrt[d];
                        arrsrt[d] = tt;
                    }
                }
            }

            for (int vv = 0;vv < n;vv++) {
                cout << vv << "--" << arrsrt[vv]<<"\n";
            }

            int min = arrsrt[rr];
            cout << "Min--" << min << "\n";
            rr = rr + 1;

            int x = 0;
            while (arry[x][1] != min) {
                x = x + 1;
            }

            int minidx = x;

            arrchk[ll] = i;
            cout << "chk---" << arrchk[ll]<<"\n";
            ll = ll + 1;
            i = minidx;
            cout << "MINI" << i<<"\n";

           
        }

        arrres[0] = n - 1;
        int mm = n - 1;
        int ik = 1;

        while (mm != 0) {
            int zy = arry[mm][0];
            arrres[ik] = zy;
            cout << ik << "arres--" << arrres[ik] << "\n";
            ik = ik + 1;
            mm = zy;
        }

        for (int o = n-1;o >=0;o--) {
            if (arrres[o] != NULL) {
                cout<<"SHORTEST_PATH-->"<<o<<"--"<<arrres[o]<<"\n";
            }
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
