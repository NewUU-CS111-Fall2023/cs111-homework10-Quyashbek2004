/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> mergeNodes(ListNode *head) {
    vector<int> result;
    int currentSum = 0;
    ListNode *currentNode = head;

    while (currentNode) {
        if (currentNode->val == 0) {
            if (currentSum != 0) {
                result.push_back(currentSum);
                currentSum = 0;
            }
        } else {
            currentSum += currentNode->val;
        }

        currentNode = currentNode->next;
    }

    if (currentSum != 0) {
        result.push_back(currentSum);
    }

    return result;
}

// Helper function to print the linked list
void printLinkedList(ListNode *head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Sample input
    vector<int> inputList = {0, 3, 1, 0, 4, 5, 2, 0};

    // Create linked list from the input
    ListNode *head = new ListNode(inputList[0]);
    ListNode *current = head;
    for (size_t i = 1; i < inputList.size(); ++i) {
        current->next = new ListNode(inputList[i]);
        current = current->next;
    }

    // Solve the problem
    vector<int> output = mergeNodes(head);

    // Print the modified list
    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i < output.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
