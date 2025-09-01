class Solution {
    unordered_map<char, string> mpp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"}, {'9',"wxyz"} };
    vector<string> ans;


    void solve(int index, string& digits, string& temp) {
        if(index == digits.length()) {
            ans.push_back(temp);
        }

        char ch = digits[index];
        string str = mpp[ch];

        for(int i=0; i < str.length() ;i++) {
            temp.push_back(str[i]);
            solve(index+1,digits,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        

        if(digits.length() == 0) return {};
        string temp = "";
        solve(0,digits,temp);
        return ans;
    }
};