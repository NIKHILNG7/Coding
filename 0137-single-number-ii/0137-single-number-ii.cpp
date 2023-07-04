class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Initialize variables to store the bits that appear once and twice
        int ones = 0;
        int twos = 0;

        // Loop through the array of numbers
        for (auto num : nums) {
            // Update ones and twos using bit manipulation
            // XOR operation will toggle the bits that are different
            // AND operation will keep the bits that are same
            // NOT operation will flip the bits
            ones = (ones ^ num) & ~twos; // Add the new bits to ones and remove the common bits with twos
            twos = (twos ^ num) & ~ones; // Add the new bits to twos and remove the common bits with ones
        }

        // Return ones as the answer
        return ones;
    }
};
