class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for (int i = 1; i < words.size(); i++) { // Size dynamically update hoga
            string x = words[i], y = words[i - 1];
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());

            if (x == y) {
                words.erase(words.begin() + i);
                i--; // Because `erase()` shifts elements left, so we recheck the same index
            }
        }
        return words;
    }
};
