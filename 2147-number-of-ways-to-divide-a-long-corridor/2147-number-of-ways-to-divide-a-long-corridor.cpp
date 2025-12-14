class Solution {
public:
int M = 1e9+7;
    int numberOfWays(string corridor) {
        int n = corridor.size();

        vector<int> arr;
        for(int i = 0 ; i < n ; i++) {
            if(corridor[i] == 'S') arr.push_back(i);
        }

        if(arr.size()%2 != 0 || arr.size() == 0) return 0;

        long long res = 1;
        int prevIndex = arr[1];
        for(int i = 2; i < arr.size() ; i+=2) {
            int len = arr[i] - prevIndex;
            res = (res*len)%M;
            prevIndex = arr[i+1];
        } 

        return res;
    }
};