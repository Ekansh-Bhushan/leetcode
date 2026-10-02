class Solution {
public:
    void backtracking(vector<string> &ans, int open , int close , int n , string curr_string){
        if(curr_string.length() == 2*n) {
            ans.push_back(curr_string);
            return;
        }

        if(open < n) backtracking(ans,open+1,close,n,curr_string+"(");
        if(close < open) backtracking(ans,open,close+1,n,curr_string+")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(ans,0,0,n,"");
        return ans;
    }
};