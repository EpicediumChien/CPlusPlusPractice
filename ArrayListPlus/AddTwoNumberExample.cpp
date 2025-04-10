// CPlusPlusPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


struct Example {
    ListNode* left;
    ListNode* right;
    ListNode* answer;
    Example* next = NULL;
    Example(ListNode* left, ListNode* right, ListNode* answer) : left(left), right(right), answer(answer) {}
};

class Solution {
public:
    ListNode* CreateListNode(string number)
    {
        ListNode* nodePtr = NULL;
        ListNode* nodeCache = NULL;

        for (int i = 0; i < number.length(); i++)
        {
            nodePtr = new ListNode(number[i] - '0', nodeCache);
            nodeCache = nodePtr;
        }

        return nodePtr;
    }

    Example* InitExamples()
    {
        Example* examplePtr;
        Example* exampleInit;

        ListNode* sample1 = CreateListNode("342");
        ListNode* sample2 = CreateListNode("465");
        ListNode* sum = CreateListNode("807");

        examplePtr = new Example(sample1, sample2, sum);
        exampleInit = examplePtr;

        sample1 = CreateListNode("0");
        sample2 = CreateListNode("0");
        sum = CreateListNode("0");

        examplePtr->next = new Example(sample1, sample2, sum);
        examplePtr = examplePtr->next;

        sample1 = CreateListNode("9999999");
        sample2 = CreateListNode("9999");
        sum = CreateListNode("10009998");

        examplePtr->next = new Example(sample1, sample2, sum);
        examplePtr = examplePtr->next;

        return exampleInit;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) +
                (l2 ? l2->val : 0) + carry;

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummyHead->next;
    }
};

int main()
{
    Solution sol;
    Example* exampleInit = sol.InitExamples();
    while (exampleInit!=NULL)
    {
        ListNode* result = sol.addTwoNumbers(exampleInit->left, exampleInit->right);
        ListNode* answer = exampleInit->answer;
        while (result!=NULL && answer!=NULL)
        {
            if (result->val != answer->val)
            {
                cout << "Wrong answer at result " + to_string(result->val) + " answer " + to_string(answer->val) + "\n";
                return 0;
            }
            result = result->next;
            answer = answer->next;
        }
        exampleInit = exampleInit->next;
    }
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
