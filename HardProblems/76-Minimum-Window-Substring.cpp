#include <unordered_map>;
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    /**
     * Finds the minimum window in a given string that contains all the characters of another string.
     *
     * The function finds the smallest substring in a given string s that contains all characters of another string t. It uses a sliding
     * window approach with two pointers, window_start and window_end, to track the current substring. The function returns the minimum window as a substring of s. If no valid substring is found, it returns an empty string.
     * Here's a high-level overview of the steps:
     *
     * Initialize frequency maps for characters in t and the current window.
     *
     * Expand the window to the right by incrementing window_end.
     *
     * If the current character is in t, update the frequency maps and check if the window contains all characters of t.
     *
     * If the window is valid, try to shrink it by incrementing window_start.
     *
     * Update the minimum window length and start position if a smaller valid window is found.
     *
     * Repeat steps 2-5 until the end of s is reached.
     *
     * Return the minimum window substring or an empty string if no valid substring is found.
     *
     * @param s The input string.
     * @param t The string containing all the characters to be found.
     *
     * @return The minimum window as a substring of the input string. If no valid substring is found, an empty string is returned.
     *
     */
    string minWindow(string s, string t)
    {
        if (s == "" || t == "")
            return "";

        unordered_map<char, int> t_char_freq;
        unordered_map<char, int> window_char_freq;
        int window_start = 0;
        int window_end = 0;
        int char_freq_matches = 0;
        int required_matches = 0;

        for (char c : t)
        {
            if (t_char_freq.find(c) == t_char_freq.end())
            {
                t_char_freq[c] = 1;
                required_matches++;
            }
            else
            {
                t_char_freq[c]++;
            }
        }

        int min_window_start = 0;
        int min_window_length = INT_MAX;

        while (window_end < s.length())
        {
            // if the character exists in t then add it to the window character frequency map
            if (t_char_freq.find(s[window_end]) != t_char_freq.end())
            {
                window_char_freq[s[window_end]]++;
                // if the character frequency matches then increase the number of matches
                if (window_char_freq[s[window_end]] == t_char_freq[s[window_end]])
                {
                    char_freq_matches++;
                }
            }

            // if substring is valid then try to shrink the window
            while (char_freq_matches == required_matches)
            {
                // update the min window length and min window start
                // if the current window length is less than the current min window length
                if (window_end - window_start + 1 < min_window_length)
                {
                    min_window_length = window_end - window_start + 1;
                    min_window_start = window_start;
                }

                // if the character exists in t then remove it from the window character frequency map
                if (t_char_freq.find(s[window_start]) != t_char_freq.end())
                {
                    window_char_freq[s[window_start]]--;
                    if (window_char_freq[s[window_start]] < t_char_freq[s[window_start]])
                    {
                        char_freq_matches--;
                    }
                }
                window_start++;
            }

            window_end++;
        }

        // if no valid substring is found then return empty string
        if (min_window_length == INT_MAX)
        {
            return "";
        }
        else
        {
            return s.substr(min_window_start, min_window_length);
        }
    }
};