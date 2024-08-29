class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        bool flag=false;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        if(flag==false) return 0;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        Node* curr=slow;
        int cnt=1;
        while(curr->next!=slow){
            curr=curr->next;
            cnt++;
        }
        return cnt;
    }
};