
class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
}


class Solution{
    //Function to rotate a linked list.
    public Node rotate(Node head, int k) {
        // add code here
          if(head==null && head.next==null)
       {
           return head;
       }
       
       Node curr=head;
         Node first=head;
         int i=1;
       while(curr.next!=null)
       {
           curr=curr.next;
       }
       Node last=curr;
       last.next=head;
   
       while(i!=k)
       {
           first=first.next;
           i++;
       }
       Node newhead=first.next;
       first.next=null;
       head=newhead;
       
       return head;
    }
}