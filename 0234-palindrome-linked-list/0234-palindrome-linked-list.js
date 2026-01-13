/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let slow = head
    let fast = head

    while(fast!=undefined && fast.next!=undefined)
    {
        slow = slow.next
        fast = fast.next.next
    }

    let prev = null
    let current = slow

    while(current!=null)
    {
        let next = current.next
        current.next = prev
        prev = current
        current = next
    }


    debugger

    let right = prev
    let left = head
    while(right!=null)
    {
        if(left.val!=right.val) return false
        right = right.next
        left = left.next
    }

    return true
    
};

// let head = createListNode([1,2,2,1])
// console.log(isPalindrome(head))
// let head2 = createListNode([1,2])
// console.log(isPalindrome(head2))

