#include <iostream>
using namespace std;
string fir_strg = "O";
string  fir_strg_1;

string sec_strg = "O";
string  sec_strg_1;
int dp_arr[50][50] = {0};

string res="";

class test {
public:
	void LCS() {
		

		cout << "Enter the 1st string"<<"\n";
		cin >> fir_strg_1;
		fir_strg = fir_strg + fir_strg_1;
		
		cout << "Enter the 2nd string" << "\n";
		cin >> sec_strg_1;
		sec_strg = sec_strg + sec_strg_1;
/*
		for (int i = 0;i < 1;i++) {
			for (int j = 0;j < 50;j++) {
				dp_arr[i][j] = 0;
				dp_arr[j][i] = 0;
			}
		}
*/
		for (int i = 1;i < fir_strg.length();i++) {
			for (int j = 1;j < sec_strg.length();j++) {
				if (fir_strg[i] == sec_strg[j]) {
					dp_arr[i][j] = 1 + dp_arr[i - 1][j - 1];
				}
				else {
					dp_arr[i][j] = (max(dp_arr[i][j - 1], dp_arr[i - 1][j]));
				}
			
			}
		}

		

		
		int q = fir_strg.length() - 1;
		int w = sec_strg.length() - 1;

		//cout << "\n" << dp_arr[q][w];

		while (true) {
			if (w == 0) { break; }
			if (q == 0) { break; }

			if (dp_arr[q][w] != dp_arr[q][w - 1] && dp_arr[q][w] != dp_arr[q - 1][w]) {
				
				res = res + sec_strg[w];
				q = q - 1;
				w = w - 1;
				//cout << "\n" << q;
				//cout << "\n" << w;
			
			}
			else {

				if (dp_arr[q][w] == dp_arr[q][w - 1]) {
					w = w - 1;
					//cout << "\n" << w;
				}
				else {
					q = q - 1;
					//cout << "\n" << q;
				}
			}
		}

		reverse(res.begin(),res.end());
		cout << "\n" <<"Longest Common Subsequence"<< "\n"<<res;
		
	}
};

int main()
{
	test t;
	t.LCS();
}

