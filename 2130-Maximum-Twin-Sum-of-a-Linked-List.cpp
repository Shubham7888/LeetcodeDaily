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
    int pairSum(ListNode* head) {
        vector<int>pre;

        while(head){
            pre.push_back(head->val);
            head=head->next;
        }
        int low=0,high=pre.size()-1;
        int ans=0;

        while(low<high){
            ans=max(ans,pre[low]+pre[high]);
            low++;
            high--;
        }
        return ans;
    }
};