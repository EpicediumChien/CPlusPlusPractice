// LongestPalindromicSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_p_len = 0;
        int startIdx = 0;
        string stackString = "";
        if (s.length() != 1) {
            for (int i = 0; i < s.length(); i++)
            {
                stackString += s.substr(i, 1);
                string leftString = stackString;
                if (leftString.length() != s.length())
                {
                    // even
                    int pLengthCount = 0;
                    string rightString = s.substr(leftString.length());
                    while (leftString.length() != 0 && rightString.length() != 0)
                    {
                        if (leftString.substr(leftString.length() - 1, 1) == rightString.substr(0, 1))
                        {
                            pLengthCount += 2;
                            leftString = leftString.substr(0, leftString.length() - 1);
                            rightString = rightString.substr(1, rightString.length() - 1);

                        }
                        else
                        {
                            break;
                        }

                        if (max_p_len < pLengthCount)
                        {
                            max_p_len = pLengthCount;
                            startIdx = leftString.length();
                        }
                    }

                    // odd
                    pLengthCount = 0;
                    leftString = stackString;
                    rightString = s.substr(leftString.length());
                    leftString = leftString.substr(0, leftString.length() - 1);
                    pLengthCount++;
                    if (max_p_len < pLengthCount)
                    {
                        max_p_len = pLengthCount;
                        startIdx = leftString.length();
                    }
                    while (leftString.length() != 0 && rightString.length() != 0)
                    {
                        if (leftString.substr(leftString.length() - 1, 1) == rightString.substr(0, 1))
                        {
                            pLengthCount += 2;
                            leftString = leftString.substr(0, leftString.length() - 1);
                            rightString = rightString.substr(1, rightString.length() - 1);

                        }
                        else
                        {
                            break;
                        }
                        if (max_p_len < pLengthCount)
                        {
                            max_p_len = pLengthCount;
                            startIdx = leftString.length();
                        }
                    }
                }
            }
        }
        else {
            return s;
        }
        return s.substr(startIdx, max_p_len);
    }
};

int main()
{
    string testCase = "jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
    string answer = "qosoq";
    //string testCase = "babad";
    //string answer = "bab";
    //string testCase = "cbbd";
    //string answer = "bb";
    //string testCase = "bb";
    //string answer = "bb";
    //string testCase = "ccc";
    //string answer = "ccc";
    //string testCase = "azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc";
    //string answer = "sooos";
    //string testCase = "ac";
    //string answer = "a";
    Solution sol;
    cout << sol.longestPalindrome(testCase);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
