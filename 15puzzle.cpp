// 15puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[4][4] = {{1,2,3,4},{5,6,0,8},{9,10,7,11},{13,14,15,12} };
int au[4][4];
int ad[4][4];
int al[4][4];
int ar[4][4];
class test {
public:

    void up(int aup[4][4]) {
        int chk = 1;
        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                if (aup[i][j] == 0) {
                    if (i == 0) {}
                    else
                    {
                        int tm = aup[i][j];
                        aup[i][j] = aup[i - 1][j];
                        aup[i - 1][j] = tm;
                    }
                    chk = 0;
                    break;
                   
                }
            }
            if (chk == 0) {
                break;
            }
        }

        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                au[i][j] = aup[i][j];

            }
        }
    }

    void down(int adn[4][4]) {
        int chk = 1;
        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                if (adn[i][j] == 0) {
                    if (i == 3) {}
                    else
                    {
                        int tm = adn[i][j];
                        adn[i][j] = adn[i + 1][j];
                        adn[i + 1][j] = tm;
                    }
                    chk = 0;
                    break;
                }
            }
            if (chk == 0) {
                break;
            }
        }

        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                ad[i][j] = adn[i][j];

            }
        }
    }
    
    void left(int alf[4][4]) {
        int chk = 1;
        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                if (alf[i][j] == 0) {
                    if (j == 0) {}
                    else
                    {
                        int tm = alf[i][j];
                        alf[i][j] = alf[i ][j-1];
                        alf[i][j - 1] = 0;
                    }
                    chk = 0;
                    break;
                }
            }
            if (chk == 0) {
                break;
            }
        }

        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                al[i][j] = alf[i][j];

            }
        }
    }


    void right(int art[4][4]) {
        int chk = 1;
        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                if (art[i][j] == 0) {
                    if (j == 3) {}
                    else
                    {
                        int tm = art[i][j];
                        art[i][j] = art[i][j + 1];
                        art[i][j + 1] = 0;
                    }
                    chk = 0;
                    break;
                }
            }
            if (chk == 0) {
                break;
            }
        }
        
        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                ar[i][j] = art[i][j];

            }
        }
    }

    int gapp(int ar_gap[4][4]) {

        int cnt = 1;
        int gap_up = 0;

        for (int i = 0;i < 4;i++) {
            for (int j = 0;j < 4;j++) {
                if (ar_gap[i][j] == 0) {
                    cnt = cnt + 1;
                }
                else {
                    if (i == 3 && j == 3) {
                        if (ar_gap[i][j] != 0) { gap_up = gap_up + 1; }
                    }
                    else {
                        if (ar_gap[i][j] == cnt) {
                            cnt = cnt + 1;
                        }
                        else {
                            gap_up = gap_up + 1;
                            cnt = cnt + 1;
                        }
                    }
                }
            }
        }
        return gap_up;
    }

    void puzzle() {
       
        up(arr);
        down(arr);
        left(arr);
        right(arr);

        cout << "UP----"<<gapp(au)<<"\n";
        cout << "RT----" << gapp(ar) << "\n";
        cout << "DN----" << gapp(ad) << "\n";
        cout << "LF----" << gapp(al) << "\n";

        
        
       

        
        


    }

};

int main()
{
    test t;
   
    t.down(arr);

    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            cout << ad[i][j] << "  ";

        }
        cout << "\n";
    }
    cout << "\n";
    cout << t.gapp(ad);
    cout << "\n";

    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            cout << arr[i][j] << "  ";

        }
        cout << "\n";
    }
    

    /*t.puzzle();*/
    
}
