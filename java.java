class Solution
{
    public static Node reverse(Node head, int k)
    {
        //Your code here
        if (head == null) {
            return null;
        }

        Node prev = null;
        Node current = head;
        Node next = null;
        int count = 0;

        // Reverse the first k nodes
        while (current != null && count < k) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
            count++;
        }

        // Recursively reverse the next group of k nodes
        if (next != null) {
            head.next = reverse(next, k);
        }

        return prev;
    }
}