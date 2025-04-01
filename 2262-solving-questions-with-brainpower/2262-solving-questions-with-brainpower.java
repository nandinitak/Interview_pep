class Solution {
    public long mostPoints(int[][] arr) {
        long dp [] = new long [arr.length];
		Arrays.fill(dp, -1);
		
		long value = check(arr, dp, 0);
		return value;
	}

	private static long check(int[][] arr, long[] dp, int ind) {
		if(ind >= arr.length)
		{
			return 0;
		}
		if(dp[ind] != -1)
		{
			return dp[ind];
		}
		long a = arr[ind][0] + check(arr, dp, ind + arr[ind][1] + 1);
		long b = check(arr, dp, ind + 1);
		return dp[ind] =(Math.max(a, b));
	}
}


