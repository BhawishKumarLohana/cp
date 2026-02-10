import java.util.ArrayList;
import java.util.List;

class Solution {

    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        int current_sum = 0;
        List<Integer> subArr = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {

            current_sum += nums[i];

            if (current_sum < 0) {

                if(current_sum>=sum){
                    sum=current_sum;
                }
                current_sum=0;
                subArr.clear();
                continue;
            } else {
                if (current_sum >= sum) {
                    sum = current_sum;
                    subArr.add(nums[i]);
                }
            }

        }

        return sum;


    }

}