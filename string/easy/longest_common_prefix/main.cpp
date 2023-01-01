#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string> strs) {
        if (strs.empty()) {
            return {};
        } else if (strs.size() == 1) {
            return strs.front();
        }
        auto firstString = strs.front();
        for (const auto &curString : strs) {
            size_t i = 0, j = 0;
            for (; i < firstString.size() && j < curString.size() && firstString[i] == curString[j];
                   ++i, ++j);
            firstString = firstString.substr(0, j);
        }
        return firstString;
    }
};

int main() {
    std::vector<std::string> vec {"flower", "flow", "fl", "flower"};
    Solution s;
    std::cout << s.longestCommonPrefix(vec) << std::endl;
    return 0;
}