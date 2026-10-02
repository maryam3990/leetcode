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
    ListNode* moveHead(ListNode* &head, ListNode* &tail)
    {
        if(head==nullptr || head->next == nullptr) return tail;
        ListNode* temp = head->next;
        tail->next = head;
        tail = head;
        tail->next = nullptr;
        head = temp;
        return tail;
    }
    ListNode* moveNext(ListNode* &temp, ListNode* &tail)
    {
        if(tail==nullptr || temp->next == tail) return tail;
        ListNode* tempo = temp->next;
        temp->next = tempo->next;
        tail->next = tempo;
        tail = tempo;
        tail->next = nullptr;
        return tail;
    }
    ListNode* partition(ListNode* head, int x) 
    {
         if(head==nullptr || head->next == nullptr) return head;
        ListNode* tail = head;
        int size = 1;
        while(tail->next!=nullptr)
        {
            tail = tail->next;
            ++size;
        }
        ListNode*originalTail = tail;
        int i = 0;
        while(head->val >= x && size>0)
        {
            if(i==0)
           originalTail = moveHead(head, tail);
           else moveHead(head, tail);
            --size;
            ++i;
        }
        ListNode* temp = head;
        while(temp->next!=nullptr && size>0 && temp->next!=originalTail)
        {  
           
           if(temp->next->val >= x) 
           {
            if(i==0)
            originalTail = moveNext(temp, tail); 
            else moveNext(temp, tail);
            ++i;
            --size;
            }
           else temp = temp->next;
        }
        return head;
    }
};