#include <iostream>
#include <algorithm>
#include <limits>

#define MAX_CITY 1000
#define MAX_DAY 1000

int N, M;
int D[MAX_CITY];
int C[MAX_DAY];

int log[MAX_CITY][MAX_DAY];

int SmallTired(int city, int day){
  if (log[city][day] != -1){
    return log[city][day];
  }

  if (city == N){
    return 0;
  }

  if (M <= day){
    return std::numeric_limits<int>::max();
  }

  log[city][day] = std::min(std::abs(SmallTired(city + 1, day + 1) + D[city] * C[day]), SmallTired(city, day + 1));
  return log[city][day];
}


int main(){
  std::cin >> N >> M;

  for (int i = 0; i < N; i++){
    std::cin >> D[i];
  }
  for (int i = 0; i < M; i++){
    std::cin >> C[i];
  }

  for (int i = 0; i <= N; i++){
    for (int j = 0; j <= M; j++){
      log[i][j] = -1;
    }
  }

  std::cout << SmallTired(0, 0) << std::endl;
}
