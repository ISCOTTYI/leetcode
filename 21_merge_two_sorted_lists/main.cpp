#include <iostream>
#include <string.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    // Three constructors for ListNode
    // : val(0), next(nullptr) is called "initializer list"
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    ListNode* lCurr = head;
    while (lCurr != nullptr) {
        std::cout << lCurr->val << std::endl;
        lCurr = lCurr->next;
    }
}

class Solution {
public:
    ListNode* insert(ListNode* n, ListNode* to) {
        // Insert n after to and return the rest of list n
        ListNode* l = n->next;
        n->next = to->next;
        to->next = n;
        return l;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = l1;
        ListNode* t = l2;
        if (h == nullptr) { return t; }
        if (t == nullptr) { return h; }
        if (l2->val < l1->val) {
            h = l2;
            t = l1;
        }
        ListNode* curr = h;
        while (curr->next != nullptr) {
            // std::cout << "curr: " << curr->val << " curr.next: " << (curr->next)->val << " t: " << t->val << std::endl;
            if (t == nullptr) {
                return h;
            }
            if (t->val < (curr->next)->val) {
                t = insert(t, curr);
            }
            curr = curr->next;
        }
        curr->next = t;
        return h;
    }
};

int main() {
    ListNode l1_2 = ListNode(5);
    ListNode l1_1 = ListNode(4, &l1_2); 
    ListNode l1_0 = ListNode(2, &l1_1);
    ListNode l2_1 = ListNode(3);
    ListNode l2_0 = ListNode(1, &l2_1);
    Solution s;
    ListNode* l = s.mergeTwoLists(&l1_0, &l2_0);
    printList(l);
    return 0;
}
