#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            prev = curr;
            curr = curr->next;
        }

        return dummy.next;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution* solution = new Solution();
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);

    std::cout << "Original List: ";
    printList(head);

    ListNode* swappedHead = solution->swapPairs(head);

    std::cout << "Swapped List: ";
    printList(swappedHead);
    return 0;
}