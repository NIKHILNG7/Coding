class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int ans=0;
        int mini=0;

        while(left<right){
        int dist=right-left; 
        if(height[right] > height[left]){

           
            mini=height[left];
            left++;
        }
        else {

            
            mini=height[right];
            right--;
        }
        ans=max(ans,mini *dist);


        }

        return ans;
    }
};