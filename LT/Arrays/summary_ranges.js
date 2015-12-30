/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/


/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    var result = [];
    var start = 0;
    var range = start + 1;
    var current_range = "";
    if (nums === null)
        return result;
    if (nums.length === 1) {
        result.push(nums[0].toString());
        return result;
    }
    if (nums.length === 2) {
        if (nums[1] === nums[0] + 1) {
            result.push(nums[0].toString() + '->' + nums[1].toString());
            return result;
        } else {
            result.push(nums[0].toString());
            result.push(nums[1].toString());
            return result;
        }
    }

    for(start = 0; start < nums.length;) {
        current_range = nums[start].toString();
        while( (range < nums.length) && (nums[range] === nums[range - 1] + 1))
            range++;
        /* Reached end of a subrange */
        if (nums[range - 1] === nums[range - 2] + 1)
            result.push(current_range + '->' + nums[range -1].toString());
        else
            result.push(current_range);
        start = range;
        range = range + 1;
    }
    return result;
};