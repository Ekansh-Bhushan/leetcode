class Solution {
    string normalize(string s) {
        int l = s.length();

        map<char,int> mpp;
        string ans = "";
        for(int i = 0 ;i < l ; i++) {
            if(mpp.find(s[i]) == mpp.end()) {
                mpp[s[i]] = mpp.size();
            }
            ans += to_string(mpp[s[i]])  + ".";
        }
        return ans;
    }
public:
    bool isIsomorphic(string s, string t) {
        string p = normalize(s);
        string q = normalize(t);

        return p == q ? true : false;
    }
};