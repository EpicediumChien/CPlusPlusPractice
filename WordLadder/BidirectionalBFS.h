#ifndef BI_BFS_H
#define BI_BFS_H

#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::unordered_set wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return 0;
    int wordLen = beginWord.size();

    int steps = 2; // begin & end
    std::unordered_set<std::string> head, tail, * phead, * ptail;
    head.insert(beginWord);
    tail.insert(endWord);

    while (!head.empty() && !tail.empty()) {
      if (head.size() <= tail.size()) {
        phead = &head;
        ptail = &tail;
      }
      else {
        phead = &tail;
        ptail = &head;
      }

      std::unordered_set<std::string> nextLevel;
      for (std::string word : *phead) {
        for (int i = 0; i < wordLen; ++i) {
          char originChar = word[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            word[i] = c;
            if (ptail->count(word)) return steps;

            if (wordSet.count(word)) {
              nextLevel.insert(word);
              wordSet.erase(word);
            }
          }
          word[i] = originChar;
        }
      }
      *phead = nextLevel;
      ++steps;
    }
    return 0;
  }
};

#endif BI_BFS_H