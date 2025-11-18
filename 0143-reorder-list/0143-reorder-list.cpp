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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next; 
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = NULL;
        while(secondHalf!=NULL){
            stk.push(secondHalf);
            secondHalf=secondHalf->next;
        }


        ListNode* curr = head;
        while(!stk.empty()){
            ListNode* top = stk.top();
            stk.pop();

            ListNode* temp = curr->next;
            curr->next = top;
            top->next = temp;

            curr=temp;

        }

    }
};