#include <iostream>
#include <vector>

using namespace std;

class node
{
    public: node * prev;
    int data;
    node * next;

    node(node * p, int d, node * n)
    {
        prev = p;
        data = d;
        next = n;
    }
};

node * revers(node * head) {
    node* temp = nullptr;
    node* i = head;
    while (i != nullptr) {
        temp = i->next;
        i->next = i->prev;
        i->prev = temp;
        head = i;
        i = i->prev;
    }
    return head;
}
int main() {
    int n;
    cout << "Enter the size of the Linked list";
    cin >> n;
    vector < int > arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node * head = new node(nullptr, arr[0], nullptr);
    node * tail = head;
    for (int i = 1; i < n; i++)
    {
        node * n = new node(tail, arr[i], nullptr);
        tail -> next = n;
        tail = n;
    }
    head = revers(head);
    node* temp = head;
    while (temp != nullptr)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    return 0;
}