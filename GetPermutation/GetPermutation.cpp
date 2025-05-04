// GetPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <numeric>  // for std::iota
using namespace std;

class Example {
public:
    int n, k;
    string result;
    Example* next;
    Example(int n, int k, string res) : n(n), k(k), result(res) {}
};

class Solution {
public:
    Example* example;
    Example* InitExamples()
    {
        example = new Example(3, 3, "213");
        Example* cursor = example;
        cursor->next = new Example(4, 9, "2314");
        cursor = cursor->next;
        cursor->next = new Example(3, 1, "123");
        return example;
    }
    string getPermutation(int n, int k) {
        vector<int> nList(n);
        iota(nList.begin(), nList.end(), 1);  // Fill 1..n
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        string result;
        k--;  // convert to zero-based index
        for (int i = n; i >= 1; --i) {
            int idx = k / factorial[i - 1];
            result += to_string(nList[idx]);
            nList.erase(nList.begin() + idx);
            k %= factorial[i - 1];
        }
        return result;
    }
};

void main()
{
    Solution sol;
    Example* exampleInit = sol.InitExamples();
    while (exampleInit != nullptr)
    {
        string result = sol.getPermutation(exampleInit->n, exampleInit->k);
        if (result != exampleInit->result) {
            throw std::runtime_error("result is not match: " + exampleInit->result);
        }
        exampleInit = exampleInit->next;
    }
    cout << "Result is good!" << endl;
    return;
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
