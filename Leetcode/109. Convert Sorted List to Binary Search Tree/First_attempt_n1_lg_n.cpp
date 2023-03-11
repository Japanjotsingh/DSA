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
    ListNode* pointer ;
    
    TreeNode* build(int n)
    {
        if( n == 0 )
            return NULL;
        
        TreeNode* now = new TreeNode();
        
        now->left =  build(n/2);
        
        now -> val  = pointer->val;
        pointer = pointer->next;
        
        now->right = build(n - n/2 -1); 
        
        return now;
    }    
    TreeNode* sortedListToBST(ListNode* head) 
    {    pointer = head;
         int len = 0 ;
     
         while(head!=NULL)
         {
             head = head->next;
             len++;
         }
     
         return build(len);
    }
};