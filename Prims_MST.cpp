// Prims_MST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int n;
int aaa;
int arr[50][50];
int a = 0;
int ii;
int jj;
int ai;
int aj;
int cnt;
int arrind[50];
int t = 0;
int dbl;

class test {
public:
	void Adjacent_Matrix() {
		for (int i = 1;i <=n;i++) {
			for (int j = 1;j <=n;j++) {
				cout << "Edge between--->" << i << j << "\n";
				cin >> aaa;
				arr[i][j] = aaa;
			}
		}

		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (arr[i][j] != 0) {
					if (a == 0) {
						a = arr[i][j];
						ii = i;
						jj = j;
					}
					else {
						if (arr[i][j] < a) {
							a = arr[i][j];
							ii = i;
							jj = j;

						}
					}
				}
			}
		}

		

		cnt = cnt + a;
		arrind[t] = ii;
		t = t + 1;
		arrind[t] = jj;

		cout <<"\n"<< "Node---" << ii << "," << jj << "\n";

		
		while (t != (n - 1)) {
			int aa = 0;
			for (int i = 0;i < n;i++) {
				if (arrind[i] != 0) {
					int g = arrind[i];
				
					for (int j = 1;j <= n;j++) {
						dbl = 0;
						for (int s = 0;s < n;s++) {
							if (arrind[s] == j) {
								dbl = 1;
							}
						}

						if (dbl == 0) {
							
							if (arr[g][j] != 0) {
								if (aa == 0) {
									aa = arr[g][j];
									ai = g;
									aj = j;
									
								}
								else {
									if (arr[g][j] < aa) {
										aa = arr[g][j];
										ai = g;
										aj = j;
										
									}
								}
							}
						}
					}
				}
			}

			cnt= cnt + aa;
			cout << "Node---" << ai << "," << aj << "\n";
			

			int avai_i = 0;
			int avai_j = 0;
			for (int i = 0;i < n;i++) {
				if (arrind[i] == ai) {
					avai_i = 1;
				}
				if (arrind[i] == aj) {
					avai_j = 1;
				}
			}

			if (avai_i != 1) {
				t = t + 1;
				arrind[t] = ai;
			}
			if (avai_j != 1) {
				t = t + 1;
				arrind[t] = aj;
			}

			
		}

		cout  <<"\n"<< "Total-Cost--" << cnt<<"\n";
		
	}
};

int main()
{
	cout<<"Enter the no of node u want"<<"\n";
	cin >> n;
	test t;
	t.Adjacent_Matrix();
   
}

