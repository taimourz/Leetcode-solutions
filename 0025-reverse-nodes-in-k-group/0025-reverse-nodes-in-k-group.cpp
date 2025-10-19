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
                
              

                printList(head);

        }
        return head;
    }
};




/*

- traverse the list. 
- set a counter cnt = k 
- decrement it upto 1 while keep moving the curr pointer. This way we are at the ending node of new list we want to reverse
- before sending the head of this list for reversing make sure tha its tail next pointer is NULL.
- It returns the new head with list reversed 
- now we need to link this list to the rest of the list. we need to go upto end of the reversed list and set its tail next to curr.
- we know that after first reversal we have the new head we would need to return. we are keeping track of this by a reverseTimes counter.
- 

1 2 3 4 5

        2               1               3       4   5
segmentHead   reverseHead         curr    

2  1            3               4                5
        segmentHead      reverseHead           curr 

*/