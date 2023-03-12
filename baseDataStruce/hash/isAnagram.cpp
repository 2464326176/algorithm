/*
 * @Author: yh
 * @Date: 2022/11/14 22:17
 * @Description: 
 * @FilePath: isAnagram.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isAnagram(string str1, string str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    int count[26] {};
    for (auto it : str1) {
        count[it - 'a']++;
    }

    for (auto it : str2) {
        if (count[it - 'a'] == 0) {
            return false;
        }
        count[it -'a']--;
    }

    return true;
}

vector<vector<string>> groupAnagrams(vector<string> strs) {
    vector<vector<string>> ret;
    unordered_map<string, vector<string>> hashMap;
    for (auto it : strs) {
        string str = it;
        sort(str.begin(), str.end());
        hashMap[str].push_back(it);
    }

    for (auto it : hashMap) {
        ret.push_back(it.second);
    }
    return ret;
}


int main() {
    //cout << isAnagram("anagram", "nagaram");
    vector<string> vStr {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret = groupAnagrams(vStr);
    for (auto it : ret) {
        for (auto iit : it) {
            cout << iit << " ";
        }
        cout << endl;
    }

    return 0;
}