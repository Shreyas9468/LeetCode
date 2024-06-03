#include <unordered_map>
#include <algorithm>
#include <climits>

#define ll long long int

class StockPrice {
public:
    std::unordered_map<ll, ll> mp;
    ll curr = 0;
    ll maxp = LLONG_MIN;
    ll minp = LLONG_MAX;
    ll latestTimestamp = 0;

    StockPrice() {}

    void update(int timestamp, int price) {
        if (mp.find(timestamp) != mp.end()) {
            // When updating an existing timestamp
            int prev = mp[timestamp];
            mp[timestamp] = price;

            if (timestamp == latestTimestamp) {
                curr = price;
            }

            if (prev == maxp || prev == minp) {
                // Recalculate maxp and minp if the current max or min is being changed
                maxp = LLONG_MIN;
                minp = LLONG_MAX;
                for (auto& it : mp) {
                    maxp = std::max(it.second, maxp);
                    minp = std::min(it.second, minp);
                }
            } else {
                // Otherwise, update maxp and minp directly
                maxp = std::max(maxp, 1LL * price);
                minp = std::min(minp, 1LL * price);
            }
        } else {
            // When adding a new timestamp
            mp[timestamp] = price;
            if (timestamp > latestTimestamp) {
                latestTimestamp = timestamp;
                curr = price;
            }
            maxp = std::max(maxp, 1LL * price);
            minp = std::min(minp, 1LL * price);
        }
    }

    int current() {
        return curr;
    }

    int maximum() {
        return maxp;
    }

    int minimum() {
        return minp;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
