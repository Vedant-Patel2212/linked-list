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

node* deletehead(node* head){
    if(head == NULL){
        return head;
    }
    node* temp = head;
    head = head->next;
    delete(temp);
    return head;
}

node* deletetail(node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete(temp->next);
    temp->next = nullptr;
    return head;
}

void traver(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp<<" ";
        temp = temp->next;
    }
}

node* deletek(node* head , int k){
    if(head == NULL){
        return NULL;
    }
    if(k == 1){
        head = deletehead(head);
        return head;
    }
    node* temp = head;
    node* pretemp = temp;
    int cunt = 0;
    
    while(temp != nullptr){
        cunt++;
        if(cunt == k){
            pretemp->next = pretemp->next->next;
            delete(temp);
            break;
        }
        pretemp = temp;
        temp = temp->next;
    }
    return head;    
}

node* deleteval(node* head , int k){
    if(head == NULL){
        return NULL;
    }
    node* temp = head;
    node* pretemp = temp;
    while(temp->data != k){
        pretemp = temp; 
        temp = temp->next;
    }
    pretemp->next = pretemp->next->next;
    delete(temp);
    return head; 
}

node* inserthead(node* head , int val){
    node* temp = head;
    node* n = new node(val , temp);
    head = n;
    return head;
}

node* inserttail(node* head , int val){
    if(head == NULL){
        return inserthead(head , val);
    }
    node* temp = head;
    node* n = new node(val , nullptr);
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = n;
    return head;
}

node* insertk(node* head , int val , int k , int n){
    if(head == NULL || k == 1){
        return inserthead(head , val);
    }    
    if(k > n + 1){
        cout<<"Linked List Full";
        return head;
    }
    node* temp = head;
    int cunt = 0;
    while(temp != nullptr){
        cunt++;
        if(cunt == k - 1){
            node* n = new node(val , temp->next);
            temp->next = n;
            break;
        }
        temp = temp->next;
    }
    return head;
}

node* insertval(node* head , int val , int d , int n){
    if(head == NULL){
        return inserthead(head , val);
    }
    node* temp = head;
    int cunt = 0;
    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
        cunt++;
        if (cunt > n) {
            cout << "No such element found";
            return head;
        }
    }
    if (temp == nullptr) {
        cout << "No such element found";
        return head;
    }
    node* m = new node(d, temp->next);
    temp->next = m;
    return head;
}

int search(node* head , int val){
    node* temp = head;
    int cunt = 0;
    while(temp != nullptr){
        if(temp->data == val){
            return cunt;
        }
        temp = temp->next;
        cunt++;
    }
    cout<<"No such element found";
    return -1;
}

void print(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    int n;
    cout << "Enter the size of Linked List: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
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

    int choice;
    while(true){
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position \n";
        cout << "4. Insert after Value\n";
        cout << "5. Delete Head\n";
        cout << "6. Delete Tail\n";
        cout << "7. Delete at Position \n";
        cout << "8. Delete by Value\n";
        cout << "9. Search\n";
        cout << "10. Print List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int val, k, i;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> val;
                head = inserthead(head, val);
                cout << "New Linked List: ";
                print(head);
                cout << endl;
                break;

            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> val;
                head = inserttail(head, val);
                cout << "New Linked List: ";
                print(head);
                cout << endl;
                break;

            case 3:
                cout << "Enter position (K): ";
                cin >> i;
                cout << "Enter value to insert: ";
                cin >> val;
                head = insertk(head, val,i , n);
                cout << "New Linked List: ";
                print(head);
                cout << endl;
                break;

            case 4:
                cout << "Enter value after which to insert: ";
                cin >> val;
                cout << "Enter value to insert: ";
                cin >> k;
                head = insertval(head, val, k, n);
                cout << "New Linked List: ";
                print(head);
                cout << endl;
                break;

            case 5:
                head = deletehead(head);
                cout << "New Linked List: ";
                print(head);
                cout << endl;
                break;

            case 6:
                head = deletetail(head);
                cout << "New Linked List: ";
                print(head);
                cout << endl;
                break;

            case 7:
                cout << "Enter position (K) to delete: ";
                cin >> i;
                head = deletek(head, i);
                cout << "New Linked List: ";
                print(head);
                cout << endl;
                break;

            case 8:
                cout << "Enter value to delete: ";
                cin >> val;
                head = deleteval(head, val);
                cout << "New Linked List: ";
                print(head);
                cout << endl;
                break;

            case 9:
                cout << "Enter value to search: ";
                cin >> val;
                i = search(head, val);
                if (i != -1) {
                    cout << "Found at position: " << i << endl;
                } else {
                    cout << "Element not found.\n";
                }
                break;

            case 10:
                cout << "Linked List: ";
                print(head);
                cout << endl;
                break;

            case 0:
                cout << "Exit\n";
                return 0;

            default:
                cout << "Invalid choice Try again.\n";
        }
    }
    return 0;
}