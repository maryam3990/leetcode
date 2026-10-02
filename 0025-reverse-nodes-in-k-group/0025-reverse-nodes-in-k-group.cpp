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
    ListNode* reverseGroup(ListNode* head, int k, int n, ListNode*newStart, bool FirstTime
    , ListNode* prev_ptr)
    {
         if(n==0) return head;
         ListNode* curr = newStart;
         ListNode* prev = nullptr;
         ListNode* next_ptr = nullptr;

         int i = 0;
         while(i!=k)
         {
            next_ptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_ptr;
            i++;
         }
         
        if(FirstTime){head=prev;}
        newStart->next = next_ptr;
        if(prev_ptr!=nullptr) prev_ptr->next = prev;
        return reverseGroup(head, k, n-1,next_ptr, false, newStart);

    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==nullptr || k == 0) return head;
        int size = 0;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            ++size;
            temp = temp->next;
        }
        int noOfTimes = size/k;
        if(noOfTimes==0) return head;
        temp = head;
        ListNode* prev = nullptr;
        return reverseGroup(head, k, noOfTimes,temp, true, prev);
    }
};