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

#include <iostream>
#include <deque>
using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        int n, carry = 0;
        while (l1!=nullptr && l2 != nullptr ){
            n = carry + l1->val + l2->val;
            carry = n/ 10;
            ListNode *tmp = new ListNode(n%10);
            tmp->next = nullptr;

            if (head == nullptr){
                head = tmp;
                curr = head;
            }else{
                curr->next = tmp;
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr){
            n = carry + l1->val;
            carry = n/ 10;
            ListNode *tmp = new ListNode(n%10);
            tmp->next = nullptr;
            curr->next = tmp;
            curr = curr->next;
            l1 = l1->next;
            
        }

        while(l2 != nullptr){
            n = carry + l2->val;
            carry = n/ 10;
            ListNode *tmp = new ListNode(n%10);
            tmp->next = nullptr;
            curr->next = tmp;
            curr = curr->next;
            l2 = l2->next;
        }

        if (carry !=0 ){
            ListNode *tmp = new ListNode(carry);
            tmp->next = nullptr;
            curr->next = tmp;
        }

        return head;
    }
};