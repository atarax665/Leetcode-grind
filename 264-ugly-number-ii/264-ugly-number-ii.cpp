class Solution
{
    public:
        int nthUglyNumber(int n)
        {
            vector<int> dp;
            dp.push_back(1);

            int i = 0, j = 0, k = 0;
            int temp = n - 1;

            while (temp--)
            {
                int a = 2 * dp[i];
                int b = 3 * dp[j];
                int c = 5 * dp[k];

                int minval = min(a, min(b, c));
                dp.push_back(minval);

                if (a == minval) i++;
                if (b == minval) j++;
                if (c == minval) k++;
            }

            return dp[n - 1];
        }
};