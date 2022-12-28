class Solution {
public:
    int minStoneSum(vector<int>& A, int k) {
        priority_queue<int> pq;
        for (int n : A) pq.push(n);
        long rm = 0, sum = accumulate(begin(A), end(A), 0L);
        for (int i = 0; i < k; ++i) {
            int n = pq.top();
            pq.pop();
            if (n == 1) break;
            rm += n / 2;
            pq.push(n - n / 2);
        }
        return sum - rm;
    }
};