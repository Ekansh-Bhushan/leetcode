class Solution {
    bool allZero(vector<int>& arr) {
        for(int i = 0; i < 26; i++) {
            if(arr[i] != 0) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();

        vector<int> arr(26,0);

        for(int i = 0; i < k ; i++) {
            char ch = p[i];
            arr[ch-'a']++;
        }

        int i = 0;
        int j = 0;
        vector<int> ans;

        while(j < n) {
            arr[s[j]-'a']--;

            if(j-i+1 == k) {
                if(allZero(arr)){
                    ans.push_back(i);
                }

                arr[s[i]-'a']++;
                i++;
            }

            j++;
        }
        return ans;
    }
};