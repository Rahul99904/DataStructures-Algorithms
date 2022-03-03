
#include <iostream>
#include <malloc.h>
using namespace std;
int ii = 0;
struct node
{
    int i;
    int j;
    int x;
    struct node* next,* prev, *pp;
}*q , *p , *d, *z ,*h , *v;

int n;
int combex = 0;
int pos;
int ttl=0;
int adno;
int yy;
int arrchk[50];
int arr[50];

class test {
public:
    void bt() {
        
        cout << "Enter values "<<"\n";
        for (int d = 0;d < n;d++) {
            cin >> yy;
            arr[d] = yy;
        }

        for (int k = 0;k < n;k++) {
                
            ttl = ttl + arr[k];
        }

        p = (struct node*)malloc(sizeof(node));
        p->i = 0;
        p->j = ttl;
        p->x = 1;
        p->pp = p;
        q = p;

        while (q->i != adno) {

            if (q->i > adno) {
                int prevj = q->j;
                q->x = 0;
                q = q->pp;
                q->x = 0;
                d = (struct node*)malloc(sizeof(node));
                d->i = q->i;
                d->j = prevj;
                d->x = 1;
                d->pp = q;
                q->next = d;
                q = q->next;
                arrchk[ii-1] = 0;

            }
             else if ((q->i +q->j)<adno)
            {
                q->x = 0;
                if (ii >= n - 1) {
                    for(int b = n - 1;b > -1;b--) {
                        if (arrchk[b] == 1) {
                             pos = b;
                             break;
                        }
                    }
                    //if (pos==(n-1)) {
                       // cout << "\n" << "No combination found"<<"\n";
                        //combex = 1;
                        //break ;
                    //}
                    arrchk[pos] = 0;
                    ii = pos + 1;
                }
                while (q->x != 1) {
                    q = q->pp;
                    if (q->i == 0 && q->j == ttl && q->x == 0) {
                         cout << "\n" << "No combination found"<<"\n";
                        combex = 1;
                        break ;
                    }
                }
                h = q->prev;
                q->x = 0;
                z = (struct node*)malloc(sizeof(node));
                z->i = q->i;
                z->j = h->j;
                z->x = 1;
                z->pp = q;
                q->next = z;
                q = q->next;
            }
            else {
                v = (struct node*)malloc(sizeof(node));
                v->i = q->i + arr[ii];
                v->j = q->j - arr[ii];
                v->x = 1;
                arrchk[ii] = 1;
                ii = ii + 1;
                v->pp = q;
                q->prev = v;
                q = v;

            }
        }
        if (combex == 0){
            cout << "\n" << "Total calculated" << "\n";
            cout << q->i<<"\n"<<"\n";
            cout << "The no combination are"<<"\n"<<"\n";
            for(int s = 0;s < n;s++) {
                cout <<arr[s]<<"----"<< arrchk[s]<<"\n";
            }
        }

    }

};

int main()
{
    cout << "Enter no of elements u want to enter"<<"\n";
    cin >> n;
    cout << "Enter the sum u want to calculate"<<"\n";
    cin >> adno;
    
    test t;
    t.bt();
}

