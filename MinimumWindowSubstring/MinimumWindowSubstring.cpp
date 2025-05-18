// TextJustification.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/text-justification/
#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
class Example {
public:
    string s;
    string t;
    string result;
    Example* next;
    Example(string str, string tar, string res)
        : s(str), t(tar), result(res) {}
};

Example* ExampleInitialize() {
    Example* cursor;
    Example* start = cursor = new Example("ADOBECODEBANC", "ABC", "BANC");
    cursor->next = new Example("a", "a", "a");
    cursor = cursor->next;
    cursor->next = new Example("a", "aa", "");

    return start;
}

class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX;
        int n = s.size();
        int l = 0, r = 0; int sIndex = -1;
        vector<int> hash(256, 0);
        for (int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }
        int cnt = 0;
        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            while (cnt == t.size()) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }

            r++;
        }
        if (sIndex == -1) {
            return "";
        }
        return s.substr(sIndex, minlen);
    }
};

void main() {
    Example* myExamples = ExampleInitialize();
    Solution sol;
    while (myExamples != nullptr) {
        string result = sol.minWindow(myExamples->s, myExamples->t);

        cout << "My Ans: \"" << result << "\", Expected: \"" << myExamples->result << "\"" << endl;

        myExamples = myExamples->next;
    }
}