class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0)
        {
            return 0;
        }
        // Let there be n numbers and each one of them has the units place digit as k
        // we can write it as (k * n) + 10(a1+a2+a3......) = num
        for(int i = 1; i <= 10; i++)
        {
            if((i * k)%10 == num % 10 && i * k <= num)
                return i;
        }
        return -1;
    }
};