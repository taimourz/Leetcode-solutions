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
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                prev->next = list1;
                list1=list1->next;
            }else{
                prev->next = list2;
                list2=list2->next;

            }
            prev=prev->next;
        }
        if(list1!=NULL) prev->next = list1;
        if(list2!=NULL) prev->next = list2;

        return dummy->next;
    }
};


/*

 [1,2,4] [1,3,4]
  
        c1   
              c2 

   c1 <= c2 


    c1 <= c2
    2. <=  1



    c1 <= c2
    2. <=  3


    c1 <= c2
    4. <=  3

p->1->1->2->3->4  

    c1 <= c2
    4. <=  4






*/