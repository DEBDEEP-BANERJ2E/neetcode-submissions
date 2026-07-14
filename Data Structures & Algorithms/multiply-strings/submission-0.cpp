class Solution {
public:
    string multiply(string num1, string num2) {
        // Handle the edge case of multiplying by zero immediately
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.length(); int n = num2.length();
        vector<int> res(m + n, 0);
        // Traverse both strings from right to left
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Convert characters to integer digits and multiply
                int product = (num1[i] - '0') * (num2[j] - '0');
            // Add the product to any existing value in the current position
                int sum = product + res[i + j + 1];
                // The unit digit stays at i + j + 1
                res[i + j + 1] = sum % 10;
                // The carry is added to the next position leftwards (i + j)
                res[i + j] += sum / 10;
            }
        }
        string result = "";
        int start = 0;
        // Find the first non-zero digit
        while (start < res.size() && res[start] == 0)
            start++;
        // Append the remaining digits
        for (int i = start; i < res.size(); ++i)
            result += to_string(res[i]);
        return result;
    }
};
