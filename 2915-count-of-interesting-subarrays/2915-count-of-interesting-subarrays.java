class Solution {
    public long countInterestingSubarrays(List<Integer> gadgets, int bambooCopters, int dorayaki) {
        int timeTunnel = gadgets.size();
        long memoryAnywhere[] = new long[timeTunnel + 1];
        Map<Long, Integer> dorasPocket = new HashMap<>();
        memoryAnywhere[0] = 0;
        dorasPocket.put(0L, 1);
        long nobitaScore = 0;

        for (int i = 0; i < timeTunnel; i++) {
            long gadget = gadgets.get(i);
            memoryAnywhere[i + 1] = (memoryAnywhere[i] + (gadget % bambooCopters == dorayaki ? 1 : 0)) % bambooCopters;
            long whatIf = (memoryAnywhere[i + 1] - dorayaki + bambooCopters) % bambooCopters;
            nobitaScore += dorasPocket.getOrDefault(whatIf, 0);
            dorasPocket.put(memoryAnywhere[i + 1], dorasPocket.getOrDefault(memoryAnywhere[i + 1], 0) + 1);
        }

        return nobitaScore;
    }
}