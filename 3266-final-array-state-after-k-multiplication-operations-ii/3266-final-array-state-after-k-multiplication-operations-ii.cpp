const int mod = 1e9+7;
#define ll long
class Solution {
public:
 ll add(ll x, ll y) {
        x %= mod;
        y %= mod;
        return (x + y)%mod;
    }
    ll sub(ll x, ll y) {
        x %= mod;
        y %= mod;
        return (x - y + mod)%mod;
    }
    ll mult(ll x, ll y) {
        x %= mod;
        y %= mod;
        return (x * y) % mod;
    }
    ll power(ll x, ll y){
        if (y == 0) return 1;
        if (y & 1) return mult(x, power(x, y - 1));
        return power(mult(x, x), y / 2);
    }

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int n = nums.size();
        if(multiplier == 1)
            return nums;
        
        multiset<pair<ll,ll>> st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert({1ll*nums[i],i});
        }
        int op = 0;
        
        int max_element1 = *max_element(nums.begin(),nums.end());
        ll idx = -1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == max_element1)
            {
                idx = i;
            }
        }
        while(op<k)
        {
            op++;
            auto top = *st.begin();
            st.erase(st.begin());
            ll val = top.first*multiplier;
            st.insert({val,top.second});
            
            if(top.second == idx) break;

            // Breakpoint index after with at every Nth interval the pattern can be repeated
        }
        
        k -= op;
        
        int time = k/n;
        vector<pair<ll,ll>> temp;
        for(int i=0;i<n;i++)
        {
            auto top = *st.begin();
             st.erase(st.begin());
             
             ll val = top.first;
             ll index = top.second;
             
            ll computer = mult(val,power(multiplier,time));
             temp.push_back({computer,index});
            
        }
        

        // Remaining values
        for(int i=0;i<k%n;i++)
        {
            temp[i].first = mult(temp[i].first,multiplier);
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
          ans[temp[i].second] = int(temp[i].first%mod);
        }
        
        return ans;
        
    }
};