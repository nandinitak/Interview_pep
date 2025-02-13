class Solution 
{
    public static int minOperations(int[] nums, int k) 
    {
        int operations = 0;
        PriorityQueue<Long> minHeap = new PriorityQueue<>();

        // Step 1: Insert all elements into minHeap
        for (int num : nums) 
        {
            minHeap.add((long) num);
        }

        // Step 2: Process until smallest element is at least k
        while (minHeap.size() > 1 && minHeap.peek() < k)
        {
            long x = minHeap.poll();
            long y = minHeap.poll();
            long newVal = x * 2 + y;

            minHeap.add(newVal);
            operations++;
        }

        // Step 3: Return the result
        return minHeap.peek() >= k ? operations : -1;
    }
}