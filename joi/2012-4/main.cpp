#include <iostream>
#include <limits>
#include <algorithm>

#define D_MAX 200
#define N_MAX 200

int d, n;

int t[D_MAX];
int a[N_MAX], b[N_MAX], c[N_MAX];

int log[N_MAX][D_MAX];

int ShowLog(){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < d; j++){
      std::cout << log[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  return 0;
}

int MaxC(int cloth, int day){
  if (log[cloth][day] != -1){
    return log[cloth][day];
  }

  if (t[day] < a[cloth] || b[cloth] < t[day]){
    return std::numeric_limits<int>::min();
  }

  if (day >= d - 1){
    return 0;
  }

  for (int i = 0; i < n; i++){
    log[cloth][day] = std::max(MaxC(i, day + 1) + std::abs(c[cloth] - c[i]), log[cloth][day]);
  }

//  std::cout << "DEBUG: day = " << day << std::endl;
//  ShowLog();

  return log[cloth][day];
}

int main(){
  std::cin >> d;
  std::cin >> n;

  for (int i = 0; i < d; i++){
    std::cin >> t[i];
  }

  for (int i = 0; i < n; i++){
    std::cin >> a[i];
    std::cin >> b[i];
    std::cin >> c[i];
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < d; j++){
      log[i][j] = -1;
    }
  }

  int result = 0;
  for (int i = 0; i < n; i++){
    result = std::max(result, MaxC(i, 0));
  }

  std::cout << result << std::endl;

  return 0;
}
