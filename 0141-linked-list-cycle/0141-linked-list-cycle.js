/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {

    let slow = head
    let fast = head

   while(fast!= undefined && fast.next!=undefined)
    {
        slow = slow.next
        fast = fast.next.next
        if(slow==fast) return true
    }
    return false
};



