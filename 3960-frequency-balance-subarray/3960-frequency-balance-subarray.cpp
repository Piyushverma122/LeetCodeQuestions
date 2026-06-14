class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;      // value -> count
            unordered_map<int, int> freqCnt;   // frequency -> how many values have this frequency

            for (int j = i; j < n; j++) {
                int x = nums[j];
                int oldf = freq[x];

                if (oldf > 0) {
                    freqCnt[oldf]--;
                    if (freqCnt[oldf] == 0) freqCnt.erase(oldf);
                }

                int newf = ++freq[x];
                freqCnt[newf]++;

                int distinct = freq.size();
                bool ok = false;

                if (distinct == 1) {
                    ok = true;
                } else if (freqCnt.size() == 2) {
                    auto it = freqCnt.begin();
                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;
                    if (f1 > f2) swap(f1, f2);

                    if (f2 == 2 * f1) ok = true;
                }

                if (ok) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};