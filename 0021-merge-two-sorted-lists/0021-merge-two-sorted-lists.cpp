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

//Recursive
// Time Complexity O(n+m)
// Space Complexity O(n+m) this is auxiliary stack space due to recursion.
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      
//         if(l1==NULL)return l2;
//         if(l2==NULL)return l1;
//         if(l1->val<=l2->val){
//             l1->next=mergeTwoLists(l1->next,l2);
//             return l1;
//         }
//         else{
//             l2->next=mergeTwoLists(l2->next,l1);
//             return l2;
//         }
//     }
// };



// ITERATIVE APPROACH

// Time Complexity O(n+m)
// Space Complexity O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      
       if(l1==NULL)return l2;
       if(l2==NULL)return l1;

        ListNode* ptr=l1;
        if(l1->val>l2->val){
            ptr=l2;
            l2=l2->next;
        }
        else{
            l1=l1->next;
        }
        ListNode *curr=ptr;
        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(!l1)curr->next=l2;
        else curr->next=l1;
        return ptr;

    }
};
