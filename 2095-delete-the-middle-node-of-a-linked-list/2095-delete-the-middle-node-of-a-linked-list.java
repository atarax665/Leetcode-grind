/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
       public ListNode deleteMiddle(ListNode head) {
        ListNode temp=head;
        int k=0;
        if(head==null)
        return head;

        while(temp!=null)
        {
            k++;
            temp=temp.next;
        }
        if(k==1)
        return null;
       int mid=k/2 - 1;
   
    ListNode prev=head;
    while(mid!=0&& prev!=null)
    {
  prev=prev.next;
  mid--;
    }
    prev.next=prev.next.next;

    return head;
    }
}