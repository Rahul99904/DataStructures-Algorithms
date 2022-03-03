#include<iostream>
#include<stdio.h>
#include <vector>
#include <utility>

using namespace std;

class strssAlgo {
public:

    void dispVect(vector<vector<int>> vect) {
        cout << "\n+++++++++++++++++++++++\n  ";
        for (int i = 0; i < vect.size(); i++) {
            
        }
        for (int i = 0; i < vect.size(); i++)
        {
            cout << "\n " ;

            for (int j = 0; j < vect[i].size(); j++)
            {
                cout << " | " << vect[i][j];
            }
        }
    }

    pair< vector<vector<int>>, vector<vector<int>>  > initialVect(vector<vector<int>> arr, int l, int h) {

        vector<vector<int>> a;
        vector<vector<int>> b;

        for (int i = l; i < h; i++) {
            vector<int> row;
            vector<int> row1;
            for (int j = l; j < h; j++) {
                row.push_back(arr[i][j]);
                if (l == 0) {
                    row1.push_back(arr[i + l][j + h]);
                }
                else {
                    row1.push_back(arr[i][j - l]);
                }
            }
            a.push_back(row);
            b.push_back(row1);
        }
        return make_pair(a, b);
    }

    pair<pair< vector<vector<int>>, vector<vector<int>>  >, pair< vector<vector<int>>, vector<vector<int>>  >  > Split(vector<vector<int>> arr, int n) {
     
        auto ret_ab = initialVect(arr, 0, n / 2);
        auto ret_cd = initialVect(arr, n / 2, n);

        vector<vector<int>> a = ret_ab.first;
        vector<vector<int>> b = ret_ab.second;

        vector<vector<int>> d = ret_cd.first;
        vector<vector<int>> c = ret_cd.second;

        return make_pair(make_pair(a, b), make_pair(c, d));
    }

    vector<vector<int>> comb(vector<vector<int>> a, vector<vector<int>> b, vector<vector<int>> c, vector<vector<int>> d) {
        vector<vector<int>> res;
        for (int i = 0; i < a.size(); i++) {
            vector<int> row;
            for (int j = 0; j < a.size(); j++) {
                row.push_back(a[i][j]);
            }
            res.push_back(row);
        }
        for (int i = 0; i < c.size(); i++) {
            vector<int> row;
            for (int j = 0; j < c.size(); j++) {
                row.push_back(c[i][j]);
            }
            res.push_back(row);
        }
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                res[i].push_back(b[i][j]);
            }
        }
        for (int i = 0; i < c.size(); i++) {
            for (int j = 0; j < c.size(); j++) {
                res[a.size() + i].push_back(d[i][j]);
            }
        }
        return res;
    }

    vector<vector<int>> add(vector<vector<int>> x, vector<vector<int>> y) {
        vector<vector<int>> res;
        for (int i = 0; i < x.size(); i++) {
            vector<int> row;
            for (int j = 0; j < x.size(); j++) {
                row.push_back(x[i][j] + y[i][j]);
            }
            res.push_back(row);
        }
        return res;
    }

    vector<vector<int>> Sub(vector<vector<int>> x, vector<vector<int>> y) {
        vector<vector<int>> res;
        for (int i = 0; i < x.size(); i++) {
            vector<int> row;
            for (int j = 0; j < x.size(); j++) {
                row.push_back(x[i][j] - y[i][j]);
            }
            res.push_back(row);
        }
        return res;
    }

    vector<vector<int>> strss(vector<vector<int>> x, vector<vector<int>> y) {
        vector<vector<int>> res;

        if (x.size() == 1)
        {
            vector<int> row;
            row.push_back((x[0][0] * y[0][0]));
            res.push_back(row);
            return res;
        }
        else {
            vector<vector<int>> a, b, c, d, e, f, g, h;
            vector<vector<int>> p1, p2, p3, p4, p5, p6, p7;
            vector<vector<int>> c11, c12, c21, c22;
            auto ret = Split(x, x.size());
            a = ret.first.first;
            b = ret.first.second;
            c = ret.second.first;
            d = ret.second.second;

            auto ret1 = Split(y, y.size());
            e = ret1.first.first;
            f = ret1.first.second;
            g = ret1.second.first;
            h = ret1.second.second;

            
            p1 = strss(a, Sub(f, h));
            p2 = strss(add(a, b), h);
            p3 = strss(add(c, d), e);
            p4 = strss(d, Sub(g, e));
            p5 = strss(add(a, d), add(e, h));
            p6 = strss(Sub(b, d), add(g, h));
            p7 = strss(Sub(a, c), add(e, f));

          
            c11 = Sub(add(add(p5, p4), p6), p2);
            c12 = add(p1, p2);
            c21 = add(p3, p4);
            c22 = Sub(Sub(add(p1, p5), p3), p7);

            res = comb(c11, c12, c21, c22);
            return res;
        }

    }
};

int main() {
    strssAlgo pa;

    //vector<vector<int>> x = { {5,2,6,1} , {0,6,2,0} , {3,8,1,4} , {1,8,5,6} };
    //vector<vector<int>> y = { {7,5,8,0} , {1,8,2,6} , {9,4,3,8} , {5,3,7,9} };

    vector<vector<int>> x = {{1,1,1,1,1,1,1,1} ,{1,1,1,1,1,1,1,1} ,{1,1,1,1,1,1,1,1} , {1,1,1,1,1,1,1,1} , {1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1} };
    vector<vector<int>> y = {{2,2,2,2,2,2,2,2} ,{2,2,2,2,2,2,2,2} ,{2,2,2,2,2,2,2,2} , {2,2,2,2,2,2,2,2} , {2,2,2,2,2,2,2,2}, {2,2,2,2,2,2,2,2}, {2,2,2,2,2,2,2,2}, {2,2,2,2,2,2,2,2} };
    
    pa.dispVect(x);
    pa.dispVect(y);

    vector<vector<int>> r = pa.strss(x, y);
    pa.dispVect(r);
    return 0;

}
