#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using std::cin, std::cout;
using std::pair, std::string;

struct Track {
  int id;
  int score;
};

bool operator>(const Track &t1, const Track &t2) {
  if (t1.score == t2.score) {
    return t1.id > t2.id;
  }
  return t1.score < t2.score;
}

void Solve() {
  const int ten_min = 600;
  int last_used_id = 1;

  std::unordered_map<string, int> last_appearance;
  std::unordered_map<int, int> actual_score;
  std::unordered_set<int> used_id;

  std::priority_queue<Track, std::vector<Track>, std::greater<>> rating;
  rating.push({1, 0});

  string command;
  while (cin >> command) {
    if (command == "VOTE") {
      string ip;
      int track_id = 0;
      int score = 0;
      int time = 0;
      cin >> ip >> track_id >> score >> time;
      if (last_appearance.find(ip) == last_appearance.end() || time - last_appearance[ip] >= ten_min) {
        actual_score[track_id] += score;
        rating.push({track_id, actual_score[track_id]});
        last_appearance[ip] = time;
        used_id.insert(track_id);
      }
      cout << actual_score[track_id] << "\n";
    } else if (command == "GET") {
      Track best_track = rating.top();
      while (rating.size() > 1 && actual_score[best_track.id] != best_track.score) {
        rating.pop();
        best_track = rating.top();
      }
      if (best_track.score < 0 || (best_track.score == 0 && best_track.id >= last_used_id)) {
        while (used_id.count(last_used_id) > 0) {
          if (actual_score[last_used_id] == 0) {
            break;
          }
          ++last_used_id;
        }
        best_track = {last_used_id, 0};
        rating.push(best_track);
        used_id.insert(last_used_id);
      }
      cout << best_track.id << ' ' << best_track.score << "\n";
      actual_score[best_track.id] = -1;
      rating.pop();
      rating.push({best_track.id, -1});
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
