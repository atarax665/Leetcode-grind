class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        long mid;
        while(l <= r){
            mid = l + (r - l)/2;
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid < x && (mid+1)*(mid+1) > x){
                return mid;
            }
            else if(mid*mid < x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return 0;
    }
};