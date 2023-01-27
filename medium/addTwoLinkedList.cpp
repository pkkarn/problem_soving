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
#include<iostream>
#include<map>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Push into Linked List at last;
void pushList(ListNode *list, int val) {
    ListNode* tempNode = list;
    cout << "Final Result: " << tempNode->next << endl;
    while(tempNode->next != 0) {
        tempNode = tempNode->next;
    }
    cout << "Loop Ends" << endl;
    tempNode->next = new ListNode(val);
}

void calculateCarryAndCurrVal(int &curr_val, int &carry) {
    if(curr_val > 9) {
        carry = 1;
        curr_val = curr_val - 10;
    } else {
        carry = 0;
    }
}



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* curr_1 = l1;
    ListNode* curr_2 = l2;
    int carry = 0;

    // 2-4->3 + 5->6->4 = 342 + 465 = 5+2->6+4+1->4+3+1
    ListNode* final_result {nullptr};
    // run while loop until one of the list finishes, As it's in reverse order that's why
    // we can sum curr values of both list and can store carry.
    while(curr_1 && curr_2) {
        int curr_val = curr_1->val + curr_2->val + carry;
        // intialize newley created to final_result if its empty
        if(!final_result) {
            // calculate carry and remaining item

            calculateCarryAndCurrVal(curr_val, carry);
            
            final_result = new ListNode(curr_val);
        } else {
            
            calculateCarryAndCurrVal(curr_val, carry);
            // Else find next item and store there
            pushList(final_result, curr_val);
        }
        // At last upate curr from next item;
        curr_1 = curr_1->next;
        curr_2 = curr_2->next;
    }

    // Lastly if items in curr_1 is left then push rest of the item final_result list
    if(curr_1) {
        while(curr_1) {
            int curr_val = curr_1->val + carry;
            calculateCarryAndCurrVal(curr_val, carry);
            pushList(final_result, curr_val);
            // carry=0;
            curr_1 = curr_1->next;
        }
    }

    // Lastly if items in curr_1 is left then push rest of the item final_result list
    if(curr_2) {
        while(curr_2) {
            int curr_val = curr_2->val + carry;
            calculateCarryAndCurrVal(curr_val, carry);
            pushList(final_result, curr_val);
            // carry=0;
            curr_2 = curr_2->next;
        }
    }

    // Atlast if there is any carry left then add that
    if(carry) {
        pushList(final_result, carry);
        carry = 0;
    }
    
    return final_result;
}

ListNode* generateListNode(string str) {
    ListNode* currNode {nullptr};
    
    for(int i=0; i<str.size(); i++) {
        char tempChar = str[i];
        int currVal = atoi(&tempChar);
        ListNode* tempNode = new ListNode(currVal);
        if(!currNode) {
            currNode = tempNode;
        } else {
            ListNode* curr = currNode;
            while(curr->next) {
                curr = curr->next;
            }
            
            curr->next = tempNode;
            
            // 3->2
        }
    }
    return currNode;
}

void printNodeList(ListNode* nl) {
    ListNode* curr = nl;
    
    while(curr) {
        cout << curr->val << endl;
        curr = curr->next;
    }
}

int main() {
    /** Test Case 1 **/
    cout << "Test Case 1 : " << endl;
    string l1_string = "9999999";
    ListNode* l1 = generateListNode(l1_string);
    
    string l2_string = "9999";
    ListNode* l2 = generateListNode(l2_string);

    ListNode* finalList = addTwoNumbers(l1, l2);
    printNodeList(finalList);
    
    /** Test Case 2 **/
    cout << "Test Case 2 : " << endl;
    string m1_string = "243";
    ListNode* m1 = generateListNode(m1_string);
    
    string m2_string = "564";
    ListNode* m2 = generateListNode(m2_string);

    ListNode* finalList2 = addTwoNumbers(m1, m2);
    printNodeList(finalList2);
}
