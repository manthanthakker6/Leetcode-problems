





#include <stack>

class Solution {
public:
    int minAddToMakeValid(std::string str) {
        stack<char> s;

        for (char ch : str) {
            if (ch == '(') {
                s.push(ch);
            } else {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    s.push(ch);
                }
            }
        }

        return s.size();
    }
};

