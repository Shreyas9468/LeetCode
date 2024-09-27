class MyCalendarTwo {
public:
    vector<pair<int, int>> singleReservations;
    vector<pair<int, int>> doubleReservations;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (const auto& interval : doubleReservations) {
            if (max(interval.first, start) < min(interval.second, end)) {
                return false;
            }
        }

        for (const auto& interval : singleReservations) {
            if (max(interval.first, start) < min(interval.second, end)) {
                doubleReservations.push_back({max(interval.first, start), min(interval.second, end)});
            }
        }

        singleReservations.push_back({start, end});
        return true;
    }
};

/**
 * Usage:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool result = obj->book(start, end);
 */