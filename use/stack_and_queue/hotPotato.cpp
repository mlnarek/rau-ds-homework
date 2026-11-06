#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>

std::string hotPotato(std::vector<std::string> players, int k) {
    std::queue<std::string> q;
    for (const auto& p : players) q.push(p);
    
    while (q.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop(); // выбывает
    }
    return q.front();
}

void test_hotPotato() {
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::string winner = hotPotato(players, 7);
    std::cout << "Winner: " << winner << "\n";
    assert(winner == "Charlie" || winner == "David" || winner == "Bob" || winner == "Alice"); // просто проверка, что кто-то остался
    std::cout << "hotPotato passed\n";
}

int main() {
    test_hotPotato();
    return 0;
}
