class Solution {
public:
    // Checks Increasing Vector
    bool checkIncreasing(vector<int>output){
        vector<int>temp = output;
        sort(output.begin(),output.end());
        return (output == temp) ? true : false;
    }

    void solve(vector<int>& nums,vector<int>output,vector<vector<int>>&subSeq,map<vector<int>,int>&map,int index){
        if( index >= nums.size()){
            if(output.size()>=2 && checkIncreasing(output) && map.find(output) == map.end())
            {           // checks duplicate and checkIncreasing
                subSeq.push_back(output);
                map[output]++;
            }
            return;
        }
        // simple recursion
        solve(nums,output,subSeq,map,index+1);
        output.push_back(nums[index]);
        solve(nums,output,subSeq,map,index+1);

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>subSeq;
        vector<int>output;  
        int index = 0;
        map<vector<int>,int>map;
        solve(nums,output,subSeq,map,index);
        cout<<subSeq.size();
        return subSeq;

    }
};