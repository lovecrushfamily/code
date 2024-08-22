#include<iostream>
#include<vector>

using namespace std;
/**
 * Bạn đang lên kế hoạch cướp tiền tại các ngôi nhà dọc theo một con phố.
 *  Ngôi nhà thứ i có nums[i] tiền. Nếu bạn cướp hai ngôi nhà cạnh nhau,
 *  hệ thống báo động sẽ kích hoạt và báo cho cảnh sát. Số tiền nhiều nhất
 *  bạn có thể cướp mà không làm kích hoạt chuông báo động là bao nhiêu?
*/
class Solution {
public:
    vector<int> nums;
    vector<int> memo;
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            // to prevent out of bounds error
            return nums[0];
        }
        
        this->nums = nums;
        memo = vector<int>(nums.size(), -1);
        return dp(nums.size() - 1);
    }
    
    int dp(int i) {
        if (i == 0) {
            return nums[0];
        }
        if (i == 1) {
            return max(nums[0], nums[1]);
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }
        
        memo[i] = max(dp(i - 1), dp(i - 2) + nums[i]);
        return memo[i];
    }
};

int main(){

    Solution so;
    vector<int> test = {3, 8, 6, 3, 1};
    cout << so.rob(test);

    return 0;
}