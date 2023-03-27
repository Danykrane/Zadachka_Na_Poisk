#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int find(vector<int> vec, int znachenie) {
  bool f = false;  //укажет нам на то, нашли ли мы значение

  int seredina = (0 + vec.size()) / 2;
  int lef = 0;             //начало
  int right = vec.size();  //конец

  while ((lef <= right) && (f != true)) {
    seredina = (lef + right) / 2;

    if (vec[seredina] == znachenie) f = true;  //серединное значение
    if (vec[seredina] > znachenie)
      right = seredina - 1;  // если больше, то уменьшаем правую границу
    else
      lef = seredina + 1;  // если меньше, то увеличиваем левую границу
  }



  if (f == true) {
    return seredina;
  } else
    return -1;
}


int main() {
  int s;
  cin >> s;
  vector <int> n (s);
  for (auto& it :n){
    cin >> it;
  }
  cout << "Отсортированный массив равен\n=> "<<endl;
  
  sort(n.begin(), n.end());
 for (auto& it :n){
    cout << it<<" ";
  }
  int zn = 0;
  cout <<"\nВведите значение для поиска"<<endl;
  cin >> zn;
  if (find(n,zn)==-1) cout <<"Такого эл-та нет"<<endl;
  else cout <<"Индекс элемента  "<<zn<<" равняется "<< find(n,zn);

}
