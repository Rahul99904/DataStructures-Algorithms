
#include <iostream>
# include <string>
# include <sstream>

using namespace std;

string a;
string h;
string strarr[100];
int stkarr[100];
int top = -1;
int len;
int ff;
string stra;
int j = 0;
 int countera = 0;
 int counterb = 0;

int aa;
class test
{
public:


	void  con() {
		h = a +","+ ")"+",";

	}

	void convert() {
		len = h.length();
		for (int i = 0;i < len;i++) {
			if (h[i] == ',') {
				strarr[j] = stra;
				//cout << strarr[j] << "\n";
				j = j + 1;
				stra = "";
			}
			else {
				stra = stra + h[i];
			}
		}


	}

	void testss() {



		
		
			for (int i = 0;i < j;i++) {

			if (strarr[i] != "-" && strarr[i] != "+" && strarr[i] != "*" && strarr[i] != "/" && strarr[i] != ")") {


				int ff = stoi(strarr[i]);
				top = top + 1;
				stkarr[top] = ff;
				//cout <<"\n"<< stkarr[i]<<"\n";
			}
			else {
				if (strarr[i] == "-") {
					aa = stkarr[top - 1] - stkarr[top];
					top = top - 1;
					stkarr[top] = aa;

				}
				else {}

				if (strarr[i] == "+") {
					aa = stkarr[top - 1] + stkarr[top];
					top = top - 1;
					stkarr[top] = aa;

				}
				else {}

				if (strarr[i] == "*") {
					aa = stkarr[top - 1] * stkarr[top];
					top = top - 1;
					stkarr[top] = aa;

				}
				else {}

				if (strarr[i] == "/") {
					aa = stkarr[top - 1] / stkarr[top];
					top = top - 1;
					stkarr[top] = aa;

				}
				else {}


				if (strarr[i] == ")") {
					cout << "you have calculation" << "\n";
					cout << stkarr[top];
				}



			}

		}
		
		


	}


};




int main() {

	test t;
	cout << "enter the postfix expression" << "\n";
	cin >> a;
	t.con();
	t.convert();
	t.testss();

}

