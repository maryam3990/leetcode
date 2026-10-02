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
    void deleteNext(ListNode* ptr)
    {
        ListNode* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==nullptr) return head;
        ListNode* temp = head;
        while(temp->next!=nullptr)
        {
           if(temp->val == temp->next->val) deleteNext(temp);
           else temp = temp->next;
        }
        return head;
    }
};