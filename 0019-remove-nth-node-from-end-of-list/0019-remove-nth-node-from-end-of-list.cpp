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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;

        int totalNode = 0;
        ListNode* temp1 = head;

        // Count total nodes
        while (temp1) {
            totalNode++;
            temp1 = temp1->next;
        }

        int nodeToBeDelete = totalNode - n + 1;

        // If we need to delete the head node
        if (nodeToBeDelete == 1) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Otherwise, delete from inside the list
        ListNode* temp = head;
        ListNode* prev = NULL;
        int cnt = 0;

        while (temp) {
            cnt++;
            if (cnt == nodeToBeDelete) {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
