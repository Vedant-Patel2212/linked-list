#include<iostream>
#include<vector>

using namespace std;

class node{
  public:
  int data;
  node* next;
  node(int d , node* n = nullptr){
      data = d;
      next = n;
  }
};

int main() {
    int n;
    cout << "Enter the size of Linked List: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    node* head = nullptr;
    node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        node* m = new node(arr[i]);
        if (head == nullptr) {
            head = m;
            tail = m;
        } else {
            tail->next = m;
            tail = m;
        }
    }

    node* prev = nullptr;
    node* temp = head;
    node* nex = head;
    while(temp != nullptr){
        nex = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nex;
    }

    head = prev;

    node* rev = head;
    while(rev != nullptr){
        cout<<rev->data<<" ";
        rev = rev->next;
    }
    return 0;
}