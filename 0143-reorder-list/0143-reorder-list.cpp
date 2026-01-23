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

/*
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        
        stack<ListNode*> my_stack;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            my_stack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = my_stack.top();
            my_stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};


*/

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* list){
        ListNode* curr = list;
        ListNode* prev = NULL;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        //finding mid
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse second half
        ListNode* second = reverseLinkedList(slow->next);
        slow->next = NULL;

        //merge alternatively
        ListNode* first = head;
        while(second){
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};
