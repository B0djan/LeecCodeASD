#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <cassert>

class Solution {
public:
    size_t romanToInt(const std::string &s) {
        if (s.empty()) {
            return 0;
        }
        std::map<char, size_t> map {
                {'I', 1},
                {'X', 10},
                {'C', 100},
                {'M', 1000},
                {'V', 5},
                {'L', 50},
                {'D', 500}
        };
        size_t result = map[s[s.size() - 1u]];
        for (size_t k = s.size(); k > 1; --k) {
            size_t j = k - 1;
            size_t i = j - 1;   // j - правый конец
            if (map.at(s[i]) < map.at(s[j])) {
                result -= map.at(s[i]);
            } else {
                result += map.at(s[i]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    assert(s.romanToInt("IV") == 4);
    assert(s.romanToInt("VI") == 6);
    return 0;
}