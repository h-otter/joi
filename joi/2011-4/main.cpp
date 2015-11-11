#include <iostream>

#define PASTA 3

int main(){
  int n, k;
  std::cin >> n;
  std::cin >> k;

  int decided[n];
  for (int i = 0; i < n; i++){
    decided[i] = -1;
  }
  for (int i = 0; i < k; i++){
    int a = 0;
    std::cin >> a;
    std::cin >> decided[a-1];
  }

  int day[n][PASTA][2];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < PASTA; j++){
      day[i][j][0] = 0;
      day[i][j][1] = 0;
    }
  }
  if (decided[0] != -1){
    day[0][decided[0]-1][0] = 1;
  }
  else{
    for (int i = 0; i < PASTA; i++){
      day[0][i][0] = 1;
    }
  }

  // process
  for (int i = 1; i < n; i++){
    if (decided[i] != -1){
      day[i][decided[i]-1][0] = day[i-1][decided[i]%3][0] +
                                day[i-1][decided[i]%3][1] +
                                day[i-1][(decided[i]+1)%3][0] +
                                day[i-1][(decided[i]+1)%3][1];
      day[i][decided[i]-1][1] = day[i-1][decided[i]-1][0];

      day[i][decided[i]-1][0] %= 10000;
      day[i][decided[i]-1][1] %= 10000;
    }
    else{
      for (int j = 0; j < PASTA; j++){
        day[i][j][0] = day[i-1][(j+1)%3][0] +
                       day[i-1][(j+1)%3][1] +
                       day[i-1][(j+2)%3][0] +
                       day[i-1][(j+2)%3][1];
        day[i][j][1] = day[i-1][j][0];

        day[i][j][0] %= 10000;
        day[i][j][1] %= 10000;
      }
    }
  }

  int result = 0;
  for (int i = 0; i < PASTA; i++){
    result += day[n-1][i][0] + day[n-1][i][1];
    result %= 10000;
  }

  std::cout << result << std::endl;

  return 0;
}
