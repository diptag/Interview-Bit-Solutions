/*
    Given a string containing only digits, restore it by returning all possible valid IP address combinations.

    A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

    Example:

    Given “25525511135”,

    return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/

void generateIP (string A, vector<string> &ans, string &cur, int i) {
    int j = cur.size() - 1, lastNum = 0, place = 1, count = 0;
    while (j >= 0) {
        if (cur[j] == '.')
            count++;
        else if (count == 0) {
            lastNum += place * (cur[j] - '0');
            place *= 10;
        }
    }
    
    if (count > 3)
        return;
    else if (i == A.size()) {
        ans.push_back(cur);
        return;
    }
    
    if (lastNum > 25 || (lastNum == 25 && A[i] > '5')) {
        cur.push_back('.');
        cur.push_back(A[i]);
        generateIP(A, ans, cur, i + 1);
        cur.pop_back();
        cur.pop_back();
    }
    else if (lastNum == 25 && A[i] <= '5') {
        cur.push_back(A[i]);
        generateIP(A, ans, cur, i + 1);
        cur.pop_back();
    }
    else if (lastNum > 0) {
        cur.push_back(A[i]);
        generateIP(A, ans, cur, i + 1);
        cur.pop_back();
    }
    else if (lastNum == 0) {
        if (A[i] == '0') {
            cur.push_back(A[i]);
            generateIP(A, ans, cur, i + 1);
            cur.pop_back();
        }
        else
            return;
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    string cur;
    
    generateIP(A, ans, cur, 0);
    
    return ans;
}
