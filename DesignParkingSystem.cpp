/*
https://leetcode.com/problems/design-parking-system/description/
*/

class ParkingSystem {
public:
    vector<int> limit;
    vector<int> cnt = {0,0,0};
    ParkingSystem(int big, int medium, int small) {
        this->limit = {big, medium, small};
    }

    bool addCar(int carType) {
        if (this->cnt[carType - 1] < this->limit[carType - 1]) {
            this->cnt[carType - 1]++;
            return true;
        }
        return false;
    }
};
