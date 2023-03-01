class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        multiset<int>s(nums.begin(),nums.end());
        vector<int>v1(s.begin(),s.end());
       

        return v1;
    }
};