#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void createList(Node*& head, Node*& tail, const string& source) {
    head = nullptr;
    tail = nullptr;

    ifstream file(source);
    if (!file.is_open()) {
        cerr << "Unable to open file\n";
        return;
    }

    int num;
    while (file >> num) {
        Node* newNode = new Node();
        newNode->data = num;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    file.close();
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int length(Node* head) {
    int len = 0;
    Node* current = head;
    while (current != nullptr) {
        len++;
        current = current->next;
    }
    return len;
}

void reverseList(Node*& head) {
    Node* prev = nullptr, * current = head, * next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

bool isFibonacci(int num) {
    if (num == 0 || num == 1)
        return true;
    int a = 0, b = 1, c = a + b;
    while (c < num) {
        c = a + b;
        a = b;
        b = c;
    }
    return c == num;
}

void findFibonacci(Node* head) {
    Node* current = head;
    cout << "Fibonacci numbers found in the list: ";
    while (current != nullptr) {
        if (isFibonacci(current->data))
            cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Build list from user input
    int size;
    cout << "Enter the number of elements to add from keyboard: ";
    cin >> size;
    cout << "Enter " << size << " integers separated by space: ";
    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        Node* newNode = new Node();
        newNode->data = num;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Build list from file
    createList(tail->next, tail, "test.txt");

    cout << "Count numbers on file: " << length(head) << endl;

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Reverse the list
    reverseList(head);
    cout << "Reversed list: ";
    printList(head);

    // Find Fibonacci numbers in the list
    findFibonacci(head);

    // Free memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}