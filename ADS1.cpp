//Made by Miras Kamatay, EIRfuc-22.

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void removeThird(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        cerr << "List is too short to remove the third item." << endl;
        return;
    }

    Node* temp = head->next->next;
    head->next->next = temp->next;
    delete temp;
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

    int menuChoice;
    do {
        cout << "Menu:\n";
        cout << "1. Remove the third item\n";
        cout << "2. Print the list\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            removeThird(head);
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