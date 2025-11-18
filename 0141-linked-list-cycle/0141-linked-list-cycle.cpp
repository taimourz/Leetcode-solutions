/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        unordered_map<ListNode*, int> mp;

        while(fast != NULL){
            if (mp.find(fast->next) != mp.end()){
                return true;
            }
            mp[fast]++;
            fast = fast->next;
        }

        return false;

        
    }
};