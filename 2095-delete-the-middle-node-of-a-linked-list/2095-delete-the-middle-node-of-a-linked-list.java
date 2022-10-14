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

        while(temp!=null)
        {
            k++;
            temp=temp.next;
        }
         if(k==1)return null;
    ListNode   curr = head;
    int mid = k/2 -1;
    int i=0;
    while(i<mid){
        curr = curr.next;
        i++;
    }
    curr.next = curr.next.next;
    return head;
    }
}