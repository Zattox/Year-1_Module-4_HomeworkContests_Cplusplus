#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <algorithm>

using std::cin, std::cout;
using std::pair, std::string;

long long getrand() {
  return (rand() * 32768) + rand();
}

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

std::unordered_map<int, int> GOOD_rating;
std::unordered_map<string, int64_t> GOOD_last_appearance;
string Good_TL_VOTE(string &ip, int track_id, int score, int64_t time) {
  const int64_t ten_min = 600;
  if (GOOD_last_appearance.find(ip) == GOOD_last_appearance.end() || time - GOOD_last_appearance[ip] >= ten_min) {
    GOOD_rating[track_id] += score;
    GOOD_last_appearance[ip] = time;
  }

  return std::to_string(GOOD_rating[track_id]);
}

string Good_TL_GET() {
  Track best_track = {-1, -1};
  for (auto &elem : GOOD_rating) {
    Track el = {elem.first, elem.second};
    if (el > best_track) {
      best_track = el;
    }
  }

  string answer = std::to_string(best_track.id);
  answer += ' ';
  answer += std::to_string(best_track.score);
  GOOD_rating[best_track.id] = -1;
  return answer;
}

struct WA_Track {
  int id;
  int score;
};

bool operator>(const WA_Track &t1, const WA_Track &t2) {
  if (t1.score == t2.score) {
    return t1.id > t2.id;
  }
  return t1.score < t2.score;
}

int last_used_id = 1;
std::unordered_map<string, int64_t> last_appearance;
std::unordered_map<int, int> actual_score;
std::unordered_set<int> used_id;
std::priority_queue<WA_Track, std::vector<WA_Track>, std::greater<>> rating;

string WA_VOTE(string &ip, int track_id, int score, int64_t time) {
  const int64_t ten_min = 600;
  if (last_appearance.find(ip) == last_appearance.end() || time - last_appearance[ip] >= ten_min) {
    actual_score[track_id] += score;
    rating.push({track_id, actual_score[track_id]});
    last_appearance[ip] = time;
    used_id.insert(track_id);
  }

  return std::to_string(actual_score[track_id]);
}

string WA_GET() {
  WA_Track best_track = rating.top();
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

  string answer = std::to_string(best_track.id);
  answer += ' ';
  answer += std::to_string(best_track.score);
  actual_score[best_track.id] = -1;
  rating.pop();
  rating.push({best_track.id, -1});
  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  freopen("tests_k.txt", "w", stdout);
  cin.tie(nullptr);
  cout.tie(nullptr);

  std::vector<long long> times;
  for (int t1 = 0; t1 < 100000; ++t1) {
    times.push_back(getrand() % 1000000);
  }
  for (int id = 1; id <= 100000; ++id) {
    GOOD_rating[id] = 0;
  }

  std::sort(times.begin(), times.end());
  int ind_t = 0;
  rating.push({1, 0});
  while (ind_t < times.size()) {
    int c = getrand() % 2;
    if (c == 0) {
      cout << "VOTE ";
      string ip =  std::to_string(getrand() % 256);
      ip += ".1.1.1";
      int track_id = getrand() % 10000 + 1;
      int score = getrand() % 100;
      if (getrand() % 2 == 1) {
        score *= -1;
      }
      int time = times[ind_t++];
      cout << ip << ' ' << track_id << ' ' << score << ' ' << time << "\n";
      auto good_ans = Good_TL_VOTE(ip, track_id, score, time);
      auto bad_ans = WA_VOTE(ip, track_id, score, time);
      if (good_ans != bad_ans) {
        cout << "EXIT\n===================================\n";
        cout << "good ans: " << good_ans << '\n';
        cout << "bad ans: " << bad_ans << "\n";
        break;
      }
    } else {
      auto good_ans = Good_TL_GET();
      auto bad_ans = WA_GET();
      cout << "GET\n";
      if (good_ans != bad_ans) {
        cout << "EXIT\n===================================\n";
        cout << "good ans: " << good_ans << '\n';
        cout << "bad ans: " << bad_ans << "\n";
        break;
      }
    }
  }

  return 0;
}
