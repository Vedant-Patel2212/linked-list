#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;

    node(node *p, int d, node *n)
    {
        prev = p;
        data = d;
        next = n;
    }
};

node *deletehead(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete (temp);
    return head;
}

node *deletetail(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete (temp);
    return head;
}

node *deletek(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (k == 1)
    {
        return deletehead(head);
    }
    node *temp = head;
    int cunt = 1;
    while (temp != nullptr)
    {
        if (cunt == k)
        {
            if (temp->next == nullptr)
            {
                return deletetail(head);
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            break;
        }
        temp = temp->next;
        cunt++;
    }
    return head;
}

node *deleteval(node *head, int val)
{
    node *temp = head;
    if (temp->data == val)
    {
        return deletehead(head);
    }
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            if (temp->next == nullptr)
            {
                return deletetail(head);
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete (temp);
            return head;
        }
        temp = temp->next;
    }
    cout << "No such element found";
    return head;
}

node *inserthead(node *head, int val)
{
    node *temp = head;
    node *n = new node(nullptr, val, temp);
    head = n;
    return head;
}

node *inserttail(node *head, int val)
{
    if (head == NULL)
    {
        return inserthead(head, val);
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    node *n = new node(temp, val, nullptr);
    temp->next = n;
    return head;
}

node *insertk(node *head, int val, int k, int n)
{
    if (k > n + 1)
    {
        cout << "Linked List Full";
        return head;
    }
    if (k == n + 1)
    {
        return inserttail(head, val);
    }
    if (k == 1)
    {
        return inserthead(head, val);
    }
    node *temp = head;
    int cunt = 1;
    while (temp->next != nullptr)
    {
        if (cunt == k)
        {
            break;
        }
        cunt++;
        temp = temp->next;
    }
    node *m = new node(temp->prev, val, temp);
    temp->prev->next = m;
    temp->prev = m;
    return head;
}

node *insertval(node *head, int val, int ele, int n)
{
    if (head == NULL)
    {
        return head;
    }
    if (ele == head->data)
    {
        return inserthead(head, val);
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->data == ele)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp->next == nullptr)
    {
        cout << "Element not found.";
        return head;
    }
    node *m = new node(temp->prev, val, temp);
    temp->prev->next = m;
    temp->prev = m;
    return head;
}

void print(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int search(node *head, int val)
{
    int i = 1;
    node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return i;
        }
        i++;
        temp = temp->next;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of the Linked list";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    node *head = new node(nullptr, arr[0], nullptr);
    node *tail = head;
    for (int i = 1; i < n; i++)
    {
        node *n = new node(tail, arr[i], nullptr);
        tail->next = n;
        tail = n;
    }

    int choice;
    while (true)
    {
        cout << "\n\nChoose operation:\n";
        cout << "1. Insert at Head\n2. Insert at Tail\n3. Insert at Position\n4. Insert before Value\n";
        cout << "5. Delete Head\n6. Delete Tail\n7. Delete at Position\n8. Delete by Value\n";
        cout << "9. Print List\n10. Search Value\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        int val, pos, ele;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            head = inserthead(head, val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            head = inserttail(head, val);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> val >> pos;
            head = insertk(head, val, pos, n);
            break;
        case 4:
            cout << "Enter value to insert and element to insert before: ";
            cin >> val >> ele;
            head = insertval(head, val, ele, n);
            break;
        case 5:
            head = deletehead(head);
            break;
        case 6:
            head = deletetail(head);
            break;
        case 7:
            cout << "Enter position: ";
            cin >> pos;
            head = deletek(head, pos);
            break;
        case 8:
            cout << "Enter value to delete: ";
            cin >> val;
            head = deleteval(head, val);
            break;
        case 9:
            print(head);
            break;
        case 10:
            cout << "Enter value to search: ";
            cin >> val;
            pos = search(head, val);
            if (pos != -1)
            {
                cout << "Element found at position: " << pos << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
