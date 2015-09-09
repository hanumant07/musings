import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;


public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int iter = 0;

        while(iter < nums.length) {
            if (!map.containsKey(nums[iter]))
                map.put(nums[iter], iter);
            else if (iter - map.get(nums[iter]) <= k)
                return true;
            else
                map.put(nums[iter], iter);
            iter++;
        }
        return false;
    }
}