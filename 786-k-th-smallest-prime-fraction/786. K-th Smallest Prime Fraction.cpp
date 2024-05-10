

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double , pair<int,int>>> vp; 
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double div = arr[i] / (arr[j] * 1.0);
                vp.push_back(make_pair(div, make_pair(arr[i], arr[j])));
            }
        }
        sort(vp.begin(), vp.end()); 
        return {vp[k - 1].second.first, vp[k - 1].second.second};
    }
};
