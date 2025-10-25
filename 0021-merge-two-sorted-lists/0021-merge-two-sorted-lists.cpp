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
        if(list1==NULL && list2) return list2;
        else if(list2==NULL && list1) return list1;
        else if(list1==NULL && list2==NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* prevHead = NULL;

        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                if(prev==NULL){
                    prev = list1;
                    prevHead = list1;
                }else{
                    prev->next=list1;
                    prev=prev->next;
                }
                list1 = list1->next;
            }else{
                if(prev==NULL){
                    prev = list2;
                    prevHead = list2;
                }else{
                    prev->next=list2;
                    prev=prev->next;
                }                
                list2 = list2->next;    
            }
        }

        if(list1!=NULL) prev->next = list1;
        else prev->next = list2;

        return prevHead;
    }
};