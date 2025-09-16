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
    // ListNode* reverseList(ListNode* head) {
    //     if(head==NULL || head->next==NULL) return head;
    //     ListNode* newHead = reverseList(head->next); 
    //     head->next->next = head;
    //     head->next = NULL;
    //     return newHead;
    // }
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        int mx=(st.top())->val;
        ListNode* prev= st.top();
        st.pop();
        while(!st.empty()){
            ListNode* temp = st.top();
            if(temp->val>=mx){
                temp->next = prev;
                prev=temp;
                mx = temp->val; 
            }
            st.pop();
        }
        return prev;
    }
};