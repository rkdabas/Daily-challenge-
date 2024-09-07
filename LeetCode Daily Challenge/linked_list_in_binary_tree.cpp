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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool check(ListNode* head,TreeNode* root){
    if(head==NULL) return true;
    if(root==NULL) return false;
    if(head->val != root->val){
        return false;
    }
    bool left=check(head->next,root->left);
    bool right=check(head->next,root->right);
    if((head->val == root->val) and (left or right)){
        return true;
    }
    else return false;
}
bool solve(ListNode* head,TreeNode* root){
    if(root==NULL) return false;
    if(root->val == head->val){
        if(check(head,root)==true){
            return true;
        }
    }
    bool left=solve(head,root->left);
    bool right=solve(head,root->right);
    return left or right;
}
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head,root);
    }
};