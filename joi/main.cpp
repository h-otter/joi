#include <iostream>
#include <algorithm>

struct HouseStruct{
  HouseStruct():
    result(-1),
    stop(false),
    stop_time(-1)
  {}

  long long int place;
  long long int result;
  bool way;  // true: west, false: east
  bool stop;
  int stop_time;
};

int main(){
  int N, T, Q;
  std::cin >> N >> T >> Q;

  HouseStruct house[N];
  for (int i = 0; i < N; i++){
    int temp;
    std::cin >> house[i].place >> temp;
    house[i].way = static_cast<bool>(temp - 1);
  }

  int who_man[Q];
  for (int i = 0; i < Q; i++){
    std::cin >> who_man[Q];
  }

  int temp_house = 0;
  for (int i = 0; i < N; i++){
    if (house[i].way){
      temp_house = i;
    }
    else if (!house[i].way && temp_house){
      if (house[i].place + house[temp_house].place <= 2 * T){
        house[i].result = house[temp_house].result = (house[i].place + house[temp_house].place) / 2;
        house[i].stop = house[temp_house].stop = true;
        house[i].stop_time = house[temp_houce].stop_time =  T - abs(house[i].place - house[i].result);
      }

      temp_house = 0;
    }
  }

  for (int i = 0; i < N; i++){
    if (house[i].stop){
      for (int j = i + 1; abs(house[j].place - house[i].result) + house[i].stop_time <= T; j++){
        if (house[j].way){
          house[j].stop = true;
          house[j].stop_time = house[j].place - house[i].result + house[i].stop_time;
          house[j].result = house[i].result;
        }
      }

      for (int j = i - 1; abs(house[j].place - house[i].result) + house[i].stop_time <= T; j--){
        if (!house[j].way){
          house[j].stop = true;
          house[j].stop_time = house[j].place - house[i].result + house[i].stop_time;
          house[j].result = house[i].result;
        }
      }
    }
  }

  for (int i = 0; i < N; i++){
    if (!house[i].stop){
      if (house[i].way){
        house[i].result = house[i].place - T;
      }
      else{
        house[i].result = house[i].place + T;
      }
    }
  }

  for (int i = 0; i < Q; i++){
    std::cout << house[who_man[i]].result << std::endl;
  }

  return 0;
}

