

#include <iostream>
# include <string>
using namespace std;

string a;
char strarr[100];
char stkarr[100];
char arrst[100];
int top = -1;
int topA = -1;
int len;
int ccs=0;
string h ;
int y;
int z;


int o;
int pos;

int kk;
int posb;

class test
{
public:

	void  con() {
		h = a + ")";
		
	}


	
	void convert() {

		len = h.length();
		for (int i = 0;i < len;i++) {
			strarr[i] = h[i];
		}
	}

	void firstbr() {
		top = top + 1;
		stkarr[top] = '(';
	}


	void testss() {
		
		for (int i = 0; i < len; i++) {
				
			if (strarr[i] == '(') {
				top = top + 1;
				stkarr[top] = strarr[i];
			
			}
			else {
				
				if (strarr[i] != '+' && strarr[i] != '-' && strarr[i] != '*' && strarr[i] != '/' && strarr[i] != ')') {
				
					topA = topA + 1;
					arrst[topA] = strarr[i];
					//cout << topA;
					//cout << arrst[topA] << "\n";
				}
			}

			if (strarr[i] == '+' or strarr[i] == '-' or strarr[i] == '*' or strarr[i] == '/' ) {
				
				if (stkarr[top] == '+' || stkarr[top] == '-' || stkarr[top] == '*' || stkarr[top] == '/') {


					for (int t = 0;t <= top;t++) {

						if (stkarr[t] == '(') {
							kk = t;
						}
					}

					posb = top - kk;


					for (int u = 0; u < posb; u++) {

						if (strarr[i] == '-') {
							y = 2;
						}
						else {}

						if (strarr[i] == '+') {
							y = 3;
						}
						else {}

						if (strarr[i] == '*') {
							y = 5;
						}
						else {}

						if (strarr[i] == '/') {
							y = 4;
						}
						else {}

						if (stkarr[top] == '-') {
							z = 2;
						}
						else {}

						if (stkarr[top] == '+') {
							z = 3;
						}
						else {}

						if (stkarr[top] == '*') {
							z = 5;
						}
						else {}

						if (stkarr[top] == '/') {
							z = 4;
						}
						else {}

						if (y < z /*|| y==z*/) {

							topA = topA + 1;
							arrst[topA] = stkarr[top];
							top = top - 1;
							//top = top + 1;
							//stkarr[top] = strarr[i];
							if (stkarr[top] == '(') {
								top = top + 1;
								stkarr[top] = strarr[i];
							}
						}
						else
						{
							if (ccs == 0) {
								top = top + 1;
								stkarr[top] = strarr[i];
								ccs = ccs + 1;
							}
							
						}



					}
					ccs = 0;

					
				}
				else
				{
					top = top + 1;
					stkarr[top] = strarr[i];
					//cout << top;
					//cout << stkarr[top] << "not pl" << "\n";
				}
			}
			else{}


			if (strarr[i] == ')') {
					
				for (int j = 0; j <= top;j++) {
					
					if (stkarr[j] == '(') {
							
						o = j;
					}
				}

				pos = top - o;

				for (int h = 0;h <=pos;h++) {

					if (stkarr[top] == '(') {
							
						//cout << top;
						//cout << stkarr[top] << "\n";
						top = top - 1;
						//cout << "( execite"<<"\n" << "\n" << "\n";
					}
					else {
						
						topA = topA + 1;
						//cout << topA;
						arrst[topA] = stkarr[top];
						//cout << arrst[topA] << "\n";
						top = top - 1;

					}
				} 
			}


		}
		cout << "\n" << "POSTFIX Expression is" << "\n" << "\n";
	
	}

	void display() {
		for (int f = 0;f <= topA; f++) {
			
			cout  <<arrst[f];
		}
		cout << "\n";
	}

};


int main()
{
	test t;
	t.firstbr();
	cout << "Enter the infix expression"<<"\n";
	cin >> a;
	t.con();
	t.convert();
	t.testss();
	t.display();
}

