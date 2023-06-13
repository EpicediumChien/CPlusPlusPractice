// CPlusPlusPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "NodeListAddTwoNumber.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* firstNode = new ListNode();
        ListNode* temp = firstNode;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            cout << to_string(sum) + " " + to_string(carry) + "\n";
            carry = sum / 10;

            temp->val = sum % 10;

            if (l1 == NULL && l2 == NULL && carry == 0)
                break;

            temp->next = new ListNode();
            temp = temp->next;
        }
        return firstNode;
    }
};

int main()
{
    cout << "Hello World!\n";
    Example* exampleInit = InitExamples();
    Solution sol;
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
