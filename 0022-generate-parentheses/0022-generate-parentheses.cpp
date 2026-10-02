class Solution {
    vector<string> ans;

    bool isValidParenthesis(string curr) {
        stack<char> st;

        for (char ch : curr) {
            if (ch == '(') {
                st.push(ch);
            } 
            else if (ch == ')') {
                if (st.empty()) return false;
                st.pop();
            }
        }

        return st.empty(); 
    }

public:
    void solve(string curr, int n ) {
        if(2*n == curr.length()) {
            if(isValidParenthesis(curr)) {
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    

    vector<string> generateParenthesis(int n) {
        
        solve("",n);
        return ans;
    }
};