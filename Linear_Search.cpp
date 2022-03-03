
#include <iostream>
using namespace std;


int arr[100];
int n;
int a;
int key;

class searchh {

public:


    

void valuess(){
           
        cout << "Enter the size of array"<<"\n";
        cin >> n;
        cout << "Enterr the values in array"<<"\n";
        for (int i = 0; i < n;i++) {
            cin >> a;
            arr[i] = a;
        }
        
    }
    
void linear() {
        
    cout << "\n" << "Enter the value to be searched"<<"\n";
    cin >> key;

    int i = 0;
    while (arr[i]!=key && i!=n ) {
        i = i + 1;
    }

    if (arr[i] == key) {
        cout << "Element found at position " << i+1 ;
    }
    else {
        cout << "No such element found"<<"\n";
    }

        
    }

     void display() {
         cout << "\n";
         for (int i = 0; i < n; i++) {
             cout << arr[i]<<" <<";
         }
     }
};

int main()
{
    searchh sc;
    sc.valuess();
    sc.linear();
    sc.display();

}

