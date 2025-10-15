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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if(list1 == NULL) return list2;
      if(list2 == NULL) return list1;

      ListNode* tail = NULL;
      ListNode* tailHead = NULL;

      ListNode* curr1 = list1;
      ListNode* curr2 = list2;

      while(curr1 != NULL && curr2 != NULL){
        if(curr1->val <= curr2->val){
            if(tail == NULL){
                tail = curr1;
                tailHead = tail;
            } 
            else{
                tail->next  = curr1;
                tail        = tail->next;
            } 
            curr1      = curr1->next;
        }else{
            if(tail == NULL){
                tail = curr2;
                tailHead = tail;
            }             
            else{
                tail->next  = curr2;
                tail        = tail->next;
            } 
            curr2      = curr2->next;
        }

      }

        if(curr1==NULL){
            tail->next = curr2;

        }else if(curr2==NULL){
            tail->next = curr1;

        }    


        return tailHead;
       
    }
};