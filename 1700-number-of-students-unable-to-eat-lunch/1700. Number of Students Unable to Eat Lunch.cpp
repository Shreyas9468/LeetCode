#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        vector<int> count(2, 0); // count[i] stores the number of students preferring sandwich type i
        
        for (int student : students)
            count[student]++;
        
        for (int i = 0; i < n; i++) {
            if (count[sandwiches[i]] > 0)
                count[sandwiches[i]]--;
            else
                return n - i; // Number of students unable to eat
        }
        
        return 0; // All students are able to eat
    }
};
