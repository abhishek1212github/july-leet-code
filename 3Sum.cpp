/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {    
        vector<vector<int>> result;
        if(nums.size()<3)
            return result;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int target= -nums[i];
            int l=i+1;
            int r=nums.size()-1;
            
            while(l<r)
            {
                
                
                if(nums[l]+nums[r]==target)
                {
                    result.push_back({-target,nums[l],nums[r]});
                    l++;r--;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                    
                }
                else if(nums[l]+nums[r]>target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return result;
        
    }
};
