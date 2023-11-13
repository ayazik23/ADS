//Made by Miras Kamatay, EIRfuc-22
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int findMax(Node* head) {
    int max = head->data;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

void doubleSmallerThanMax(Node* head) {
    int max = findMax(head);
    Node* current = head;
    while (current != nullptr) {
        if (current->data < max) {
            current->data *= 2;
        }
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
    int N;

    cout << "Enter the number of elements (N): ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int num;
        cout << "Enter element " << (i + 1) << ": ";
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
    }

    doubleSmallerThanMax(head);

    cout << "Resulting sequence: ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}