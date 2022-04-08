#include <iostream>
#include <string.h>
#include <unordered_map>

// using namespace std;

/* PLAN:
 *  iterate through string and keep supplying a hashtable with the current char
 *  as key and the current index as value. If the key we want to add already
 *  exists (https://en.cppreference.com/w/cpp/container/unordered_map/count),
 *  take the index of the first occurence (value of hashtable), clear the table
 *  and start the process from this index over again.
 */

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> m;
        int cnt = 0;
        int max = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            std::cout << i << " " << c << std::endl;
            if (m.count(c)) {
                i = m[c]; // start again at char after first occurence of c (i++ causes this)
                m.clear();
                cnt = 0;
            } else {
                cnt++;
                if (cnt > max) {
                    max = cnt;
                }
                m[c] = i;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("pwwkew");
    return 0;
}

