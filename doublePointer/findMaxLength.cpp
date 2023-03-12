#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findMaxLength(const vector<int> &numbers) {
    std::unordered_map<int, int> sumToIndex;
    // sumToIndex.insert({0, -1});
    int sum = 0;
    int maxLength = 0;
    int length = numbers.size();
    std::unordered_map<int, int>::iterator iter;
    for (int i = 0; i < length; ++i) {
        sum += numbers[i] == 0 ? -1 : 1;
        iter = sumToIndex.find(sum);
        if (iter != sumToIndex.end()) {
            maxLength = std::max(maxLength, iter->second);
        } else {
            sumToIndex.emplace(sum, i);
        }
    }
    return maxLength;
}
int main() {
    vector<int> numbers{0, 1, 0};
    cout << findMaxLength(numbers) << endl;

    return 0;
}