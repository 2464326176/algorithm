/*
 * @Author: yh
 * @Date: 2022-11-29 00:36:47
 * @LastEditTime: 2022-12-01 00:44:47
 * @Description:
 * @FilePath: \algorithm\practice\tree\trie\trie.cpp
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
    Trie() { root = new TrieNode; }

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

void Trie::insert(std::string word) {
    TrieNode *node = root;
    for (const auto &ch : word) {
        if (node->childNode[ch - 'a'] == nullptr) {
            node->childNode[ch - 'a'] = new TrieNode();
        }

        node = node->childNode[ch - 'a'];
    }

    node->value = node->isWord = true;
}

void Trie::insert(std::string word, int value) {
    TrieNode *node = root;
    for (const auto &ch : word) {
        if (node->childNode[ch - 'a'] == nullptr) {
            node->childNode[ch - 'a'] = new TrieNode();
        }

        node = node->childNode[ch - 'a'];
    }

    node->value = value;
    node->isWord = true;
}

bool Trie::search(std::string word) {
    TrieNode *node = root;
    for (const auto &ch : word) {
        if (node->childNode[ch - 'a'] == nullptr) {
            return false;
        }

        node = node->childNode[ch - 'a'];
    }

    return node->isWord;
}

int Trie::sum(std::string prefix) {
    TrieNode *node = root;
    for (const auto it : prefix) {
        if (node->childNode[it - 'a'] == nullptr) {
            return 0;
        }

        node = node->childNode[it - 'a'];
    }

    return getSum(node);
}

int Trie::getSum(TrieNode *node) {
    if (node == nullptr) {
        return 0;
    }

    int ret = node->value;

    for (TrieNode *child : node->childNode) {
        ret += getSum(child);
    }

    return ret;
}

bool Trie::startsWith(std::string prefix) {
    TrieNode *node = root;
    for (const auto &ch : prefix) {
        if (node->childNode[ch - 'a'] == nullptr) {
            return false;
        }

        node = node->childNode[ch - 'a'];
    }

    return true;
}

std::string Trie::findPrefix(std::string words) {
    std::string prefix;
    TrieNode *node = root;

    for (const auto &ch : words) {
        if (node->isWord || node->childNode[ch - 'a'] == nullptr) {
            break;
        }

        prefix += ch;
        node = node->childNode[ch - 'a'];
    }

    return node->isWord ? prefix : words;
}

std::string Trie::replaceWords(std::vector<std::string> dicts, std::string sentence) {
    for (const auto &dict : dicts) {
        insert(dict);
    }

    std::string ret;
    std::string str = sentence;
    std::string::size_type it;
    while ((it = str.find(" ")) != std::string::npos) {
        std::string prefix = findPrefix(str.substr(0, it));
        ret += prefix + " ";
        str = str.substr(it + 1);
    }

    std::string prefix = findPrefix(str.substr(0, it));
    ret += prefix;
    return ret;
}

int main() {
    Trie trie;
    /*trie.insert("boy");
    trie.insert("boss");
    trie.insert("cowboy");
    trie.insert("cow");

    std::cout << trie.search("cow") << std::endl;
    std::cout << trie.search("boss") << std::endl;
    std::cout << trie.startsWith("bo") << std::endl;*/

    /*std::vector<std::string> dicts {"cat", "bat", "rat"};
    std::string sentence {"the cattle was rattled by the battery!!!"};
    std::cout << trie.replaceWords(dicts, sentence);*/

    trie.insert("happy", 3);
    std::cout << trie.sum("hap") << std::endl;
    trie.insert("hap", 2);
    std::cout << trie.sum("hap") << std::endl;
    return 0;
}