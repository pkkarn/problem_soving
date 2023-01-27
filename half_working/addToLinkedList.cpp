#include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /**
            - Reverse both linked list one by one. in O(m+n);
            - and store item from both of them one by one as string 

            // Just loop throught each linked list one by one and store it inside a string
            // Generate string like currItem + mainItem // 2 - 42 - 342
            // And add at last and store them inside new linked list
            
        **/
    
        ListNode* curr = l1;
        string stringL1 = "";
        ListNode* curr2 = l2;
        string stringL2 = "";

        while(curr) {
            stringL1 = to_string(curr->val) + stringL1;
            curr = curr->next;
        }

        while(curr2) {
            stringL2 = to_string(curr2->val) + stringL2;
            curr2 = curr2->next;
        }

        cout << stringL1 << endl;
        cout << stringL2 << endl;

        string finalAdd = to_string(stoi(stringL1) + stoi(stringL2));

        ListNode* final_result {nullptr};
        for(int i = 0; i < finalAdd.size(); i++) {
            char currChar = finalAdd[i];
            int currVal = atoi(&currChar);
            ListNode* currLinked = new ListNode(currVal);
            if(!final_result) {
                final_result = currLinked;
            } else {
                currLinked->next = final_result;
                final_result = currLinked;
            }
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