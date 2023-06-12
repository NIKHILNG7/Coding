class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> retVal(nums.size(), 1);
        
        int curProduct = 1;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            curProduct *= nums[i];
            retVal[i + 1]*= curProduct;
        }
        
        curProduct = 1;
        
        for (int i = nums.size() - 1; i >= 1; --i) {
            curProduct *= nums[i];
            retVal[i - 1] *= curProduct;
        }
        
        return retVal;
    }
};



