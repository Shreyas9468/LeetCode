class DataStream {
public:
    int val, count = 0, k;
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }
    bool consec(int num) {
        if (val == num) {
            count++;
            return (count >= k);
        }
        count = 0;
        return false;
    }
};
/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */