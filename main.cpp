#include "arraylist.h"
#include <iostream>

using namespace std;

int main() {
    //    create a list of type List that uses ArrayList
    List *list = new ArrayList();

    //    ArrayList* list = new ArrayList();
    //    ArrayList list;
    int num;

    char op;
    do {
        cout << "Op: ";
        cin >> op;

        switch (op) {

        case 'a':
            cin >> num;
            list->add(num);
            break;

        case 'r':
            cin >> num;
            list->remove(num);
            break;

        case 'g':
            cin >> num;
            list->get(num);
            break;
        case 'R':
            cin >> num;
            list->removeAll(num);
            break;

        case 's':
            list->_size();
            break;

        case 'p':
            list->print();
            break;

        case 'x':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (op != 'x');

    return 0;
}