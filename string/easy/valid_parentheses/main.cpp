#include <stack>
#include <string>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (c == ')' && (st.empty() || st.top() != '(')) {
                    return false;
                } else if (c == ']' && (st.empty() || st.top() != '[')) {
                    return false;
                } else if (c == '}' && (st.empty() || st.top() != '{')) {
                    return false;
                }
                st.pop();
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    std::string str;
    std::cin >> str;
    std::cout << s.isValid(str) << std::endl;
    return 0;
}