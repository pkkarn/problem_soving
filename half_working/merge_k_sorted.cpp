/**  Merge K Sorted Lists: It's working in all condition except for large no. of lists **/

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



     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If l1

        ListNode* curr1 =  list1;
        ListNode* curr2 =  list2;
        
        ListNode* newList {nullptr};
        ListNode* tail {nullptr};
        // 1->2->4
        // 1->3->4


        while(curr1 && curr2) {
            int temp;
            if(curr1->val <= curr2->val) {
                // cout << curr1->val <<endl;
                temp = curr1->val;
                if(curr1->next) {
                    curr1 = curr1->next;
                } else {
                    curr1 = nullptr;
                }
            } else {
                temp = curr2->val;
                // cout << curr2->val <<endl;
                if(curr2->next) {
                    curr2 = curr2->next;
                } else {
                    curr2 = nullptr;
                }
            }

            ListNode* newNode = new ListNode(temp);

            if(!newList) {
                tail = newNode;
                newList = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        while(curr1 || curr2) {
            ListNode* newNode {nullptr};

            if(curr1) {
                newNode = new ListNode(curr1->val);
                curr1 = curr1->next;
            }

            if(curr2) {
                newNode = new ListNode(curr2->val);
                curr2 = curr2->next;
            }

            if(!newList) {
                tail = newNode;
                newList = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        return newList;
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // write function to merge sorted list
        // merge two list and that with other one.
        if(lists.size() == 0) { 
            ListNode* temp {nullptr};
            return temp;
        }
        if(lists.size() == 1) { 
            ListNode* temp = lists.at(0);
            return temp;
        }
        ListNode* finalResult = lists.at(0);

        for(int i = 1; i < lists.size(); i++) {
            finalResult = mergeTwoLists(lists.at(i), finalResult);
        }

        return finalResult;
    }
};
