// TextJustification.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/text-justification/
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Example {
public:
    string num1;
    string num2;
    string result;
    Example* next;
    Example(string str1, string str2, string res)
        : num1(str1), num2(str2), result(res) {
    }
};

Example* ExampleInitialize() {
    Example* cursor;
    Example* start = cursor = new Example("79362", "217", "17221554");

    return start;
}

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> result(n + m, 0);

        // Multiply each digit and add to the result
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j, pos2 = i + j + 1;
                int sum = mul + result[pos2];

                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }

        // Convert result to string, skipping leading 0s
        string product = "";
        for (int digit : result) {
            if (!(product.empty() && digit == 0)) {
                product += (digit + '0');
            }
        }

        return product.empty() ? "0" : product;

    }
};

void main() {
    Example* myExamples = ExampleInitialize();
    Solution sol;
    while (myExamples != nullptr) {
        string result = sol.multiply(myExamples->num1, myExamples->num2);

        cout << "My Ans: \"" << result << "\", Expected: \"" << myExamples->result << "\"" << endl;

        myExamples = myExamples->next;
    }
}