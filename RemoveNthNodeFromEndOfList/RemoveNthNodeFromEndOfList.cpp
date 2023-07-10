// RemoveNthNodeFromEndOfList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* preTemp {};
        int listLength = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            listLength++;
        }
        temp = head;
        for (int i = 0; i < listLength; i++)
        {
            if (listLength - n == 0)
            {
                head = temp->next;
                break;
            }
            else if(i == listLength - n)
            {
                preTemp->next = preTemp->next->next;
                break;
            }
            else
            {
                preTemp = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};

int main()
{
    ListNode* testCase = new ListNode(1);
    int n = 1;
    ListNode* answer = new ListNode();
    Solution sol;
    ListNode* result = sol.removeNthFromEnd(testCase, n);
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
