#include <iostream>

#define FLAG_J 1
#define FLAG_O 2
#define FLAG_I 4
#define ALL_PATTERN 8

int main(){
  int N;
  std::cin >> N;
  
  char must_man[N];
  int map[N][ALL_PATTERN];
  
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
    for (int j = 1; j <= 7; j++){
      map[i][j] = 0;
	}
  }
   
  for (int i = 1; i <= 7; i++){
    if ((i & must_man[0]) != 0 && (i & FLAG_J) != 0){
      map[0][i] = 1;
	}
  }
  
  for (int i = 1; i < N; i++){
    for (int now = 1; now <= 7; now++){
	  for (int before = 1; before <= 7; before++){
        if ((now & before) != 0 && (now & must_man[i]) != 0){
          map[i][now] += map[i-1][before];
		  map[i][now] %= 10007;
		}
	  }
	}	  
  }
  
  /* DEBUG */
  for (int i = 0; i < N; i++){
    for (int j = 1; j <= 7; j++){
      std::cout << map[i][j] << ", ";
	}
	std::cout << static_cast<int>(must_man[i]) << std::endl;
  }
  
  
  int result = 0;
  for (int i = 1; i <= 7; i++){
	result += map[N-1][i];
	result %= 10007;
  }
  
  std::cout << result << std::endl;
  
  return 0;
}