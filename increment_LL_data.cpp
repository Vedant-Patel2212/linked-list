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

node* reverse(node* head){
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
    return head;
}

int main() {
    int n;
    cout << "Enter the size of Linked List: ";
    cin >> n;
    if(n == 0){
    cout << "Empty List" << endl;
    return 0;
    }
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

    head = reverse(head);

    node* prev = nullptr;
    int cf = 1;
    node* temp = head;
    while(temp != nullptr){
        int sum = temp->data + cf;
        temp->data = sum % 10;
        cf = sum / 10;
        prev = temp;
        temp = temp->next;
    }
    if(cf){
        prev->next = new node(cf);
    }

    head = reverse(head);

    node* rev = head;
    while(rev != nullptr){
        cout<<rev->data<<" ";
        rev = rev->next;
    }
    return 0;
}