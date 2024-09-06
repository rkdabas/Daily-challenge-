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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>m;
        for(auto it:nums) m[it]++;

        ListNode* curr=head;
        while(m.find(curr->val)!=m.end()){
            curr=curr->next;
        }
         
        ListNode* prev=NULL;
        head=curr;
        while(curr!=NULL){
            if(m.find(curr->val)!=m.end()){
                curr=curr->next;
                prev->next=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};