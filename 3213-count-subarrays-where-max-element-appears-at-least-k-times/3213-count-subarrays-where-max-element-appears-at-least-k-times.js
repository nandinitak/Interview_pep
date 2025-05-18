/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function countSubarrays(nums, k) {
    const max = nums.reduce((a, b) => Math.max(a, b)), n = nums.length;
    let L = 0, cnt = 0;
    return nums.reduce((res, numR, R) => {
        cnt += +(numR === max);
        while (cnt >= k) cnt -= +(nums[L++] === max), res += n - R;
        return res;
    }, 0);
}