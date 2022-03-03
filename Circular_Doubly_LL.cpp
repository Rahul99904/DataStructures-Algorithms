
#include <iostream>
#include <malloc.h>
using namespace std;
int cc, value, ele, o, counter, countss, ct = 0;

struct node
{
    int data;
    struct node* next, * prev;
}*list = NULL, * p, * q, * h, * x, * z, * fg,*qq;

class test {

public:

    void menu() {

        do {

            cout << "\n" << "Enter the operation want to perform" << "\n" << " 1:insertb" << "\n" << " 2:insertr" << "\n" << " 3:insertap " << "\n" << " 4:insertbp " << "\n" << " 5:deleter " << "\n" << " 6:deleteb " << "\n" << " 7:deletep " << "\n" << " 8:sort " << "\n" << " 9:count " << "\n" << " 10:search " << "\n" << " 11:reverse " << "\n" << " 12:display " << "\n" << " 13:exit" << "\n";
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
        cout << "enter the value u want to insert" << "\n";
        cin >> value;
        p->data = value;
        if (list == NULL) {
            p->next = p;
            p->prev = p;
            list = p;
        }
        else {
            q = list;
            p->next = list;
            q->prev = p;
            while (q->next != list) {
                q = q->next;
            }

            p->prev = q;
            q->next = p;
            list = p;
        }

    }

    void insertr() {
        p = (struct node*)malloc(sizeof(node));
        cout << "enter the value tobe inserted" << "\n";
        cin >> value;
        p->data = value;
        if (list == NULL) {
            p->next = p;
            p->prev = p;
            list = p;
        }
        else {
            q = list;
            while (q->next != list) {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
            p->next = list;

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
            while (q->data != ele && q->next != list) {

                q = q->next;
            }


            if (q->data == ele) {
                p = (struct node*)malloc(sizeof(node));
                cout << "enter the value tobe inserted" << "\n";
                cin >> value;
                p->data = value;
                p->next = q->next;
                p->prev = q;
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
            while (q->data != ele && q->next != list) {

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
                    q->prev = p;
                    while (q->next != list) {
                        q = q->next;
                    }

                    p->prev = q;
                    q->next = p;
                    list = p;
                }
                else {
                    p->prev = h;
                    h->next = p;
                    p->next = q;
                    q->prev = p;
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
            while (q->next != list) {

                h = q;
                q = q->next;
            }
            if (q->next == list) {
                if (q == list) {
                    list = NULL;
                    cout << "ALL elements deleted";
                    free(q);
                }
                else {
                    h->next = list;
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
            qq = list;
            if (q->next == list) {
                list = NULL;
                cout << "All Elements are deleted";
                free(q);
            }
            else {
                while (qq->next != list) {
                    qq = qq->next;
                }
                list = q->next;
                qq->next = list;
                list->prev = qq;
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
            qq = list;
            while (q->data != ele && q->next != list) {

                h = q;
                q = q->next;
            }

            if (q->data != ele && q->next == list) {
                cout << "There is no such element";
            }

            if (q->data == ele && q->next == list) {
                if (q == list) {
                    list = NULL;
                    cout << "All elements are deleted";
                    free(q);
                }
                else {
                    h->next = list;
                    free(q);
                    cout << "Element deleted";
                }
            }

            if (q->data == ele && q->next != list) {
                if (q == list) {
                    while (qq->next != list) {
                        qq = qq->next;
                    }
                    list = q->next;
                    qq->next = list;
                    list->prev = qq;
                    free(q);
                    cout << "element deleted";
                }
                else {
                    h->next = q->next;
                    fg = q->next;
                    fg->prev = h;
                    free(q);
                    cout << "Element deleted";
                }
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

            while (q->next != list) {
                if (q->data > x->data) {
                    o = x->data;
                    x->data = q->data;
                    q->data = o;
                    x = x->next;
                }
                else {
                    x = x->next;
                }
                if (x == list) {
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
            cout << "No elements in list" << "\n";
        }
        else {
            q = list;
            counter = 1;
            while (q->next != list) {
                counter = counter + 1;
                q = q->next;
            }
        }
        cout << "count is" << counter << "\n";
        ct = 1;
    }

    void search() {
        if (list == NULL) {
            cout << "Empty list" << "\n";
        }
        else {
            cout << "enter the element tobe searched" << "\n";
            cin >> ele;
            q = list;
            counter = 1;
            while (q->data != ele && q->next != list) {
                counter = counter + 1;
                q = q->next;
            }

            if (q->data == ele) {
                cout << q->data << " " << "element found at position" << " " << counter << "\n";
            }
            else {
                cout << "there is no such element" << "\n";
            }

        }

    }


    void reverse() {
        if (list == NULL) {
            cout << "No elements in list";
        }

        else {

            q = list;
            counter = 1;
            while (q->next != list) {
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
                    while (q->next != list) {
                        h = q;
                        q = q->next;
                    }
                    countss = countss + 1;
                    q->next = h;
                    h->prev = q;
                    if (countss == 1) {
                        z = q;
                    }
                    if (i != counter - 1) {
                        h->next = list;
                    }


                }

                list = z;
                h->next = list;
                list->prev = h;
                cout << "Reverse Done" << "\n";
            }
        }




    }





    void display() {

        q = list;
        if (list == NULL) {
            cout << "No elements" << "\n";
        }
        else {
            while (q->next != list) {
                cout << q->data;
                q = q->next;
            }
            if (q->next == list) {
                cout << q->data;
            }
        }

    }








};

int main()
{

    test t;
    t.menu();

}
