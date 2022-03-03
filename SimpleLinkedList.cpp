
#include <iostream>
#include <malloc.h>
using namespace std;
int cc,value, ele,o,counter,countss,ct=0;

struct node
{
    int data;
    struct node  *next;
}*list=NULL,*p,*q,*h,*x,*z;

class test {

public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform"<<"\n"<< " 1:insertb" << "\n"<<" 2:insertr" << "\n" << " 3:insertap " << "\n" << " 4:insertbp " << "\n" << " 5:deleter " << "\n" << " 6:deleteb " << "\n" << " 7:deletep " << "\n" << " 8:sort " << "\n" << " 9:count " << "\n" << " 10:search " << "\n" << " 11:reverse " << "\n" << " 12:display " << "\n" << " 13:exit" << "\n";
            cin >> cc;

            switch (cc)
            {
            case 1:
                insertb();
                break;
            case 2:
                insertr();
                break;
            case 3:
                insertap();
                break;
            case 4:
                insertbp();
                break;
            case 5:
                deleter();
                break;
            case 6:
                deleteb();
                break;
            case 7:
                deletep();
                break;
            case 8:
                sort();
                break;
            case 9:
                count();
                break;
            case 10:
                search();
                break;
            case 11:
                reverse();
                break;
            case 12:
                display();
                break;
            case 13:
                break;
            default:
                cout << "Invalid input" << "\n";
                break;
            }
        } while (cc != 13);
    }

    void insertb() {
        p = (struct node*)malloc(sizeof(node));
        cout << "enter the value u want to insert"<<"\n";
        cin >> value;
        p->data = value;
        if (list == NULL) {
            p->next = NULL;
            list = p;
        }
        else {
            p->next = list;
            list = p;
        }
    
    }

    void insertr() {
        p = (struct node*)malloc(sizeof(node));
        cout << "enter the value tobe inserted" << "\n";
        cin >> value;
        p->data = value;
        if (list == NULL) {
            p->next = NULL;
            list = p;
        }
        else {
            q = list;
            while (q->next != NULL) {
                q = q->next;
            }

            q->next = p;
            p->next = NULL;

        }

    }


    void insertap() {
        
        if (list == NULL) {
            cout << "List is empty" << "\n";
        }
        else {
            cout << "enter the element after which u want to insert" << "\n";
            cin >> ele;
            q = list;
            while (q->data != ele && q->next != NULL) {

                q = q->next;
            }


            if (q->data == ele) {
                p = (struct node*)malloc(sizeof(node));
                cout << "enter the value tobe inserted" << "\n";
                cin >> value;
                p->data = value;
                p->next = q->next;
                q->next = p;
            }
            else {
                cout << "There is no such element" << "\n";
            }
        }
    }

    void insertbp() {

        if (list == NULL) {
            cout << "List is empty" << "\n";
        }
        else {
            cout << "enter the element before which u want to insert" << "\n";
            cin >> ele;
            q = list;
            while (q->data != ele && q->next != NULL) {
            
                h = q;
                q = q->next;
            }


            if (q->data == ele) {
                p = (struct node*)malloc(sizeof(node));
                cout << "enter the value tobe inserted" << "\n";
                cin >> value;
                p->data = value;
                if (q == list) {
                    p->next = q;
                    list = p;
                }
                else {
                h->next = p;
                p->next = q;
                }
                
            }
            else {
                cout << "There is no such element" << "\n";
            }
        }
    }

    void deleter() {
        if (list == NULL) {
            cout << "no elemnts in list";
        }
        else {
            q = list;
            while ( q->next != NULL) {

                h = q;
                q = q->next;
            }
            if (q->next == NULL) {
                if (q == list) {
                    list = NULL;
                    cout << "ALL elements deleted";
                    free(q);
                }
                else {
                h->next = NULL;
                free(q);
                cout << "Element deleted" << "\n";
                }
            }
        }
    }

    void deleteb() {
        if (list == NULL) {
            cout << "Empty list";
        }
        else {
            q = list;
            if (q->next == NULL) {
                list = NULL;
                cout << "All Elements are deleted";
                free(q);
            }
            else {
                list = q->next;
                free(q);
            cout << "element deleted";
            }
        }
    }

    void deletep() {
            
        if (list == NULL) {
            cout << "List is empty" << "\n";
        }
        else {
            cout << "enter the element  which u want to delete" << "\n";
            cin >> ele;
            q = list;
            while (q->data != ele && q->next != NULL) {

                h = q;
                q = q->next;
            }

            if (q->data != ele && q->next == NULL) {
                cout << "There is no such element";
            }

            if (q->data == ele && q->next == NULL) {
                if (q == list) {
                    list = NULL;
                    cout << "All elements are deleted";
                    free(q);
                }
                else {
                    h->next = NULL;
                    free(q);
                    cout << "Element deleted";
                }
            }

            if (q->data == ele && q->next != NULL) {
                if (q == list) {
                    list = q->next;
                    free(q);
                    cout << "Element deleted";
                }
                else {
                    h->next = q->next;
                    free(q);
                    cout << "Element deleted";
                }
            }
        }

    
    }

    void display() {
        
        q = list;
        if (list == NULL) {
            cout << "No elements"<<"\n";
        }
        else {
        while (q->next != NULL) {
            cout << q->data<<"-->";
            q = q->next;
        }
        if (q->next == NULL) {
            cout << q->data;
        }
        }
    
    }

    void sort() {
        if (list == NULL) {
            cout << "No elements to be sorted";
        }
        else {
        q = list;
        x = q->next;

        while (q->next != NULL) {
            if (q->data > x->data) {
                o = x->data;
                x->data = q->data;
                q->data = o;
                x = x->next;
            }
            else {
                x = x->next;
            }
            if (x == NULL) {
                q = q->next;
                x = q->next;
            }
        }

        cout << "elements sorted";
        }
    
    }

    void count() {
        counter = 0;
        if (list == NULL) {
            cout << "No elements in list"<<"\n";
        }
        else {    
            q = list;
            counter = 1;
            while (q->next != NULL) {
                counter = counter + 1;
                q = q->next;
            }
        }
        cout << "count is" << counter<<"\n";
        ct = 1;
    }

    void search() {
        if (list == NULL) {
            cout << "Empty list"<<"\n";
        }
        else {
            cout << "enter the element tobe searched" << "\n";
            cin >> ele;
            q = list;
            counter = 1;
            while (q->data != ele && q->next!=NULL) {
                counter = counter + 1;
                q = q->next;
            }

            if (q->data == ele) {
                cout << q->data <<" "<< "element found at position" <<" "<< counter << "\n";
            }
            else {
                cout << "there is no such element"<<"\n";
            }

        }
        
    }

    void reverse() {
        if (list == NULL) {
            cout << "No elements in list";
        }
        
       else{

            q = list;
            counter = 1;
            while (q->next != NULL) {
                counter = counter + 1;
                q = q->next;
            }

            if (counter == 1) {
                cout << "one element cant be reversed";
            }
            else {
            
            countss = 0;

            for (int i = 0; i < counter;i++) {
                q = list;
                while (q->next != NULL) {
                    h = q;
                    q = q->next;
                }
                countss = countss + 1;
                q->next = h;
                if (countss == 1) {
                    z = q;
                }
                h->next = NULL;
                
                
            }
            
            list = z;
            cout << "Reverse Done" << "\n";
            }
       }

            
        
        
    }

   

   


};

int main()
{

    test t;
    t.menu();

}
