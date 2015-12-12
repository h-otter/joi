#include <iostream>

#define FLAG_J 1
#define FLAG_O 2
#define FLAG_I 4
#define ALL_PATTERN 7
#define DAY_MAX 1000

int log[DAY_MAX][ALL_PATTERN+1];

int N;
char must_man[DAY_MAX];

int GetAllPattern(const int day, const int pattern){
  if ((must_man[day] & pattern) == 0){
	  return 0;
  }
  
  if (log[day][pattern] != -1){
	  return log[day][pattern];
  }
	
  if (day + 1 >= N){
    return 1;
  }
	
  log[day][pattern] = 0;
  for (int i = 1; i <= ALL_PATTERN; i++){
    if ((pattern & i) != 0){
      log[day][pattern] += GetAllPattern(day + 1, i);
    }
  }
  log[day][pattern] %= 10007;
  
  return log[day][pattern]; 
}

int main(){
  std::cin >> N;
  for (int i = 0; i < N; i++){
	  char input;
	  std::cin >> input;
    
	  switch(input){
    case 'J':
	    must_man[i] = FLAG_J;
	    break;    
	
	  case 'O':
	    must_man[i] = FLAG_O;
	    break;
	  
	  case 'I':
	    must_man[i] = FLAG_I;
	    break;
	  }
  }
  
  for (int i = 0; i < N; i++){
    for (int j = 1; j <= ALL_PATTERN; j++){
      log[i][j] = -1;
    }
  }
  
  int result = 0;
  for (int i = 1; i <= ALL_PATTERN; i++){
    if (i & FLAG_J != 0){
      result += GetAllPattern(0, i);
    }
  }
  
  /* DEBUG */
  // for (int i = 0; i < N; i++){
  //   for (int j = 1; j <= ALL_PATTERN; j++){
  //     std::cout << log[i][j] << ", ";
  //   }
  //   std::cout << static_cast<int>(must_man[i]) << std::endl;
  // }
  
  std::cout << result % 10007 << std::endl;

  return 0;
}