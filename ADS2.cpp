//Made by Miras Kamatay, EIRfuc-22
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertBeforeDivisible(Node* head, int x) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data % 3 == 0 || current->data % 5 == 0) {
            Node* newNode = new Node(x);
            newNode->next = current;
            if (prev != nullptr) {
                prev->next = newNode;
            }
            else {
                head = newNode;
            }
            current = newNode->next;  // Move to the next node after the inserted node
        }
        prev = current;
        current = current->next;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int num;
    char choice;

    do {
        cout << "Enter element for the singly-linked list: ";
        cin >> num;

        if (head == nullptr) {
            head = new Node(num);
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(num);
        }

        cout << "Do you want to enter another element? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    int x;
    cout << "Enter the number to insert: ";
    cin >> x;

    insertBeforeDivisible(head, x);

    int menuChoice;
    do {
        cout << "Menu:\n";
        cout << "1. Insert before divisible\n";
        cout << "2. Print the list\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            cout << "Enter the number to insert: ";
            cin >> x;
            insertBeforeDivisible(head, x);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            // Clean up memory before exiting
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (true);

    return 0;
}