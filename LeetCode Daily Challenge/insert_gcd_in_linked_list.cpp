/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode* curr=head->next;
        ListNode* prev=head;
        ListNode* ans=new ListNode(head->val);
        ListNode* temp=ans;
        while(curr!=NULL){
            int gcd=__gcd(curr->val,prev->val);
            temp->next=new ListNode(gcd);
            temp=temp->next;
            temp->next=curr;
            temp=temp->next;
            prev=curr;
            curr=curr->next;
        }
        return ans;
    }
};