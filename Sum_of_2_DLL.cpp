#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;
    
    node(node* p , int d , node* n){
        prev = p;
        data = d;
        next = n;
    }
};

node* sum(node* head1 , node* head2){
    node* temp1 = head1;
    node* temp2 = head2;
    
    node* sumlist = new node(nullptr , -1 , nullptr);
    node* tail = sumlist;
    int cf = 0;
    
    while(temp1 != nullptr || temp2 != nullptr){
        int sum = cf;
        if(temp1 != nullptr){
            sum = sum + temp1->data;
            temp1 = temp1->next;
        }
        if(temp2 != nullptr){
            sum = sum + temp2->data;
            temp2 = temp2->next;
        }
        node* n = new node(tail , sum % 10 , nullptr);
        cf = sum / 10;
        tail->next = n;
        tail = n;
    }
    if(cf){
        node* n = new node(tail , cf , nullptr);
        tail->next = n;
    }
    node* head = sumlist->next;
    return head;
}
int main() {
    int n , m;
    
    cout<<"Enter the size of the 2 DLL: ";
    cin>>n>>m;
    
    if(n == 0 && m == 0) {
        cout << "Both lists are empty!" << endl;
        return 0;
    }
    
    vector<int> arr1(n);
    vector<int> arr2(n);
    
    cout<<"Enter the elements of first DLL: ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr1[i];
    }
    
    cout<<"Enter the elements of second DLL: ";
    for(int i = 0 ; i < m ; i++){
        cin>>arr2[i];
    }
    
    node* head1 = new node(nullptr, arr1[0], nullptr);
    node* head2 = new node(nullptr, arr2[0], nullptr);

    node* tail1 = head1;
    node* tail2 = head2;

    for (int i = 1; i < arr1.size(); i++) {
        node* n1 = new node(tail1, arr1[i], nullptr);
        tail1->next = n1;
        tail1 = n1;
    }

    for (int i = 1; i < arr2.size(); i++) {
        node* n2 = new node(tail2, arr2[i], nullptr);
        tail2->next = n2;
        tail2 = n2;
    }

	node* head = sum(head1 , head2);
	node* temp = head;
	
	while(temp != nullptr){
	    cout<<temp->data<<" ";
	    temp = temp->next;
	}
    return 0;
}
