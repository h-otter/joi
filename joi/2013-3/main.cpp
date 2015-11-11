#include <iostream>
#include <algorithm>

int main(){
  int w, h, n;
  std::cin >> w;
  std::cin >> h;
  std::cin >> n;

  int point[n][2];
  for (int i = 0; i < n; i++){
    std::cin >> point[i][0];
    std::cin >> point[i][1];
  }

  int length = 0;
  for (int i = 1; i < n; i++){
    if ((point[i][0] - point[i-1][0]) * (point[i][1] - point[i-1][1]) > 0){
      length += std::max(abs(point[i][0] - point[i-1][0]), abs(point[i][1] - point[i-1][1]));
    }
    else{
      length += abs(point[i][0] - point[i-1][0]) + abs(point[i][1] - point[i-1][1]);
    }
//    std::cout << "DEBUG i = " << i << ", length = " << length << std::endl;
  }

  std::cout << length << std::endl;

  return 0;
}
