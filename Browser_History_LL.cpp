#include<iostream>
#include<string>

using namespace std;

class browser {
public:
    browser* prev;
    string data;
    browser* next;

    browser(string d, browser* p = nullptr, browser* n = nullptr) {
        prev = p;
        data = d;
        next = n;
    }
};

browser* visit(browser* c, string url) {
    browser* newpage = new browser(url, c);
    c->next = newpage;
    return newpage;
}

browser* back(browser* c, int n) {
    while (n--) {
        if (c->prev == NULL) {
            cout << "Reached beginning: " << c->data << endl;
            return c;
        }
        c = c->prev;
    }
    cout << "back Current page: " << c->data << endl;
    return c;
}

browser* forward(browser* c, int n) {
    while (n--) {
        if (c->next == NULL) {
            cout << "Reached end: " << c->data << endl;
            return c;
        }
        c = c->next;
    }
    cout << "forward Current page: " << c->data << endl;
    return c;
}

int main() {
    string h;
    cout << "Enter the Homepage URL: ";
    cin >> h;
    browser* homepage = new browser(h);
    browser* curr = homepage;

    string command;
    while (true) {
        cout << "\nCommands: visit <url>, back <n>, forward <n>, current, exit" << endl;
        cout << "Enter command: ";
        cin >> command;

        if (command == "visit") {
            string url;
            cin >> url;
            curr = visit(curr, url);
            cout << "Visited: " << curr->data << endl;
        } else if (command == "back") {
            int n;
            cin >> n;
            curr = back(curr, n);
        } else if (command == "forward") {
            int n;
            cin >> n;
            curr = forward(curr, n);
        } else if (command == "current") {
            cout << "Current page: " << curr->data << endl;
        } else if (command == "exit") {
            cout << "Exit browser" << endl;
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
