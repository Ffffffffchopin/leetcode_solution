class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

       int count=0;
       vector<int> sums(k,0);
       sums[0]++;
       int curr_sum=0;
       for(int num : nums){
           curr_sum=(curr_sum+num%k+k)%k;
           count+=sums[curr_sum];
           sums[curr_sum]++;
       }
       return count;

    }
};