class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        stringstream ss(s);
        string token;

        while(ss >> token) {
            st.push(token);
        }

        string res = "";

        while(!st.empty()) {
            string word = st.top();
            res += word + " ";
            st.pop();
        }
        res.pop_back();
        return res;
    }
};