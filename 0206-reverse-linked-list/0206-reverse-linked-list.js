/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    
    let prev = null
    let curr = head

    while(curr!=null)
    {
        let next = curr.next
        curr.next = prev

        prev = curr
        curr = next
    }

    return prev

/*

 prev->null
  null<-1 2-> 3-> 4

  next = 2
  1 -> null
  prev = 1





*/


};