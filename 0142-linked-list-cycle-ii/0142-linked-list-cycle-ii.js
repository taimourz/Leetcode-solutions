var detectCycle = function(head) {

    let slow = head
    let fast = head

   let cycle_length = 0
   while(fast!= undefined && fast.next!=undefined)
    {
        slow = slow.next
        fast = fast.next.next
        if(slow==fast)
        {
            let current = slow

            while(true)
            {
                cycle_length += 1
                current = current.next

                if(slow==current) break
            }
            break;

        }
    }

    if(cycle_length == 0) return null

    let pointer1 = head, pointer2 = head
    
    debugger
    while(cycle_length>0)
    {
        pointer2 = pointer2.next
        cycle_length -= 1
    }


    while(pointer1 != pointer2)
    {
        pointer1 = pointer1.next
        pointer2 = pointer2.next
    }

    debugger
    return pointer1
    
};



/*


3 2 0 4





*/
