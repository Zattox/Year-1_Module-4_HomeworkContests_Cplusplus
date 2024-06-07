#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstdint>

using std::cin, std::cout;
using std::pair, std::string;

struct Track {
  int id;
  int score;
};

bool operator>(const Track &t1, const Track &t2) {
  if (t1.score == t2.score) {
    return t1.id < t2.id;
  }
  return t1.score > t2.score;
}

void Solve() {
  const int64_t ten_min = 600;
  string command;
  std::unordered_map<int, int> rating;
  std::unordered_map<string, int64_t> last_appearance;

  for (int id = 1; id <= 100000; ++id) {
    rating[id] = 0;
  }

  while (cin >> command) {
    if (command == "VOTE") {
      string ip;
      int track_id = 0;
      int score = 0;
      int64_t time = 0;
      cin >> ip >> track_id >> score >> time;

      if (last_appearance.find(ip) == last_appearance.end() || time - last_appearance[ip] >= ten_min) {
        rating[track_id] += score;
        last_appearance[ip] = time;
      }

      cout << rating[track_id] << "\n";
    } else if (command == "GET") {
      Track best_track = {-1, -1};
      for (auto &elem : rating) {
        Track el = {elem.first, elem.second};
        if (el > best_track) {
          best_track = el;
        }
      }

      cout << best_track.id << ' ' << best_track.score << "\n";
      rating[best_track.id] = -1;

    } else if (command == "EXIT") {
      cout << "OK\n";
      break;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solve();

  return 0;
}
