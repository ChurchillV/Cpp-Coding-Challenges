#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {

    if(head == nullptr || head->next == nullptr) { 
        return false;
    }

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) { 
            return true;
        }
    }

    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;

    if(hasCycle(head)) {
        std::cout << "Cycle detected" << std::endl;
    } else { 
        std::cout << "No Cycle detected" << std::endl;
    }
    return 0;
}