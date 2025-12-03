class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum=((1LL * n)*(n+1))/2;
        long long diff=sum-target;
        
        if(diff<0 || diff%2==1){
            return {};
        }

        long long need=diff/2;
        
        if(need>sum){
            return {};
        }
        vector<int>Neg;
        vector<int>Pos;

        vector<int>res;
        for(int i=n;i>0;i--){
            if(i<=need){
                Neg.push_back(i);
                need-=i;
            }
            else{
                Pos.push_back(i);
            }
        }
        
        for(auto i : Neg){
            res.push_back(-i);
        }
        for(int i=Pos.size()-1;i>=0;i--){
            res.push_back(Pos[i]);
        }
        
        return res;
    }
};