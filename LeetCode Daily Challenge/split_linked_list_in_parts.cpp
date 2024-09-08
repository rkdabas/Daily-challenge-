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
    int findLen(ListNode* root) {
        int cnt = 0;
        while (root != NULL) {
            cnt++;
            root = root->next;
        }
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);  

        if (head == NULL) {
            return ans;  
        }

        int n = findLen(head);
        int eachPartLength = n / k; 
        int remainder = n % k; 

        ListNode* curr = head;
        for (int i = 0; i < k && curr != NULL; i++) {
            ans[i] = curr;  
            int partSize = eachPartLength + (remainder > 0 ? 1 : 0); 

            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            ListNode* nextPart = curr->next;
            curr->next = NULL;
            curr = nextPart;

            if (remainder > 0) remainder--; 
        }

        return ans;
    }
};
