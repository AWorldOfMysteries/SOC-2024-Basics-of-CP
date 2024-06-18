class Solution {
public:

    int findLower(vector<int>& nums, int target){
        int len = nums.size();
        int l = 0;
        int r = len-1;

        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(nums[mid] == target){
                if(mid == 0)
                    return mid;
                else if(nums[mid - 1] == target)
                    r = mid - 1;
                else
                    return mid;
            }

            else if(nums[mid] > target)
                r = mid - 1;

            else
                l = mid + 1;
        }

        return -1;
    }

    int findUpper(vector<int>& nums, int target){
        int len = nums.size();
        int l = 0;
        int r = len-1;

        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(nums[mid] == target){
                if(mid == len - 1)
                    return mid;
                else if(nums[mid + 1] == target)
                    l = mid + 1;
                else
                    return mid;
            }

            else if(nums[mid] > target)
                r = mid - 1;

            else
                l = mid + 1;
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(findLower(nums, target));
        ans.push_back(findUpper(nums, target));
        return ans;
    }

};
