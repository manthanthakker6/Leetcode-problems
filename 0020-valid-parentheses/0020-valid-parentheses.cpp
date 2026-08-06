

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // Push opening brackets into the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                // If stack is empty when seeing a closing bracket, it's invalid
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                // Check if closing bracket matches top opening bracket
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            } 
        }
        
        // String is valid only if all brackets were closed
        return st.empty();
    }
};