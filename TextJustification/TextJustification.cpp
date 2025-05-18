// TextJustification.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/text-justification/
#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
class Example {
public:
    vector<string> words = {};
    vector<string> expected = {};
    int maxWidth;
    Example* next;
    Example(const vector<string>& w, const vector<string>& e, int m)
        : words(w), expected(e), maxWidth(m), next(nullptr) { }
};

Example* ExampleInitialize() {
    Example* cursor;
    Example* start = cursor = new Example({ "This", "is", "an", "example", "of", "text", "justification." },
        { "This    is    an", "example  of text", "justification.  " }, 16);
    cursor->next = new Example({"What", "must", "be", "acknowledgment", "shall", "be"},
        { "What   must   be", "acknowledgment  ", "shall be        " }, 16);
    cursor = cursor->next;
    cursor->next = new Example({ "Science","is","what","we","understand","well","enough"
        ,"to","explain","to","a","computer.","Art","is","everything","else","we","do" },
        { "Science  is  what we", "understand      well", "enough to explain to",
        "a  computer.  Art is", "everything  else  we", "do                  " }, 20);

    return start;
}

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        queue<string> tmp;
        int leftSpaces = maxWidth;
        for (int i = 0; i < words.size(); ++i) {
            if (leftSpaces - tmp.size() + 1 > words[i].size()) {
                tmp.push(words[i]);
                leftSpaces -= words[i].size();
            }
            else {
                string resultline;
                int gap = leftSpaces;
                int remains = 0;
                if (tmp.size() > 2) {
                    gap = leftSpaces / (tmp.size() - 1);
                    remains = leftSpaces % (tmp.size() - 1);
                }
                string gapSpace(gap, ' ');
                int tmpCount = tmp.size();
                while (tmp.size() > 0) {
                    resultline += tmp.front();
                    tmp.pop();
                    if (tmp.size() != 0) {
                        resultline += gapSpace;
                        if (remains != 0) {
                            resultline += " ";
                            --remains;
                        }
                    }
                }
                if (tmpCount == 1) {
                    resultline += gapSpace;
                }
                result.push_back(resultline);
                --i;
                leftSpaces = maxWidth;
            }
        }
        if (leftSpaces != maxWidth) {
            string resultline;
            string lastSpaces(leftSpaces - tmp.size() + 1, ' ');
            while (tmp.size() > 0) {
                resultline += tmp.front();
                tmp.pop();
                if (tmp.size() != 0)
                    resultline += " ";
            }

            result.push_back(resultline + lastSpaces);
        }

        return result;
    }
};

void main() {
    Example* myExamples = ExampleInitialize();
    Solution sol;
    while (myExamples != nullptr) {
        vector<string> result = sol.fullJustify(myExamples->words, myExamples->maxWidth);
        string firstline;
        for (string line : result)
        {
            firstline += "[" + line + "], ";
        }
        firstline.erase(firstline.size() - 2, 2);
        cout << firstline << endl;

        string secondline;
        for (string line : myExamples->expected)
        {
            secondline += "[" + line + "], ";
        }
        secondline.erase(secondline.size() - 2, 2);
        cout << secondline << endl;

        myExamples = myExamples->next;
    }
}