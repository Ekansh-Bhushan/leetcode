class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        map<int,int> mpp;

        while(r < n) {
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]] == 0){
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }

            }
            maxLen = max(maxLen , r-l+1);
            r++;
        }
        return maxLen;
    }
};