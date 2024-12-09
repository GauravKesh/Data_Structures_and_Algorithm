# //
# // Created by Gaurav Kesh Roushan on 09/12/24.
# //
#
# /*Using Python*/


class Solution:
    def lengthOfLastWord(self, s: str) -> int:


a = list(s.strip().split(" "));
return len(a[len(a) - 1]);
