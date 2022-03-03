
#include <iostream>
#include <malloc.h>
#include <sstream>
# include <string>
using namespace std;

string arr[20000];
int arras[20000];
int cc;
string ccc;
int na;
int aba;
string dd;
//string a;
string key;
string jp;
int bnn;
int aaa;
int nn;
int n;
int l;
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

            
            nn = ccc.length();
            

            cout << "Enter the key"<<"\n";
            cin >> key;
            
            l = key.length();
            if (l % nn == 0) {
                
            }
            else {
                int y =  l % nn;
                int z = nn - y;
                for (int i = 0;i < z;i++) {
                    key = "0" + key;
                }
            }

            int aa = key.length();
            int jj = aa / nn;

            int h = 0;
            int xx = 0;

            while (h != jj) {
                for (int i = 0;i < nn;i++) {
                     jp = jp + key[xx];
                    xx = xx + 1;
                }
                if (nn != 1) {
                    if ((h == 0) || (h == (jj - 1))) {
                        for (int i = 0; i < nn / 2;i++) {
                            swap(jp[i], jp[nn - i - 1]);
                        }
                    }
                }

                arr[h] = jp;
                jp = "";
                h = h + 1;
            }

            for (int i = 0;i < jj;i++) {
                if (i == (jj - 1)) {
                    aaa = aaa + (stoi(arr[i]));
                }
                else {
                aaa = aaa + (stoi(arr[i])) + (stoi(arr[i + 1]));
                }
                i = i + 1;
            }


            dd = to_string(aaa);
            int lal = dd.length();
            if (lal > nn) {
                int er = lal - nn;
                dd.erase(0, er);
                aba = stoi(dd);
            }
            else {
                aba = aaa;
            }

            aaa = 0;

            if (aba > n) {
                bnn = aba % n;
            }
            else {
                bnn = aba;
            }

            while (arras[bnn] != NULL) {
                if (bnn == n - 1) {
                    bnn = -1;
                }
                bnn = bnn + 1;
            }
            
                arras[bnn] = stoi(key);


                countt = countt + 1;
            

        }

        else {
            cout << "You have entered all elements" << "\n";
        }

    }

    void Display() {
        for (int i = 0;i < n;i++) {
            if (arras[i] != 0) {
                    cout<< i << "\t" << arras[i] << "\n";
            }
            //cout << i << "\t" << arras[i] << "\n";
        }
    }

};

int main()
{

    test t;

    cout << "Eneter the Size" << "\n";
    cin >> n;
    //n = stoi(a);
    na = n - 1;
    ccc = to_string(na);
    t.menu();

}
