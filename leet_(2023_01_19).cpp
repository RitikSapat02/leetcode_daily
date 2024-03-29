class Solution {
public:
    #define ll long long
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<ll> mp(k);
        ll tot = 0; int ans = 0;
        mp[0] = 1;
        for(int num: nums){
            tot += num;
            int mod = (tot % k + k) % k;
            mp[mod]++;
        }
        for (int n: mp)
            ans += (n * (n-1) * 0.5);
        return ans;
    }
};