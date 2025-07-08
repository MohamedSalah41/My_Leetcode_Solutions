class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start =0 ;
        int windowsum = 0;
        int minlen=INT_MAX;
        int n = nums.size();
        int curlen=0;

        for(int end =0 ; end < n ; end++){
                windowsum += nums[end] ;
                while(windowsum >= target){
                    curlen=end-start +1;
                    windowsum-=nums[start];
                    minlen=min(minlen , curlen);
                    start++;
                }

        }
        return (minlen == INT_MAX )? 0 : minlen;
    }
};


/*🧠 Explanation (step-by-step):
start: left pointer of the window

end: right pointer (moves in the for-loop)

windowSum: sum of numbers inside the current window

minLen: tracks the smallest valid window length

🔁 How it works:
Loop through each element with end

Add current number to windowSum

If windowSum ≥ target:

Update minLen

Move start to shrink the window and keep checking

After the loop, return minLen if found, else return 0

⏱ Time Complexity:
O(n) — each number is added and removed at most once

📦 Space Complexity:
O(1) — no extra space used*/
