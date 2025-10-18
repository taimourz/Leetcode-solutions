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

    void printList(ListNode* head) {
        ListNode* curr = head;
        while (curr != NULL) {
            cout << curr->val;
            if (curr->next != NULL) cout << ", ";
            curr = curr->next;
        }
        cout << endl;
    }

    ListNode* reverseList(ListNode* head, ListNode* endingNode){
        if(head == NULL) return {};
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;

        while(next!=NULL){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        printList(prev);
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int reverseTimes = 0;
        ListNode* prevTail = NULL; // track tail of previous reversed segment

        while(curr != NULL && curr->next != NULL){
            int cnt = k;
            ListNode* prev = curr;
            while(cnt > 1 && curr->next!=NULL){
                curr = curr->next;
                cnt--;
            }    

            if(cnt == 1){
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = NULL;
                
                // reverse current segment
                ListNode* reverseHead = reverseList(prev, temp);
                
                // \U0001f538 Instead of walking again, use `prev` (original head) as the tail
                ListNode* tailOfReversedSegment = prev;  // this was the head before reversal

                // set head for returning
                reverseTimes++;
                if(reverseTimes == 1){
                    head = reverseHead;
                } else {
                    // connect previous segment tail to new reversed head
                    prevTail->next = reverseHead;
                }

                // connect tail of this reversed segment to next part
                tailOfReversedSegment->next = curr;
                
                // update prevTail for next iteration
                prevTail = tailOfReversedSegment;

            } else {
                break;
            }
        }
        return head;
    }
};
