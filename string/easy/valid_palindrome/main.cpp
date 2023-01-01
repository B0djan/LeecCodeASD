#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.empty()) {
            return true;
        }
        std::string explanation;
        for (auto c : s) {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                explanation.push_back(static_cast<char>(std::tolower(c)));
            }
        }
        size_t i = 0;
        size_t j = explanation.size()-1;
        for (; i < j; ++i, --j) {
            if (explanation[i] != explanation[j]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::string str{"a"};
    Solution s;
    std::cout << s.isPalindrome(str) << std::endl;
    return 0;
}