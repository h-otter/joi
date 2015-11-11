#include <iostream>
#include <algorithm>

int main(){
  int w, n, h;
  std::cin >> w;
  std::cin >> n;
  std::cin >> h;

  int point[n][2];
  for (int i = 0; i < n; i++){
    std::cin >> point[i][0];
    std::cin >> point[i][1];
  }

  int length = std::max(point[0][0], point[0][1]);
  for (int i = 1; i < n; i++){
    if ((point[i][0] - point[i-1][0]) * (point[i][1] - point[i-1][1]) > 0){
      length += std::max(abs(point[i][0] - point[i-1][0]), abs(point[i][1] - point[i-1][1]));
    }
    else{
      length += abs(point[i][0] - point[i-1][0]) + abs(point[i][1] - point[i-1][1]);
    }
  }
  length += std::max(abs(point[n-1][0] - w), abs(point[n-1][1] - h));

  std::cout << length << std::endl;

  return 0;
}
