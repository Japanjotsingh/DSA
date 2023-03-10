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
    ListNode * head_1 = NULL;
    int len = 0 ;
    
    Solution(ListNode* head) {
        
        head_1 = head;
        
        while(head != NULL)
        {
            head = head-> next;
            len++;
        }   
        
    }
    
    int getRandom() {
        
        int rand_no = 1 +  ( ( rand() ) %  ( len ) );
        ListNode* head = head_1;
        
        
        while(--rand_no)
        {  
            head = head->next;   
        }
        
        return head->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */