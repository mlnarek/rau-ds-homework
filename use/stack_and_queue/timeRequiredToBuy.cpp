#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

int timeRequiredToBuy(std::vector<int>& tickets, int k) {
    std::queue<std::pair<int, int>> q; // индекс, оставшиеся билеты
    for (int i = 0; i < tickets.size(); i++) {
        q.push({i, tickets[i]});
    }
    
    int time = 0;
    while (!q.empty()) {
        auto [idx, rem] = q.front();
        q.pop();
        time++;
        rem--;
        
        if (idx == k && rem == 0) {
            return time;
        }
        if (rem > 0) {
            q.push({idx, rem});
        }
    }
    return time;
}

void test_timeRequiredToBuy() {
    std::vector<int> t1 = {2, 3, 2};
    assert(timeRequiredToBuy(t1, 2) == 6);
    
    std::vector<int> t2 = {5, 1, 1, 1};
    assert(timeRequiredToBuy(t2, 0) == 8);
    
    std::cout << "timeRequiredToBuy passed\n";
}

int main() {
    test_timeRequiredToBuy();
    return 0;
}
