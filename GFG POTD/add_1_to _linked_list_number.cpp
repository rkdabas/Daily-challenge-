class Solution {
  public:
  Node* reverse(Node* head){
      Node* curr=head;
      Node* prev=NULL;
      Node* forw=NULL;
      while(curr!=NULL){
          forw=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forw;
      }
      return prev;
  }
    Node* addOne(Node* head) {
        head=reverse(head);
        int carry=1;
        Node* res=new Node(-1);
        Node* ans=res;
        
        while(head!=NULL or carry!=0){
            int sum=0;
            if(head!=NULL) sum=head->data+carry;
            else sum=carry;
            carry=sum/10;
            
            Node* temp=new Node(sum%10);
            ans->next=temp;
            ans=ans->next;
            if(head!=NULL) head=head->next;
        }
        res->next=reverse(res->next);
        return res->next;
        
    }
};