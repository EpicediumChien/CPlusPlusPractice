// SwapNodesInPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/swap-nodes-in-pairs/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;     
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head != NULL && head->next != NULL)
        {
            ListNode* buffer = NULL;
            ListNode* cursor = head;
            head = cursor->next;
            while (cursor != NULL)
            {
                if(buffer==NULL)
                {
                    buffer = new ListNode(cursor->val);
                    buffer->next = cursor->next->next;
                } 
                else if(cursor->next!=NULL)
                {
                    buffer->next = cursor->next;
                    buffer = new ListNode(cursor->val);
                    buffer->next = cursor->next->next;
                }
                else
                {
                    break;
                }
                cursor = cursor->next;
                cursor->next = buffer;
                cursor = cursor->next->next;
            }
        }

        return head;
    }
};

int main()
{
    //ListNode* testCase = new ListNode(4);
    //testCase = new ListNode(3, testCase);
    //testCase = new ListNode(2, testCase);
    //testCase = new ListNode(1, testCase);
    //int answer[4] = {2, 1, 4, 3};
    ListNode* testCase = new ListNode(3);
    testCase = new ListNode(2, testCase);
    testCase = new ListNode(1, testCase);
    int answer[3] = { 2, 1, 3 };
    Solution sol;
    ListNode* result = sol.swapPairs(testCase);
    string output = "[";
    ListNode* temp = result;
    while (temp != NULL)
    {
        output += to_string(temp->val) + ",";
        temp = temp->next;
    }
    if (output.substr(output.length() - 1, 1) == ",")
    {
        output = output.substr(0, output.length() - 1);
    }
    output += "]";
    cout << output;
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
