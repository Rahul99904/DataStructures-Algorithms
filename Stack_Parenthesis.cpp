

#include <iostream>
#include <cstring>
using namespace std;



string a;
char arrstck[100];
int len;
int top = -1;
char strarr[100];
int counta = 0;
int countb = 0;



class test
{
public:
	void convert() {

		len = a.length();
		for (int i = 0;i < len;i++) {
			strarr[i] = a[i];
		}
	}

	

	void testee() {

		for (int i = 0;i < len;i++) {

			if (strarr[i] == '(') {
				top = top + 1;
				arrstck[top] = strarr[i];
				counta = counta + 1;
			
			}

			if (strarr[i] == ')') {
				if (top == -1) {
					cout << "Underflow ...Invalid Input ):" << "\n" << "\n";
					countb = countb + 1;
					
				}
				else {

					top = top - 1;
					countb = countb + 1;


				}
			}

		}

		if ( top != -1 or counta!=countb ) {
			cout << "Invalid input ):" << "\n" << "\n";
		}
		else {
			cout << "Valid input (:" << "\n" << "\n";
		}
	}

};



int main()
{
	test t;
	cout << "enter the expression" << "\n" << "\n";
	cin >> a;
	t.convert();
	t.testee();
}

