#include <iostream>
using namespace std;

class list_element {
    public:
        list_element(int d = 0, list_element* next = nullptr):d(d),next(next) {}
        int d;
        list_element* next;
};
class list {
    public:
        list():head(0),cursor(nullptr){}
        void prepend(int n); //insert at front value n
        int get_element() { return cursor->d; }
        void advance() { cursor = cursor ->next; }
        void print();
    private:
        list_element* head;
        list_element* cursor;
};

void list::prepend(int n) {
    if (head == nullptr) // empty list case
        cursor = head = new list_element(n, head);
    else  // add to front -chain
        head = new list_element(n, head);
}

void list::print() {
    list_element* h = head;
    while(h != nullptr) {  //idiom for chaining
        cout << h->d << " ";
        h = h->next;
    }
    cout << "###" << endl;
}

int main() {
   list a, b;
   a.prepend(9); a.prepend(8);
   cout << "list a " << endl;
   a.print();

   for (int i = 0; i < 40; i++) 
       b.prepend(i*i);

   cout << "list b" << endl;
   b.print();
}
