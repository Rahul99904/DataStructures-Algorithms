
#include <iostream>
#include <malloc.h>
using namespace std;
int cc, n, g=0 , value,lp;
int top;
int topA;
int topB;
int arr[50];
int arrd[50];

struct node
{
    int data;
    struct node  *next;
    struct node  *prev;
}*list=NULL,*p,*q,*b,*x,*z;
struct node* arrsn[50];
struct node* stko[50];
struct node* stkt[50];
struct node* stkin[50];

class test {

public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform"<<"\n"<< " 1:Create_BST" << "\n" << " 2:Preorder"  << "\n" << " 3:Postorder" << "\n" << " 4:Inorder" <<  "\n" << " 5:exit" << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                Create_BST();
                break;
            case 2:
                Preorder();
                break;
            case 3:
                Postorder();
                break;
            case 4:
                Inorder();
                break;
            case 5:
                break;
            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 5);
    }

    void arrs() {
        for (int i = 0;i < n;i++) {
            cout << "Enter the value-->";
            cin >> g;
            arr[i] = g;
        }
    }

    void Create_BST() {
        cout << "\n";
        for (int i = 0;i < n;i++) {
            p = (struct node*)malloc(sizeof(node));

            if (list == NULL) {
                p->data = arr[i];
                p->next = NULL;
                p->prev = NULL;
                list = p;
            }

            else {
                    
                q = list;
                if (arr[i] > q->data) {
                    b = q->next;
                }
                else {
                    b = q->prev;
                }

                while (b != NULL) {
                    if (arr[i] > q->data) {
                        q = q->next;
                    }
                    else {
                        q = q -> prev;
                    }
                    if (arr[i] > q -> data) {
                        b = q->next;
                    }
                    else {
                        b = q->prev;
                    }
                    
                }

                p->data = arr[i];
                if (arr[i] > q->data) {
                    q->next = p;
                    p->next = NULL;
                    p->prev = NULL;
                }
                else {
                    q->prev = p;
                    p->next = NULL;
                    p->prev = NULL;
                }
            }
        }
    
    }

   void Preorder() {
       top = -1;
       cout << "\n";
       q = list;

       if (q->prev == NULL) {
           b = q->next;
       }
       else {
           b = q->prev;
           if (q->next != NULL) {
               top = top + 1;
               arrsn[top] = q->next;
           }
       }

       while (b != NULL) {
           cout << q->data<<"\n";
           q = b;

           while (q->prev == NULL && q->next==NULL) {
               cout << q->data << "\n";
               if (top == -1) {
                   break;
               }
               q = arrsn[top];
               top = top - 1;
           }

           if (q->prev == NULL) {
               b = q->next;
           }
           else {
               b = q->prev;
               if (q->next != NULL) {
                   top = top + 1;
                   arrsn[top] = q->next;
               }
           }
       }
        
    }

   void Postorder() {
       top = -1;
       topA = -1;

       cout << "\n";
       q = list;
       top = top + 1;
       stko[top] = q;

       if (q->next == NULL) {
           b = q->prev;

           topA = topA + 1;
           stkt[topA] = stko[top];
           top = top - 1;

           top = top + 1;
           stko[top] = q->prev;
       }
       else {
           b = q->next;

           topA = topA + 1;
           stkt[topA] = stko[top];
           top = top - 1;

           if (q->prev != NULL) {
               top = top + 1;
               stko[top] = q->prev;
           }

           top = top + 1;
           stko[top] = q->next;
       }

       while (top != -1) {
           q = b;
           topA = topA + 1;
           stkt[topA] = stko[top];
           top = top - 1;

           while (q->prev == NULL && q->next == NULL) {
               if (top == -1) {
                   break;
               }
               q = stko[top];
               topA = topA + 1;
               stkt[topA] = stko[top];
               top = top - 1;
           }

           if (q->prev == NULL && q->next == NULL) {
               break;
           }

           if (q->next == NULL) {
               b = q->prev;

               top = top + 1;
               stko[top] = q->prev;
           }
           else {
               b = q->next;

               if (q->prev != NULL) {
                   top = top + 1;
                   stko[top] = q->prev;
               }

               top = top + 1;
               stko[top] = q->next;
           }

       }

       for (int i = 50; i >= 0;i--) {
           if (stkt[i] != NULL) {
           cout << stkt[i]->data << "\n";
           }
       }
       

   }

   
   void Inorder() {
       topB = -1;
       cout << "\n";
       q = list;
       

       topB = topB + 1;
       stkin[topB] = q;

       while (true) {

            
           if (q->prev == NULL) {
               lp = 1;
           }
           else {
               lp = 0;
               q = q->prev;
               topB = topB + 1;
               stkin[topB] = q;
           }

           while (lp == 1) {
               if (topB == -1) {
                   break;
               }
               q = stkin[topB];
               cout << q->data << "\n";
               topB = topB - 1;
               
               if (q->next == NULL) {
                   lp = 1;
               }
               else {
                   lp = 0;
                   q = q->next;

                   topB = topB + 1;
                   stkin[topB] = q;
               }
           }
           
           if (topB == -1) {
               break;
           }
           
           
           

          
       }

   }


   

   


};

int main()
{    
    cout << "Enterr the no of values u want to insert"<<"\n";
    cin >> n;
    test t;
    t.arrs();
    t.menu();

}
