class Solution {
public:
    bool contains(vector<int>&arr, int value) {
        for (auto num:arr) {
            if (num == value)
                return true;
        }
        return false;
    }

    int missingInteger(vector<int>& arr) {
        int pss = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1) {
                pss += arr[i];
            } else {
                break;
            }
        }
        int missingInt = pss;
        while (contains(arr, missingInt)) {
            missingInt++;
        }
        return missingInt;
    }
};