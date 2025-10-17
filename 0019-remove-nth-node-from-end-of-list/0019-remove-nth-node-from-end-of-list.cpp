/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head && head->next == NULL && n==1) return {};

        while(fast != NULL && n--){
            fast = fast->next;
        }

        if(fast == NULL){
            head = head->next;
            return head;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

/*
- slow and fast pointer technique is used.
- first move fast n steps then both slow and fast.
- edge case: if fast bcomes NULL it means no gap b/c fast and slow, which means we need to handle head.
- go with rest of logic

*/