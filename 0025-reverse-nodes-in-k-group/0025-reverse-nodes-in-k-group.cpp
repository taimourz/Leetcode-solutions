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


    ListNode* reverseList(ListNode* head){
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
        ListNode* oldTail = NULL;        

        while(curr != NULL){
            int cnt = k;
            ListNode* prev = curr;


            ListNode* lookahead = curr;
            int i = 0;
            while(i < k && lookahead != nullptr){
                lookahead = lookahead->next;
                i++;
            }
            if(i < k) break;

            // cnt > 1 b/c I want the node 1 before the rest of the list
            while(cnt > 1){
                curr = curr->next;
                cnt--;
            }                
            
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            
            ListNode* tempPointer = reverseList(prev);

            ListNode* segmentHead = tempPointer;
            ListNode* segmentTail = prev;
            
            // set head for returning
            reverseTimes++;
            if(reverseTimes == 1){
                head = segmentHead;  
            }else{
                oldTail->next = segmentHead;
            }
            
            // merge reverse list to new
            segmentTail->next = curr;
            oldTail = segmentTail;   
                              

                // printList(head);

        }
        return head;
    }
};




/*

- we will traverse. 
- we check if enough nodes are available to reverse else break out
- once confirmed. move the curr pointer till the end node. 
- you know both new list head and tail
- pass the head to function. it returns new head
- set head and tail segments for new reversed list
- here check if it was first reversal. in that case you need to change the head (for returning)
- otherwise, we know we need to connect both tail of previous segment and now tail of current list to rest of list
- at end, you need to make sure new tail is merged with old list
- plus, store current tail as you are going to need it next time.


1 2 3 4 5

        2               1               3       4   5
segmentHead   reverseHead         curr    

2  1            3               4                5
        segmentHead      reverseHead           curr 

*/