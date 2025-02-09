#include <iostream>
#include <memory>

// Define a Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to find the length of a linked list
int getLength(Node* head) {
    int length = 0;
    while (head) {
        ++length;
        head = head->next;
    }
    return length;
}

// Function to find the merge point of two linked lists
Node* findMergePoint(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Align the starting points
    while (len1 > len2) {
        head1 = head1->next;
        --len1;
    }
    while (len2 > len1) {
        head2 = head2->next;
        --len2;
    }

    // Traverse both lists together to find the merge point
    while (head1 && head2) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr; // No merge point found
}

// Helper function to create a new node
Node* createNode(int value) {
    return new Node(value);
}

// Helper function to print a linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    // Create two linked lists
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    Node* head2 = createNode(9);
    head2->next = createNode(10);

    // Create a merge point
    head2->next->next = head1->next->next; // Both lists merge at node with value 3

    // Print the lists
    std::cout << "List 1: ";
    printList(head1);

    std::cout << "List 2: ";
    printList(head2);

    // Find and print the merge point
    Node* mergePoint = findMergePoint(head1, head2);
    if (mergePoint) {
        std::cout << "Merge point found at value: " << mergePoint->data << std::endl;
    } else {
        std::cout << "No merge point found." << std::endl;
    }

    // Free memory (cleanup)
    delete head2->next->next; // Shared node
    delete head1->next->next->next->next; // Node 5
    delete head1->next->next->next;       // Node 4
    delete head1->next->next;             // Node 3
    delete head2->next;                   // Node 10
    delete head2;                         // Node 9
    delete head1->next;                   // Node 2
    delete head1;                         // Node 1

    return 0;
}

// List 1: 1 -> 2 -> 3 -> 4 -> 5 -> null
// List 2: 9 -> 10 -> 3 -> 4 -> 5 -> null
// Merge point found at value: 3
