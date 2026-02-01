#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::unordered_set wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return 0;
    int wordLen = beginWord.size();

    std::queue<std::pair<std::string, int>> q;
    q.push({ beginWord, 1 });
    int steps = 1;
    while (!q.empty()) {
      auto [toWord, steps] = q.front();
      q.pop();

      if (toWord == endWord)
        return steps;

      for (int i = 0; i < wordLen; ++i) {
        char originChar = toWord[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          toWord[i] = c;
          if (wordSet.find(toWord) != wordSet.end()) {
            q.push({ toWord, steps + 1 });
            wordSet.erase(toWord);
          }
        }
        toWord[i] = originChar;
      }
    }
    return 0;
  }
};

#endif BFS_H