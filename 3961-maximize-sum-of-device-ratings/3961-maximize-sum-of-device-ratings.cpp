class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();

        vector<int> mn1(m), mn2(m, INT_MAX);
        vector<long long> posGain(m, 0);
        long long base = 0;
        int G = INT_MAX;

        for (int i = 0; i < m; i++) {
            int a = INT_MAX, b = INT_MAX;
            for (int x : units[i]) {
                if (x < a) {
                    b = a;
                    a = x;
                } else if (x < b) {
                    b = x;
                }
            }

            mn1[i] = a;
            mn2[i] = b;
            base += a;
            G = min(G, a);

            if ((int)units[i].size() >= 2) {
                posGain[i] = max(0, b - a);
            }
        }

        long long sumPos = 0;
        for (long long g : posGain) sumPos += g;

        long long ans = base;

        // Case 1: keep one global-min device as sink
        long long bestKeepGlobal = LLONG_MAX;
        for (int i = 0; i < m; i++) {
            if (mn1[i] == G) {
                bestKeepGlobal = min(bestKeepGlobal, posGain[i]);
            }
        }
        ans = max(ans, base + sumPos - bestKeepGlobal);

        // Case 2: use no global-min device as sink
        long long bestOtherSink = LLONG_MAX;
        for (int i = 0; i < m; i++) {
            if (mn1[i] > G) {
                bestOtherSink = min(bestOtherSink, posGain[i] + (long long)(mn1[i] - G));
            }
        }
        if (bestOtherSink != LLONG_MAX) {
            ans = max(ans, base + sumPos - bestOtherSink);
        }

        return ans;
    }
};