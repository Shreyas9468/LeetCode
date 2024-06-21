#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baselineSatisfaction = 0;

        // Calculate the baseline satisfaction
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                baselineSatisfaction += customers[i];
            }
        }

        // Find the best window to apply the grumpiness suppression
        int maxAdditionalSatisfaction = 0;
        int currentAdditionalSatisfaction = 0;

        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentAdditionalSatisfaction += customers[i];
            }
        }

        maxAdditionalSatisfaction = currentAdditionalSatisfaction;

        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentAdditionalSatisfaction += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentAdditionalSatisfaction -= customers[i - minutes];
            }
            maxAdditionalSatisfaction = std::max(maxAdditionalSatisfaction, currentAdditionalSatisfaction);
        }

        return baselineSatisfaction + maxAdditionalSatisfaction;
    }
};
