#include <iostream>
#include <string>
#include <cmath>

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

class WoringButUnacceptedSolution {
public:
    int getNumberFromList(ListNode* l) {
        int exp = 0, res = 0;
        while (l != nullptr) {
            // std::cout << exp << " " << res << std::endl;
            res = res + l->val * std::pow(10, exp);
            exp++;
            l = l->next;
        }
        return res;
    }

    ListNode* numberToList(int n) {
        ListNode* h = new ListNode();
        ListNode* curr = h;
        std::string nStr = std::to_string(n);
        std::cout << nStr << std::endl;
        // https://www.techiedelight.com/loop-characters-string-backwards-cpp/
        // one shoud use auto here!!!
        typedef std::string::const_reverse_iterator cri;
        for (cri it = nStr.crbegin(); it != nStr.crend(); it++) {
            int i = *it - '0'; // convert char to int
            curr->val = i;
            if (it < nStr.crend() - 1) { // cool: this shit works with iters :)
                ListNode* n = new ListNode();
                curr->next = n;
                curr = n;
            }
        }
        return h;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1Num = getNumberFromList(l1);
        int l2Num = getNumberFromList(l2);
        int res = l1Num + l2Num;
        return numberToList(res);
    }
};

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return 0;
    }
};

int main() {
    ListNode l1_2 = ListNode(3);
    ListNode l1_1 = ListNode(4, &l1_2); 
    ListNode l1_0 = ListNode(2, &l1_1);
    ListNode l2_2 = ListNode(4);
    ListNode l2_1 = ListNode(6, &l2_2); 
    ListNode l2_0 = ListNode(5, &l2_1);
    Solution s;
    // ListNode* l = s.addTwoNumbers(&l1_0, &l2_0);
    printList(l);
    return 0;
}
