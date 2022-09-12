#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str("abcd");
    string str1("klkk");

    string sr;
    set_intersection(str.begin(), str.end(), str1.begin(), str1.end(), inserter(sr, sr.begin()));

    cout << sr << endl;
    return 0;
}
