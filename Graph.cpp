
#include <iostream>
using namespace std;

int arr[50][50];
int que[50];
int arry[50];
int arryd[50];
int stk[50];
int ny=0;
int top = -1;;
int ik;
int ii;
int z;
int m;
int k=0;
int t = 0;
int cc;
int n;
int first=0;
int a;
int rear = -1;
int front = 0;

class test {

public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform" << "\n" << " 1:Adjacent_Matrix" << "\n" << " 2:BFS" << "\n" << " 3:DFS " << "\n" << " 4:EXIT " << "\n" << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                Adjacent_Matrix();
                break;
            case 2:
                BFS();
                break;
            case 3:
                DFS();
                break;

            case 4:
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
                cout << "Edge between--->" << i << j<<"\n";
                cin >> a;
                arr[i][j] = a;
            }
        }
    }

    void BFS() {
        cout << "\n"<<"\n";
         ii = first;
        rear = rear + 1;
        que[rear] = ii;

        while (front <= rear) {
            for (int j = 0;j < n;j++) {
                if (arr[ii][j] == 1) {
                    z = 0;
                    while (que[z] != j && z <= rear) {
                        z = z + 1;
                    }

                    m = 0;
                    while (arry[m] != j && arry[m]!= NULL ) {
                        m = m + 1;
                    }

                    if (z > rear) {
                        if (arry[m]==NULL) {
                            rear = rear + 1;
                            que[rear] = j;
                        }
                    }
                }
                
            }

            arry[k] = que[front];
            front = front + 1;
            ii = que[front];
            k = k + 1;
        }

        cout << "The BFS is as follows-->" << "\n" << "\n";

        for (int i = 0;i < n;i++) {
            cout << arry[i] ;
        }
        cout << "\n" << "\n";
    
    }

    void DFS() {
        cout << "\n" << "\n";
        ik = first;
        top = top + 1;
        stk[top] = ik;

        for (int y = 0;y < n;y++) {
            ik = stk[top];
            arryd[t] = stk[top];
            top = top - 1;
            t = t + 1;

            for (int j = 0;j < n;j++) {
                if (arr[ik][j] == 1) {

                    z = 0;
                    while (stk[z] != j && z <= top) {
                        z = z + 1;
                    }
                    
                    m = 0;
                    while (arryd[m] != j ) {
                        m = m + 1;
                        if (arryd[m] == NULL) {
                            ny = 1;
                            break;
                        }
                    }

                    if (z > top) {

                        if (ny==1 ) {
                            top = top + 1;
                            stk[top] = j;
                            
                        }
                    }
                }
                ny = 0;
            }
        }

        cout << "The DFS is as follows-->" << "\n" << "\n";

        for (int i = 0;i < n;i++) {
            cout << arryd[i];
        }
        cout << "\n" << "\n";

    }

    


 };

int main()
{

    test t;
    cout << "Eneter the no of node u want to create" << "\n";
    cin >> n;
    t.menu();

}
