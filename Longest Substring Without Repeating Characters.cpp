class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // maintain a map to record the latest location of the character
        unordered_map<char, int> mp;

        // maintain a sliding window, move right,
        // if the character already exists in the sliding window,
        // move left to the latest location of the repeating character
        int left = 0, right = 0, ans = 0;

        // move right
        for( int right = 0; right < s.length(); right++){

            // if s[right] exist in map &&
            // the latest location of the repeating character is in the sliding window,
            // then move left to the latest location of the repeating character
            if(mp.count(s[right]) && mp[s[right]] >= left){
                left = mp[s[right]] + 1;
            }

            // record the latest location of the character
            mp[s[right]] = right;

            // maintain ans
            ans = max(ans, right - left + 1);
        }
        return ans;
        
    }
};