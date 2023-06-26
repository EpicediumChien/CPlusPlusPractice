// MergeKSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* tempNode;
        ListNode* Dummy = new ListNode();
        ListNode* cursorNode = Dummy;
        while (lists.size() > 0)
        {
            int cursorIdx = 0;
            tempNode = lists[0];
            if (tempNode != NULL) {
                for (int i = 0; i < lists.size(); i++)
                {
                    if (lists[i]!=NULL
                        && lists[i]->val <= tempNode->val)
                    {
                        tempNode = lists[i];
                        cursorIdx = i;
                    }
                }
                cursorNode->next = new ListNode(tempNode->val);
                cursorNode = cursorNode->next;
                lists[cursorIdx] = lists[cursorIdx]->next;
                if (lists[cursorIdx] == NULL)
                {
                    lists.erase(lists.begin() + cursorIdx);
                }
            }
            else {
                lists.erase(lists.begin());
            }
        }

        return Dummy->next;
    }
};

int main()
{
    //ListNode* listNode1 = new ListNode(1);
    //ListNode* cursor = listNode1;
    //cursor->next = new ListNode(4);
    //cursor = cursor->next;
    //cursor->next = new ListNode(5);
    //ListNode* listNode2 = new ListNode(1);
    //cursor = listNode2;
    //cursor->next = new ListNode(3);
    //cursor = cursor->next;
    //cursor->next = new ListNode(4);
    //ListNode* listNode3 = new ListNode(2);
    //cursor = listNode3;
    //cursor->next = new ListNode(6);
    //vector<ListNode*> testCase { listNode1, listNode2, listNode3 };
    //ListNode* answer = new ListNode(1);
    //cursor = answer;
    //cursor->next = new ListNode(1);
    //cursor = cursor->next;
    //cursor->next = new ListNode(2);
    //cursor = cursor->next;
    //cursor->next = new ListNode(3);
    //cursor = cursor->next;
    //cursor->next = new ListNode(4);
    //cursor = cursor->next;
    //cursor->next = new ListNode(4);
    //cursor = cursor->next;
    //cursor->next = new ListNode(5);
    //cursor = cursor->next;
    //cursor->next = new ListNode(6);
 
    //vector<ListNode*> testCase { };
    //ListNode* answer = new ListNode();
 
    //vector<ListNode*> testCase { { } };
    //ListNode* answer = new ListNode();

    ListNode* listNode1 = new ListNode(2);
    ListNode* listNode2 {};
    ListNode* listNode3 = new ListNode(-1);
    vector<ListNode*> testCase { listNode1, listNode2, listNode3 };
    ListNode* answer = new ListNode(-1);
    ListNode* cursor = answer;
    cursor->next = new ListNode(2);

    Solution sol;
    ListNode* result = sol.mergeKLists(testCase);
    string output = "[";
    while (result != NULL)
    {
        output += to_string(result->val) + ", ";
        result = result->next;
    }
    if (output.length() >= 2
        && output.substr(output.length() - 2, 2) == ", ")
    {
        output = output.substr(0, output.length() - 2);
    }
    cout << output << "]";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
