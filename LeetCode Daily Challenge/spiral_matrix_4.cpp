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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        ListNode* curr=head;

        int left=0;
        int top=0;
        int right=n-1;
        int bottom=m-1;
        while(curr!=NULL and left<=right and top<=bottom){
            for(int j=left;j<=right;j++){
                if(curr==NULL) return ans;
                ans[top][j]=curr->val;
                curr=curr->next;
            }
            top++;

            for(int i=top;i<=bottom;i++){
                if(curr==NULL) return ans;
                ans[i][right]=curr->val;
                curr=curr->next;
            }
            right--;

            for(int j=right;j>=left;j--){
                if(curr==NULL) return ans;
                ans[bottom][j]=curr->val;
                curr=curr->next;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                if(curr==NULL) return ans;
                ans[i][left]=curr->val;
                curr=curr->next;
            }
            left++;
        }
        return ans;
    }
};