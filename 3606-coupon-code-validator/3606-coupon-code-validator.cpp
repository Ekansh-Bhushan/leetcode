class Solution {
    bool isValidCode(string &s) {
        int n = s.length();
        if(n == 0) return false;
        for(int i = 0 ; i < n ;i++) {
            char ch = s[i];
            if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch == '_')) continue;
            else return false;
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        map<string,int> mpp = {{"electronics",0}, {"grocery",1}, {"pharmacy",2}, {"restaurant",3}};

        vector<pair<int,string>> temp;

        for(int i = 0 ; i < n ; i++) {
            if(isActive[i]) {
                if(mpp.count(businessLine[i]) && isValidCode(code[i])){
                    temp.push_back({mpp[businessLine[i]],code[i]});
                }
            }
        }

        sort(temp.begin(),temp.end());

        vector<string> ans;

        for(int i = 0 ; i < temp.size(); i++) {
            ans.push_back(temp[i].second);
        }
        return ans;

    }
};