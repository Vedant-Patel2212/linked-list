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

node* odd_even(node* head){
    if(head == nullptr || head->next == NULL){
        return head;
    }
    node* odd = head;
    node* even = head->next;
    node* evenHead = even;
    while(even != nullptr && even->next != nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main(){
    int n;
    cout<<"Enter the size of the Linked List: ";
    cin>>n;
    
    vector<int> arr(n);
    
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    
    node* head = new node(arr[0]);
    node* tail = head;

    for(int i = 1 ; i < arr.size() ; i++){
        node* n = new node(arr[i]);
        tail->next = n;
        tail = n;
    }
    
    head = odd_even(head);
    node* temp = head;
    
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}