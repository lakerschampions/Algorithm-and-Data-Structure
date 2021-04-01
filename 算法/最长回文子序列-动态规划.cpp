/*
leetcode 516:
给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int f[1001][1001];
        for (int i = n - 1; i >= 0; i-- ){
            f[i][i] = 1;
            for (int j = i + 1; j < n; j++){
                if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1] + 2;
                else {
                    f[i][j] = max(f[i+1][j], f[i][j-1]);
                }
            }
        }
        return (f[0][n-1]);
    }
};
