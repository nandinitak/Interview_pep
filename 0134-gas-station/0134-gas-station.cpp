class Solution {
public:
    // int canCompleteCircuit(vector<int>& gass, vector<int>& cost) {
//         int n = gass.size();
//         int gas = 0;
//         int index = -1;  // ✅ Initialize to -1 to check if a valid start exists
//         int diff = 0;
//         bool valid = false;

//         for (int i = 0; i < n; i++) {
//             if (gass[i] >= cost[i]) {  
//                 index = i;
//                 gas = 0;  // ✅ Reset gas for new starting point

//                 for (int j = 0; j < n; j++) {  
//                     int curr = (index + j) % n;  // ✅ Circular index to simulate the journey
//                     gas += gass[curr] - cost[curr];

//                     if (gas < 0) {  // ✅ If gas goes negative, this start is invalid
//                         index = -1;
//                         break;
//                     }
//                 }

//                 if (index != -1) {  // ✅ If a valid start is found, return it
//                     return index;
//                 }
//             }
//         }

//         return -1;  // ✅ Return -1 if no valid start exists

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int current_gas = 0;
        int index = 0;
        int total_gas = 0, total_cost = 0;

        // Calculate total gas and total cost
        for (int i = 0; i < n; i++) {
            total_gas += gas[i];
            total_cost += cost[i];
        }

        // If total gas is less than total cost, completing the circuit is impossible
        if (total_gas < total_cost) return -1;

        // Find the starting index
        for (int i = 0; i < n; i++) {
            current_gas += gas[i] - cost[i];
            if (current_gas < 0) {  // If gas goes negative, reset the start index
                index = i + 1;
                current_gas = 0;
            }
        }

        return index;


    }
};
