// ReverseNodesInK-Group.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
private:
    ListNode* reverseListNode(ListNode* head, int k) {
        ListNode* cursor = head;
        vector<ListNode*> vec {};
        for (int i = 0; i < k; i++)
        {
            vec.push_back(cursor);
            cursor = cursor->next;
        }
        ListNode* tail = vec[vec.size()-1]->next;
        for (int i = k-1; i > 0; i--)
        {
            vec[i]->next = vec[i - 1];
        }
        vec[0]->next = tail;

        return vec[vec.size() - 1];
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool validFlag = false;
        bool saveHeaderFlag = true;
        ListNode* cursor = head;
        ListNode* tempCursor = cursor;
        ListNode* previousTail{};
        while (tempCursor != NULL)
        {
            validFlag = false;
            tempCursor = cursor;
            for (int i = 0; i < k && tempCursor != NULL; i++)
            {
                tempCursor = tempCursor->next;
                if (i == k - 1)
                {
                    validFlag = true;
                }
            }
            if (tempCursor!=NULL || validFlag) {
                ListNode* reversedHead = reverseListNode(cursor, k);
                if (saveHeaderFlag)
                {
                    head = reversedHead;
                    saveHeaderFlag = false;
                }
                else
                {
                    previousTail->next = reversedHead;
                }
                previousTail = cursor;
                cursor = cursor->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode* testCase = new ListNode(1);
    ListNode* cursor = testCase;
    cursor->next = new ListNode(2);
    cursor = cursor->next;
    cursor->next = new ListNode(3);
    cursor = cursor->next;
    cursor->next = new ListNode(4);
    cursor = cursor->next;
    cursor->next = new ListNode(5);
    cursor = cursor->next;
    int k = 2;
    string answer = "[2, 1, 4, 3, 5]";
 
    //ListNode* testCase = new ListNode(1);
    //ListNode* cursor = testCase;
    //cursor->next = new ListNode(2);
    //int k = 2;
    //string answer = "[2, 1]";

    Solution sol;
    ListNode* result = sol.reverseKGroup(testCase, k);
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
