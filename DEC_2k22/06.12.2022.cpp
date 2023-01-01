1. https://leetcode.com/problems/odd-even-linked-list/
solution - 
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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* starteven=head->next;
        
        while(even->next!=NULL and odd->next!=NULL)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
            if(even==NULL) break;
        }
        odd->next=starteven;
        
        return head;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

2. https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
solution - 
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
 #define nil NULL
class Solution {
public:
    int length(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n = length(head);
        if(head -> next == nil){
            return head;
        }
        ListNode* temp = head;
        ListNode* f;
        ListNode* l;
        int cnt = 0;

        while(temp){
            cnt++;
            if(cnt == k){
                f = temp;
            }
            if(cnt == n - k + 1){
                l = temp;
            }
            temp = temp -> next;
        }

        swap(f -> val, l -> val);
        return head;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

3. https://leetcode.com/problems/swap-nodes-in-pairs/
solution - 
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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !(head->next)){
            return head;
        }
        ListNode* f = head;
        while(f and f->next){
            swap(f -> val, f -> next -> val);
            f = f -> next -> next;
        }
        return head;
    }
};
