/*
 * @Author: yh
 * @Date: 2022-11-29 00:36:47
 * @LastEditTime: 2023-03-12 21:06:12
 * @Description:
 * @FilePath: \algorithm\baseDataStruce\tree\trie\trie.h
 */
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    int value{};
    bool isWord{};
    TrieNode *childNode[26]{};
};

class Trie {
  public:
    Trie() { root = new TrieNode(); }

    void insert(std::string word);
    void insert(std::string word, int value);
    bool search(std::string word);
    bool startsWith(std::string prefix);

    int sum(std::string prefix);
    int getSum(TrieNode *node);
    std::string findPrefix(std::string prefix);
    std::string replaceWords(std::vector<std::string> dicts, std::string sentence);

  private:
    TrieNode *root;
};
